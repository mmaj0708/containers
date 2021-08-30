
#include <vector>
#include <map>
#include <iostream>
#include "map.hpp"
# include "Rand_iterator.hpp"

int main()
{
	std::cout << "***MAP TEST***\n" << std::endl;
	std::map<char, int>				mp;

	mp.insert( std::pair<char, int>('c', 3) );
	mp.insert( std::pair<char, int>('d', 4) );
	mp.insert( std::pair<char, int>('a', 1) );
	mp.insert( std::pair<char, int>('b', 2) );
	std::map<char, int>::iterator	mp_it;

	std::cout << "STD\n" << mp.begin()->first << std::endl;
	// for (mp_it = mp.begin() ; mp_it != mp.end() ; mp_it++)
	// {
	// 	std::cout << "KEY   " << mp_it->first << std::endl;
	// 	std::cout << "VALUE " << mp_it->second << std::endl;
	// }
	// std::cout << "KEY   " << (mp_it = mp.begin())->first << std::endl;
	// std::cout << "VALUE   " << (*mp_it).second << std::endl;
	
	std::cout << "\nFT" << std::endl;
	ft::map<char, int>		ft_mp;

	ft_mp.insert( ft::pair<char, int>('c', 3) );
	ft_mp.insert( ft::pair<char, int>('d', 4) );
	ft_mp.insert( ft::pair<char, int>('a', 1) );
	ft_mp.insert( ft::pair<char, int>('b', 2) );

	ft_mp.showTree();

	return (0);
}
