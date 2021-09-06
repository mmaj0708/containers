
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
	ft::map<char, int>		ft_mp2;

	ft_mp.insert( ft::pair<char, int>('e', 5) );
	ft_mp.insert( ft_mp.begin(), ft::pair<char, int>('b', 2) );
	ft_mp.insert( ft::pair<char, int>('h', 8) );
	ft_mp.insert( ft::pair<char, int>('f', 6) );
	ft_mp.insert( ft::pair<char, int>('j', 10) );
	ft_mp.insert( ft::pair<char, int>('a', 1) );
	ft_mp.insert( ft::pair<char, int>('c', 3) );
	ft_mp.insert( ft::pair<char, int>('d', 4) );
	// ft_mp.insert( ft::pair<char, int>('x', 5) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );
	// ft_mp.insert( ft::pair<char, int>('b', 2) );

	ft_mp2.insert(ft_mp.begin(), ft_mp.end());

	ft::map<char, int>::iterator		ft_it = ft_mp.begin();

	// std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;
	// ft_it++;
	// std::cout << ft_it->first << ft_it->second << std::endl;
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

	// ft_mp.clear();
	ft_mp.erase(ft_mp.begin(), ft_mp.end());
	// ft_mp.erase('a');
	// ft_mp.erase('b');
	// ft_mp.erase('c');
	// ft_mp.erase('d');
	// ft_mp.erase('e');
	// ft_mp.erase('f');
	// ft_mp.erase('h');
	// ft_mp.erase('j');
	// ft_mp.showTree();
	// std::cout << std::endl;
	// ft_mp.erase('b');
	// ft_mp.showTree();
	// std::cout << std::endl;
	// ft_mp.erase('h');
	// ft_mp.showTree();
	// std::cout << std::endl;
	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// std::cout << "IT AFTER ERASE " << ft_it->first << std::endl;

	// std::cout << "IT AFTER ERASE " << ft_it->first << std::endl;
	// std::cout << "END : "<< ft_mp.end()->first << std::endl;
	ft_mp.showTree();

	std::cout << "\ninsert by range\n" << std::endl;


	ft_mp2.showTree();

	std::cout << "\nSWAP\n" << std::endl;

	ft::map<char, int>	swapMap;

	swapMap.insert(ft::pair<char, int>('x', 1));
	swapMap.insert(ft::pair<char, int>('y', 2));
	swapMap.insert(ft::pair<char, int>('z', 3));

	swapMap.swap(ft_mp2);
	std::cout << "swaped tab" << std::endl;
	swapMap.showTree();
	std::cout << "\nft_mp2" << std::endl;
	ft_mp2.showTree();
	// ft_mp.clear();



	// ft_mp.erase(ft_mp.end());

	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());

	// std::cout << "END : "<< ft_mp.end()->first << std::endl;

	// ft_mp.erase(ft_mp.end());

	std::cout << "EMPTY ? "<< ft_mp.empty() << std::endl;

	std::cout << "\nREVERSE IT\n";

	std::map<char,int> stdmap;
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	stdmap['x']=1001;
	stdmap['y']=2002;
	stdmap['z']=3003;

	// std::cout << "\nmymap contains:\n";

	// ft::pair<char,int> highest = *mymap.rbegin();          // last element

	// ft::map<char,int>::iterator it = mymap.begin();
	// do {
	// 	std::cout << it->first << " => " << it->second << '\n';
	// } while ( mymap.value_comp()(*it++, highest) );

	std::map<char,int>::reverse_iterator stdit = stdmap.rbegin();
	std::cout << "stdit->first : " << stdit->first << std::endl;
	++stdit;
	std::cout << "stdit->first : " << stdit->first << std::endl;
	++stdit;
	std::cout << "stdit->first : " << stdit->first << std::endl;

	std::cout << "\nmymap contains:\n";

	// ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::reverse_iterator it = mymap.rbegin();
	std::cout << "it->first : " << it->first << std::endl;
	++it;
	std::cout << "it->first : " << it->first << std::endl;
	++it;
	std::cout << "it->first : " << it->first << std::endl;

	return (0);
}
