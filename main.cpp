
#include <vector>
#include <iostream>
#include "vector.hpp"
# include "Rand_iterator.hpp"


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

	// std::cout << "**RANGE CONSTRUCTOR**" << std::endl;
	// std::cout << "*FT::VECTOR*" << std::endl;
	// std::vector<int>	a4(5, 0);
	// std::vector<int>	a5(a4.begin(), a4.end());
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << a5[i] << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a4(5, 0);
	// ft::vector<int>	ft_a5(ft_a4.begin(), a4.end());
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << ft_a5[i] << std::endl;

	std::vector<int>	a6(0,5);
	std::cout << "cap bef = " << a6.capacity() << std::endl;
	a6.push_back(56);
	std::cout << "cap bef = " << a6.capacity() << std::endl;
	a6.push_back(56);
	std::cout << "cap bef = " << a6.capacity() << std::endl;
	a6.push_back(56);
	std::cout << "cap bef = " << a6.capacity() << std::endl;
	a6.push_back(56);
	std::cout << "cap bef = " << a6.capacity() << std::endl;
	a6.push_back(56);
	std::cout << "cap bef = " << a6.capacity() << std::endl;

	// std::cout << "ITERATOR TEST\n" << std::endl;
	// std::cout << "*OPERATOR++*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int> tab2(5, 10);
	// for(int i = 0 ; i < 5 ; i++)
	// 	tab2[i] = i;

	// std::vector<int>::iterator	it(tab2.begin());
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << *(it++) << std::endl;


	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int> ft_tab2(5, 10);
	// for(int i = 0 ; i < 5 ; i++)
	// 	ft_tab2[i] = i;

	// ft::vector<int>::iterator	ft_it(ft_tab2.begin());
	// for(int j = 0 ; j < 5 ; j++)
	// 	std::cout << *(ft_it++) << std::endl;

	
	// std::cout << "\n*OPERATOR--*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int> tab3(5, 10);
	// for(int i = 4 ; i >= 0 ; i--)
	// 	tab3[i] = i;

	// std::vector<int>::iterator	it2(tab3.end());
	// for(int i = 4 ; i >= 0 ; i--)
	// 	std::cout << *(--it2) << std::endl;


	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int> ft_tab3(5, 10);
	// for(int i = 4 ; i >= 0 ; i--)
	// 	ft_tab3[i] = i;

	// ft::vector<int>::iterator	ft_it2(ft_tab3.end());
	// for(int i = 4 ; i >= 0 ; i--)
	// 	std::cout << *(--ft_it2) << std::endl;
}
