/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:42:21 by mmakarov          #+#    #+#             */
/*   Updated: 2023/01/11 18:11:49 by mmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**input_as_str(char **argv) //return of all arguments. even prog name
{
	char	**a;
	char	*b;

	b = ft_strjoin("./push_swap ", argv[1]);
	if (b == NULL)
		return (NULL);
	a = ft_split(b, ' '); //if input is like "6 4 1 23 -4"
	free(b);
	if (a == NULL)
		return (NULL);
	return (a);
}

int     n_of_n(char **a) //n of lines (i.e. numbers)
{
        int     i;
        int     j;

        j = 0;
        while (a[j] != NULL)
        {
                i = 0;
                while (a[i])
                        i++;
                j++;
        }
        return (j); //return how many numbers in **a (or **argv). Kind of argc
}

static int	err_checker(int ac, char **av, int old_ac) //check all errors
{
	int	j;
	int	i;

	j = 1; //from argv[1]
	if (av[j] == NULL)
		return (0);
	while (j < ac)
	{
		if (!ft_isdigit(av[j])) //autres char non autorises non plus
			return (0);
		if (ft_atoi(av[j]) > 2147483647 || ft_atoi(av[j]) < -2147483648)
			return (0);
		i = j + 1;
		while (i < ac)
		{
			if (ft_atoi(av[j]) == ft_atoi(av[i]))
				return (0);
			i++;
		}
		j++;
	}
	if (old_ac == 1)
		free_char(av, ac);
	return (1);
}

int	err_input_checker(int argc, char **argv) //function that put all together
{
	char	**a;
	int		i;

	i = 0;
	if (argv == NULL)
		return (0);
	if (argc == 2)
	{
		a = input_as_str(argv);
		i = n_of_n(a);
		return (err_checker(i, a, 1)); //free only newly created argv
	}
	return (err_checker(argc, argv, 0));
}
