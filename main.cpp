
#include <vector>
#include <iostream>
#include "vector.hpp"


int main()
{
	std::cout << "***VECTOR TEST***\n" << std::endl;
	// std::cout << "**DEFAULT CONSTRUCTOR TEST**\n" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int> tab;
	// std::cout << "size : " << tab.size() << std::endl;
	// std::cout << "max_size : " << tab.max_size() << std::endl;
	// std::cout << "capacity : " << tab.capacity() << std::endl;
	// std::cout << "empty : " << tab.empty() << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_tab;
	// std::cout << "size : " << ft_tab.size() << std::endl;
	// std::cout << "max_size : " << ft_tab.max_size() << std::endl;
	// std::cout << "capacity : " << ft_tab.capacity() << std::endl;
	// std::cout << "empty : " << ft_tab.empty() << std::endl;

	// std::cout << "\n**FILL CONSTRUCTOR TEST**\n" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int> tab2(5, 10);
	// std::cout << "size : " << tab2.size() << std::endl;
	// std::cout << "max_size : " << tab2.max_size() << std::endl;
	// std::cout << "capacity : " << tab2.capacity() << std::endl;
	// std::cout << "empty : " << tab2.empty() << std::endl;
	// std::cout << tab2[0] << std::endl;
	// std::cout << tab2[1] << std::endl;
	// std::cout << tab2[2] << std::endl;
	// std::cout << tab2[3] << std::endl;
	// std::cout << tab2[4] << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_tab2(5, 10);
	// std::cout << "size : " << ft_tab2.size() << std::endl;
	// std::cout << "max_size : " << ft_tab2.max_size() << std::endl;
	// std::cout << "capacity : " << ft_tab2.capacity() << std::endl;
	// std::cout << "empty : " << ft_tab2.empty() << std::endl;
	// std::cout << ft_tab2[0] << std::endl;
	// std::cout << ft_tab2[1] << std::endl;
	// std::cout << ft_tab2[2] << std::endl;
	// std::cout << ft_tab2[3] << std::endl;
	// std::cout << ft_tab2[4] << std::endl;

	std::vector<int> tab2(5, 10);
	std::vector<int>::iterator	it = tab2.begin();
	it[0] = 5;
	std::cout << *it << std::endl;
	
}
