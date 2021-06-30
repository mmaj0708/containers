
#include <vector>
#include <iostream>
#include "vector.hpp"

int main()
{
	// int i = 0;
	std::vector<int> tab(5, 10);
	std::vector<int>::iterator it = tab.begin();
	std::cout << tab.size() << std::endl;

	std::cout << "bonjour" << std::endl;
	while (it != tab.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	
	std::cout << "\nMY VECTOR" << std::endl;
	ft::vector<int>	ft_tab(5, 10);

	std::cout << ft_tab.size() << std::endl;
	std::cout << ft_tab[0] << std::endl;
	std::cout << ft_tab[1] << std::endl;
	std::cout << ft_tab[2] << std::endl;
	std::cout << ft_tab[3] << std::endl;
	std::cout << ft_tab[4] << std::endl;
	std::cout << ft_tab[5] << std::endl;
}
