#include "common.hpp"

#define TESTED_TYPE foo<int>

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::list<TESTED_TYPE> lst(size);
	TESTED_NAMESPACE::list<TESTED_TYPE>::iterator it(lst.begin());
	TESTED_NAMESPACE::list<TESTED_TYPE>::const_iterator ite(lst.end());

	for (int i = 1; it != ite; ++i)
		*it++ = i;
	printSize(lst, 1);

	it = lst.begin();
	ite = lst.begin();

	std::cout << *(++ite) << std::endl;
	std::cout << *(ite++) << std::endl;
	std::cout << *ite++ << std::endl;
	std::cout << *++ite << std::endl;

	it->m();
	ite->m();

	std::cout << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	std::cout << *(--ite) << std::endl;
	std::cout << *(ite--) << std::endl;
	std::cout << *--ite << std::endl;
	std::cout << *ite-- << std::endl;

	(*it).m();
	(*ite).m();

	std::cout << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	return (0);
}
