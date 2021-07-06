
// pk besoin de rajouter une classe iterator dans vector_decl.hpp ??
// pk pas tous les operators dans rand_it ??
// comment tu fais ++a, a++, *a++

// iterator = pointer enveloppé dans une classe

#ifndef RAND_ITERATOR_HPP
# define RAND_ITERATOR_HPP

namespace ft
{

	template<typename T>
	class Rand_iterator
	{
	private:

	public:

	    typedef T							value_type;
	    typedef Rand_iterator               randIt;

		randIt() {}
		randIt(value_type a); // Marc a mis *a
		randIt &operator=(randIt const &src); // Marc a mis *a
		~randIt();

		bool	operator==(randIt const &rhs) const;
		bool	operator!=(randIt const &rhs) const;
		bool	operator*(randIt const &rhs) const;
		bool	operator->(randIt const &rhs) const;
		bool	operator++(randIt const &rhs) const;


	};

}

#endif