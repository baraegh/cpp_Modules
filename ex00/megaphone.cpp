#include <iostream>

int	main(int ac, char **av)
{
	int	len;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		len = strlen(av[i]);
		for (int j = 0; j < len; j++)
		{
			if (isalpha(av[i][j]))
				std::cout << (char)toupper(av[i][j]);
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}