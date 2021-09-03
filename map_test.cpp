
#include <vector>
#include <map>
#include <iostream>
#include "map.hpp"
# include "Rand_iterator.hpp"

int main()
{
	std::cout << "***MAP TEST***\n" << std::endl;
	std::map<char, int>				mp;

	// std::cout << "END : "<< mp.end()->first << std::endl; // quand rien, cas indeterminé
	// std::cout << mp.find('x')->first << std::endl;
	mp.insert( std::pair<char, int>('x', 2) );
	std::cout << (mp['h'] = 7) << std::endl;
	mp.insert( std::pair<char, int>('c', 3) );
	mp.insert( std::pair<char, int>('d', 4) );
	mp.insert( std::pair<char, int>('a', 1) );
	mp.insert( std::pair<char, int>('b', 2) );
	std::map<char, int>::iterator	mp_it = mp.begin();

	std::cout << "STD\n" << mp_it->first << std::endl;
	std::cout << (++mp_it)->first << std::endl;
	std::cout << (++mp_it)->first << std::endl;
	std::cout << (++mp_it)->first << std::endl;
	std::cout << (++mp_it)->first << std::endl;
	// for (mp_it = mp.begin() ; mp_it != mp.end() ; mp_it++)
	// {
	// 	std::cout << "KEY   " << mp_it->first << std::endl;
	// 	std::cout << "VALUE " << mp_it->second << std::endl;
	// }
	// std::cout << "KEY   " << (mp_it = mp.begin())->first << std::endl;
	// std::cout << "VALUE   " << (*mp_it).second << std::endl;
	
	std::cout << "\nFT" << std::endl;
	ft::map<char, int>		ft_mp;

	ft_mp.insert( ft::pair<char, int>('e', 5) );
	ft_mp.insert( ft::pair<char, int>('b', 2) );
	ft_mp.insert( ft::pair<char, int>('h', 8) );
	ft_mp.insert( ft::pair<char, int>('f', 6) );
	ft_mp.insert( ft::pair<char, int>('j', 10) );
	std::cout << ft_mp.insert( ft::pair<char, int>('a', 1) ).first->second << std::endl;
	ft_mp.insert( ft::pair<char, int>('c', 3) );
	ft_mp.insert( ft::pair<char, int>('d', 4) );
	// ft_mp.insert( ft::pair<char, int>('x', 5) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );

	ft::map<char, int>::iterator		ft_it = ft_mp.begin();

	std::cout << ft_it->first << ft_it->second << std::endl;
	ft_it++;
	std::cout << ft_it->first << ft_it->second << std::endl;
	ft_it++;
	std::cout << ft_it->first << ft_it->second << std::endl;
	ft_it++;
	std::cout << ft_it->first << ft_it->second << std::endl;
	ft_it++;
	std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;


	// --ft_it;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// --ft_it;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// --ft_it;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// --ft_it;
	// std::cout << ft_it->first << ft_it->second << std::endl;


	// std::cout << "\nFIND" << std::endl;
	// std::cout << ft_mp.find('c')->first << ft_mp.find('c')->second << std::endl;
	// std::cout << ft_mp.find('h')->first << ft_mp.find('h')->second << std::endl;
	// std::cout << ft_mp.count('c') << std::endl;
	// std::cout << ft_mp.count('h') << std::endl;

	// std::cout << "\n[]" << std::endl;
	// std::cout << ft_mp['a'] << std::endl;
	// std::cout << ft_mp['b'] << std::endl;
	// std::cout << ft_mp['c'] << std::endl;
	// std::cout << ft_mp['d'] << std::endl;
	// std::cout << (ft_mp['h'] = 7) << std::endl;

	// // ft_mp.showTree();

	// // ft_mp.clear();
	ft_mp.erase(ft_it);
	std::cout << "END : "<< ft_mp.end()->first << std::endl;

	std::cout << "IT AFTER ERASE " << ft_it->first << std::endl;

	ft_mp.erase(ft_it);
	std::cout << "IT AFTER ERASE " << ft_it->first << std::endl;
	std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());

	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());

	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());

	// std::cout << "EMPTY ? "<< ft_mp.empty() << std::endl;
	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());
	// std::cout << ft_mp.size() << std::endl;

	ft_mp.showTree();

	return (0);
}
