/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:45:51 by cmakario          #+#    #+#             */
/*   Updated: 2024/12/12 21:45:52 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int	main(int argc, char **argv)
{
	int	i,j=0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		j = 0;
		while (argv[i][j])
		{
			char c = argv[i][j];
			if (islower(argv[i][j]))
				c = toupper(c);
			std::cout << c;
			j++;
		}
	}
	std::cout << std::endl;
	return 0;
}

