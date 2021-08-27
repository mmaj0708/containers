
#include <vector>
#include <map>
#include <iostream>
#include "map.hpp"
# include "Rand_iterator.hpp"

int main()
{
	std::cout << "***MAP TEST***\n" << std::endl;
	std::map<std::string, int>				mp;

	mp.insert( std::pair<std::string, int>("a", 100) );
	mp.insert( std::pair<std::string, int>("bbb", 101) );
	mp.insert( std::pair<std::string, int>("ccc", 102) );
	mp.insert( std::pair<std::string, int>("ddd", 103) );
	mp.insert( std::pair<std::string, int>("eee", 104) );
	std::map<std::string, int>::iterator	mp_it;
	// for (mp_it = mp.begin() ; mp_it != mp.end() ; mp_it++)
	// {
	// 	std::cout << "KEY   " << mp_it->first << std::endl;
	// 	std::cout << "VALUE " << mp_it->second << std::endl;
	// }
	// std::cout << "KEY   " << (mp_it = mp.begin())->first << std::endl;
	// std::cout << "VALUE   " << (*mp_it).second << std::endl;
	
	ft::map<char, int>		ft_mp;

	ft_mp.insert( ft::pair<char, int>('a', 1) );


	return (0);
}
