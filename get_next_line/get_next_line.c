/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:34:35 by mmakarov          #+#    #+#             */
/*   Updated: 2022/11/29 10:57:59 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// returns the rest of lines (after the first read line)

static void	the_rest(char *str_save)
{
	size_t	i;
	size_t	ind;

	i = 0;
	ind = 0;
	while (str_save[i] && str_save[i] != '\n')
		i++;
	i++;
	while (str_save[i])
		str_save[ind++] = str_save[i++]; // decalage du buffer
	str_save[ind] = '\0';
}

/* old the_rest

static char	*the_rest(char *str_save)
{
	size_t	i;
	size_t	ind;
	char	*rest;

	if (str_save == NULL)
		return (NULL);
	i = 0;
	while (str_save[i] && str_save[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(str_save) - i - 1)); //size of str_save - len of the fisrt line and \n
	if (rest == NULL)
		return (NULL);
	ind = 0;
	i++; //for \n, beacause it was not included before
	while (str_save[i])
		rest[ind++] = str_save[i++];
	rest[ind] = '\0';           // il faut ajouter \n ????
	return (rest);
}
*/

// read and return the line before \n, \n included
static char	*div_lines(char *all_strs)
{
	size_t	i;
	char	*line;

	if (all_strs == NULL)
		return (NULL);
	i = 0;
	while (all_strs[i] && all_strs[i] != '\n') //count i till \n
		i++;
	line = malloc(sizeof(char) * (i + 2)); //malloc for the line str_save[i]
	if (line == NULL)
		return (NULL);
	i = 0;
	while (all_strs[i] && all_strs[i] != '\n')
	{
		line[i] = all_strs[i]; //put str_save[i] into line
		i++;
	}
	if (all_strs[i] == '\n') // if EOF, return a line without \n
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

int	read_save_additional(int read_bytes, char **temp, char *str_save)
{
	char	*tmp_free; //save temp in memory

	if (read_bytes == -1) // -1 is retured if there is an error
	{
		free(*temp);
		return (0);
	}
	str_save[read_bytes] = '\0'; //I've read the line from fd and put in temp
								 //here I add a '\0' 
								 //temp[read_bytes] not read_bytes - 1
								 //because read_bytes initialized from 1
	tmp_free = ft_strjoin(*temp, str_save); //double pointeur
	free(*temp);
	*temp = tmp_free;
	if (*temp == NULL) // check for malloc in ft_strjoin 
		return (0);
	return (1); //astuce: put an int function, it returns 1 or 0 (= NULL)
}

// read the file fd and save all the lines in str_save
static char	*read_save(int fd, char *str_save)
{
	char	*temp;
	int		read_bytes;
	int		i;

	read_bytes = 1;  // 1 char 1 byte, so start counting from 1 for '\0'
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	//temp[0] = '\0';
	temp = ft_strcpy(temp, str_save);
	while (read_bytes != 0 && ft_strchr(str_save, '\n')) // read_bytes = 0 means EOF
	{
		i = 0;
		while(i <= BUFFER_SIZE)
			str_save[i++] = '\0'; //fill in with 0, like bzero
		read_bytes = read(fd, str_save, BUFFER_SIZE); // read function returns n of read bytes
		
		/*  was cut, look the function above !

		if (read_bytes == -1) // -1 is retured if there is an error
		{
			free(temp);
			return (NULL);
		}
		str_save[read_bytes] = '\0'; //I've read the line from fd and put in temp
								 //here I add a '\0' 
								 //temp[read_bytes] not read_bytes - 1
								 //because read_bytes initialized from 1
		tmp_free = temp; //garger temp en memoire
		temp = ft_strjoin(temp, str_save);
		free(tmp_free);
		if (temp == NULL) // for malloc in ft_strjoin 
			return (NULL);
		*/

		if (!read_save_additional(read_bytes, &temp, str_save)) // since temp is malloced here
																//  and manipulated (ex, free) in the addit.
																//  function, we need the address
		   return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	str_save[BUFFER_SIZE + 1];
	char	*line;
	char	*all_strs;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_strs = read_save(fd, str_save); //read all the file, all lines. save as all_strs
	if (all_strs == NULL)
		return (NULL);
//	printf("%s", str_save);
	line = div_lines(all_strs); //get only 1 line tiil the first \n
	free(all_strs);
	if (line == NULL)
		return (NULL);
//	printf("%s\n", line);
	the_rest(str_save);
//	printf("%s\n", str_save);
	if (ft_strlen(line)) //if str is void, return a pointer to null
		return (line);
	free(line);
	return (NULL);
}
