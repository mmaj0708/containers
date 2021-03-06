
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include "stack.hpp"
#include "vector.hpp"
# include "Rand_iterator.hpp"

int main()
{
	std::cout << "***STACK TEST***\n" << std::endl;
	ft::stack<int> stck;
	std::map<char, std::string> mp;
	// std::cout << "***VECTOR TEST***\n" << std::endl;
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
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a4(5, 0);
	// std::vector<int>	a5(a4.begin(), a4.end());
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << a5[i] << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a4(5,0);
	// for(ft::vector<int>::iterator it = ft_a4.begin() ; it != ft_a4.end() ; it++)
	// { std::cout << *it << std::endl; }
	// ft::vector<int>	ft_a5(ft_a4.begin(), ft_a4.end());
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << ft_a5[i] << std::endl;

	// std::cout << "**COPY CONSTRUCTOR**" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a6(5, 0);
	// std::vector<int>	a7(a6);
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << a7[i] << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a6(5,0);
	// ft::vector<int>	ft_a7(ft_a6);
	// for(int i = 0 ; i < 5 ; i++)
	// 	std::cout << ft_a6[i] << std::endl;



	// std::vector<int>	a6(0,5);
	// std::vector<int>::iterator it;
	// std::cout << "cap = " << a6.capacity() << std::endl;
	// std::cout << "size = " << a6.size() << std::endl;
	// for (it = a6.begin() ; it != a6.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }

	// a6.push_back(56);
	
	// a6.resize(10, 0);
	// std::cout << "\ncap = " << a6.capacity() << std::endl;
	// std::cout << "size = " << a6.size() << std::endl;
	// for (it = a6.begin() ; it != a6.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }	
	// a6.resize(5, 0);
	// std::cout << "\ncap = " << a6.capacity() << std::endl;
	// std::cout << "size = " << a6.size() << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	fta6(0,10);
	// ft::vector<int>::iterator ftit;
	// std::cout << "cap = " << fta6.capacity() << std::endl;
	// std::cout << "size = " << fta6.size() << std::endl;
	// for (ftit = fta6.begin() ; ftit != fta6.end(); ftit++) {
	// 	std::cout << *ftit << std::endl;
	// }

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

	// std::cout << "*OPERATOR=*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a7(5, 0);
	// std::vector<int>	a8(10, 21);
	// std::cout << "cap = " << a8.capacity() << std::endl;
	// std::cout << "size = " << a8.size() << std::endl;
	// a7 = a8;
	// for(int i = 0 ; i < a8.size() ; i++)
	// 	std::cout << a8[i] << " ";
	// 	std::cout << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a7(5, 0);
	// ft::vector<int> ft_a8(10, 21);
	// std::cout << "cap = " << ft_a8.capacity() << std::endl;
	// std::cout << "size = " << ft_a8.size() << std::endl;
	// ft_a7 = ft_a8;
	// for(int i = 0 ; i < ft_a8.size() ; i++)
	// 	std::cout << ft_a8[i] << " ";
	// 	std::cout << std::endl;

	// std::cout << "\n*STD::Vector*" << std::endl;
	// std::vector<int>			tab_for_it(10, 3);
	// std::vector<int>			tab_for_it2(10, 3);
	// std::vector<int>::iterator	it_test = tab_for_it.begin();
	// std::vector<int>::iterator	it_test2 = tab_for_it2.begin();
	// std::cout << "*==*"  << " ";
	// std::cout << (it_test == it_test2) << " ";
	// std::cout << (it_test == tab_for_it.begin()) << " ";
	// std::cout << "*!=*"  << " ";
	// std::cout << (it_test != it_test2)  << " ";
	// std::cout << (it_test != tab_for_it.begin()) << " ";
	// std::cout << "*>*"  << " ";
	// std::cout << (it_test > it_test + 1) << " ";
	// std::cout << (it_test > tab_for_it.begin()) << " ";
	// std::cout << "*<*"  << " ";
	// std::cout << (it_test < it_test - 1)  << " ";
	// std::cout << (it_test < tab_for_it.begin())  << " ";
	// std::cout << "*>=*"  << " ";
	// std::cout << (it_test >= it_test2) << " ";
	// std::cout << (it_test >= tab_for_it.begin()) << " ";
	// std::cout << "*<=*"  << " ";
	// std::cout << (it_test <= it_test2)  << " ";
	// std::cout << (it_test <= tab_for_it.begin()) << " ";

	// std::cout << "\n*FT::Vector*" << std::endl;
	// ft::vector<int>				ft_tab_for_it(10, 3);
	// ft::vector<int>				ft_tab_for_it2(10, 3);
	// ft::vector<int>::iterator	ft_it_test = ft_tab_for_it.begin();
	// ft::vector<int>::iterator	ft_it_test2 = ft_tab_for_it2.begin();
	// std::cout << "*==*"  << " ";
	// std::cout << (ft_it_test == ft_it_test2)  << " ";
	// std::cout << (ft_it_test == ft_tab_for_it.begin())  << " ";
	// std::cout << "*!=*"  << " ";
	// std::cout << (ft_it_test != ft_it_test2)  << " ";
	// std::cout << (ft_it_test != ft_tab_for_it.begin())  << " ";
	// std::cout << "*>*"  << " ";
	// std::cout << (ft_it_test > ft_it_test + 1)  << " ";
	// std::cout << (ft_it_test > ft_tab_for_it.begin())  << " ";
	// std::cout << "*<*"  << " ";
	// std::cout << (ft_it_test < ft_it_test - 1)  << " ";
	// std::cout << (ft_it_test < ft_tab_for_it.begin())  << " ";
	// std::cout << "*>=*"  << " ";
	// std::cout << (ft_it_test >= ft_it_test2)  << " ";
	// std::cout << (ft_it_test >= ft_tab_for_it.begin())  << " ";
	// std::cout << "*<=*"  << " ";
	// std::cout << (ft_it_test <= ft_it_test2)  << " ";
	// std::cout << (ft_it_test <= ft_tab_for_it.begin())  << " ";
	// std::cout << std::endl;
	

	// 	std::cout << "*AT*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a7(5, 0);
	// std::cout << "AT = " << a7.at(2) << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a7(5, 0);
	// std::cout << "AT = " << ft_a7.at(2) << std::endl; // try with n > size

	// std::cout << "*FRONT/BACK*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
  	// std::vector<int> vector;
  	// vector.push_back(78);
  	// vector.push_back(16);
	// std::cout << "cap = " << vector.capacity() << std::endl;
	// std::cout << "size = " << vector.size() << std::endl;
  	// vector.front() -= vector.back();
  	// std::cout << "vector.front() is now " << vector.front() << '\n';
	// vector.pop_back();
	// vector.pop_back();
  	// std::cout << "empty() =  " << vector.empty() << '\n';

	// std::cout << "\n*FT::VECTOR*" << std::endl;
  	// ft::vector<int> myvector;
  	// myvector.push_back(78);
  	// myvector.push_back(16);
	// std::cout << "cap = " << myvector.capacity() << std::endl;
	// std::cout << "size = " << myvector.size() << std::endl;
  	// myvector.front() -= myvector.back();
  	// std::cout << "myvector.front() is now " << myvector.front() << '\n';
  	// myvector.pop_back();
  	// myvector.pop_back();
	// std::cout << "empty() = " << myvector.empty() << '\n';


	// std::cout << "*RESIZE/RESERVE*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a6(5, 0);
	// a6.resize(10);
	// std::cout << "cap = " << a6.capacity() << std::endl;
	// std::cout << "size = " << a6.size() << std::endl;
	// for(int i = 0 ; i < 10 ; i++)
	// 	std::cout << a6[i] << " ";
	// 	std::cout << std::endl;
	// a6.resize(15);
	// std::cout << "cap = " << a6.capacity() << std::endl;
	// std::cout << "size = " << a6.size() << std::endl;
	// for(int i = 0 ; i < 15 ; i++)
	// 	std::cout << a6[i] << " ";
	// 	std::cout << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a6(5, 0);
	// ft_a6.resize(10);
	// std::cout << "cap = " << ft_a6.capacity() << std::endl;
	// std::cout << "size = " << ft_a6.size() << std::endl;
	// for(int i = 0 ; i < 10 ; i++)
	// 	std::cout << ft_a6[i] << " ";
	// 	std::cout << std::endl;
	// ft_a6.resize(15);
	// std::cout << "cap = " << ft_a6.capacity() << std::endl;
	// std::cout << "size = " << ft_a6.size() << std::endl;
	// for(int i = 0 ; i < 15 ; i++)
	// 	std::cout << ft_a6[i] << " ";
	// 	std::cout << std::endl;

	// 	std::cout << "*ASSIGN*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a9(25, 0);
	// std::vector<int>	a10(21, 20);
	// a9.assign(a10.begin(), a10.end());
	// std::cout << "cap = " << a9.capacity() << std::endl;
	// std::cout << "size = " << a9.size() << std::endl;
	// for(int i = 0 ; i < a9.size() ; i++)
	// 	std::cout << a9[i] << " ";
	// 	std::cout << std::endl;
	// a9.assign(1, 10);
	// std::cout << "cap = " << a9.capacity() << std::endl;
	// std::cout << "size = " << a9.size() << std::endl;
	// for(int i = 0 ; i < a9.size() ; i++)
	// 	std::cout << a9[i] << " ";
	// 	std::cout << std::endl;

	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a9(25, 0);
	// ft::vector<int>	ft_a10(21, 20);
	// ft_a9.assign(ft_a10.begin(), ft_a10.end());

	// std::cout << "cap = " << ft_a9.capacity() << std::endl;
	// std::cout << "size = " << ft_a9.size() << std::endl;
	// for(int i = 0 ; i < ft_a9.size() ; i++)
	// 	std::cout << ft_a9[i] << " ";
	// 	std::cout << std::endl;
	// ft_a9.assign(1, 10);
	// std::cout << "cap = " << ft_a9.capacity() << std::endl;
	// std::cout << "size = " << ft_a9.size() << std::endl;
	// for(int i = 0 ; i < ft_a9.size() ; i++)
	// 	std::cout << ft_a9[i] << " ";
	// 	std::cout << std::endl;

	// std::cout << "*INSERT*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a11(3, 0);
	// std::vector<int>::iterator it = a11.begin();
	// std::vector<int>	a12(10, 20);
	// std::cout << "cap = " << a11.capacity() << std::endl;
	// std::cout << "size = " << a11.size() << std::endl;
	// a11.insert(it + 1, 5, 6);
	// it = a11.begin();
	// std::cout << "cap = " << a11.capacity() << std::endl;
	// std::cout << "size = " << a11.size() << std::endl;
	// std::cout << *(a11.insert(it + 5, 999)) << std::endl;
	// it = a11.begin();
	// std::cout << "cap = " << a11.capacity() << std::endl;
	// std::cout << "size = " << a11.size() << std::endl;
	// a11.insert(it + 2, a12.begin(), a12.end());
	// it = a11.begin();
	// std::cout << "cap = " << a11.capacity() << std::endl;
	// std::cout << "size = " << a11.size() << std::endl;
	// for(int i = 0 ; i < a11.size() ; i++)
	// 	std::cout << a11[i] << " ";
	// std::cout << std::endl;


	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a11(3, 0);
	// ft::vector<int>::iterator ft_it = ft_a11.begin();
	// ft::vector<int>	ft_a12(10, 20);
	// std::cout << "cap = " << ft_a11.capacity() << std::endl;
	// std::cout << "size = " << ft_a11.size() << std::endl;
	// ft_a11.insert(ft_it + 1, 5, 6);
	// ft_it = ft_a11.begin();
	// std::cout << "cap = " << ft_a11.capacity() << std::endl;
	// std::cout << "size = " << ft_a11.size() << std::endl;
	// std::cout << *(ft_a11.insert(ft_it + 5, 999)) << std::endl;
	// ft_it = ft_a11.begin();
	// std::cout << "cap = " << ft_a11.capacity() << std::endl;
	// std::cout << "size = " << ft_a11.size() << std::endl;
	// ft_a11.insert(ft_it + 2, ft_a12.begin(), ft_a12.end());
	// ft_it = ft_a11.begin();
	// std::cout << "cap = " << ft_a11.capacity() << std::endl;
	// std::cout << "size = " << ft_a11.size() << std::endl;
	// for(int i = 0 ; i < ft_a11.size() ; i++)
	// 	std::cout << ft_a11[i] << " ";
	// std::cout << std::endl;

	// std::cout << "*ERASE*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a13(10, 11);
	// a13.push_back(34);
	// a13.push_back(13);
	// a13.push_back(67);
	// std::vector<int>::iterator it = a13.begin();
	// std::cout << "cap = " << a13.capacity() << std::endl;
	// std::cout << "size = " << a13.size() << std::endl;
	// a13.erase(it + 3);
	// it = a13.begin();
	// std::cout << "cap = " << a13.capacity() << std::endl;
	// std::cout << "size = " << a13.size() << std::endl;
	// a13.erase(it + 3, it + 7);
	// it = a13.begin();
	// std::cout << "cap = " << a13.capacity() << std::endl;
	// std::cout << "size = " << a13.size() << std::endl;
	// for(int i = 0 ; i < a13.size() ; i++)
	// 	std::cout << a13[i] << " ";
	// std::cout << std::endl;


	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a13(10, 11);
	// ft_a13.push_back(34);
	// ft_a13.push_back(13);
	// ft_a13.push_back(67);
	// ft::vector<int>::iterator ft_it = ft_a13.begin();
	// std::cout << "cap = " << ft_a13.capacity() << std::endl;
	// std::cout << "size = " << ft_a13.size() << std::endl;
	// ft_a13.erase(ft_it + 3);
	// ft_it = ft_a13.begin();
	// std::cout << "cap = " << ft_a13.capacity() << std::endl;
	// std::cout << "size = " << ft_a13.size() << std::endl;
	// ft_a13.erase(ft_it + 3, ft_it + 7);
	// ft_it = ft_a13.begin();
	// std::cout << "cap = " << ft_a13.capacity() << std::endl;
	// std::cout << "size = " << ft_a13.size() << std::endl;
	// for(int i = 0 ; i < ft_a13.size() ; i++)
	// 	std::cout << ft_a13[i] << " ";
	// std::cout << std::endl;

	// std::cout << "*SWAP*" << std::endl;
	// std::cout << "*STD::VECTOR*" << std::endl;
	// std::vector<int>	a14(10, 11);
	// a14.push_back(34);
	// a14.push_back(13);
	// a14.push_back(67);
	// std::vector<int>	a15(10, 11);
	// std::vector<int>::iterator it = a14.begin();
	// std::cout << "cap = " << a14.capacity() << std::endl;
	// std::cout << "size = " << a14.size() << std::endl;
	// a14.swap(a15);
	// std::cout << "cap = " << a14.capacity() << std::endl;
	// std::cout << "size = " << a14.size() << std::endl;
	// for(int i = 0 ; i < a14.size() ; i++)
	// 	std::cout << a14[i] << " ";
	// std::cout << std::endl;
	// for(int i = 0 ; i < a15.size() ; i++)
	// 	std::cout << a15[i] << " ";
	// std::cout << std::endl;
	// a14.clear();
	// std::cout << "cap = " << a14.capacity() << std::endl;
	// std::cout << "size = " << a14.size() << std::endl;


	// std::cout << "\n*FT::VECTOR*" << std::endl;
	// ft::vector<int>	ft_a14(10, 11);
	// ft_a14.push_back(34);
	// ft_a14.push_back(13);
	// ft_a14.push_back(67);
	// ft::vector<int>	ft_a15(10, 11);
	// ft::vector<int>::iterator ft_it = ft_a14.begin();
	// std::cout << "cap = " << ft_a14.capacity() << std::endl;
	// std::cout << "size = " << ft_a14.size() << std::endl;
	// ft_a14.swap(ft_a15);
	// std::cout << "cap = " << ft_a14.capacity() << std::endl;
	// std::cout << "size = " << ft_a14.size() << std::endl;
	// for(int i = 0 ; i < ft_a14.size() ; i++)
	// 	std::cout << ft_a14[i] << " ";
	// std::cout << std::endl;
	// for(int i = 0 ; i < ft_a15.size() ; i++)
	// 	std::cout << ft_a15[i] << " ";
	// std::cout << std::endl;
	// ft_a14.clear();
	// std::cout << "cap = " << ft_a14.capacity() << std::endl;
	// std::cout << "size = " << ft_a14.size() << std::endl;


	return (0);
}
