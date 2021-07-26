/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand_const_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:50 by mmaj              #+#    #+#             */
/*   Updated: 2021/07/26 18:18:28 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_CONST_ITERATOR_HPP
# define RAND_CONST_ITERATOR_HPP

namespace ft
{

	template<typename T>
	class const_randIt
	{

	public:

	    typedef T							value_type;
		typedef	value_type&					reference;
		typedef	value_type*					pointer;
		typedef ptrdiff_t					difference_type;

		const_randIt() : _ptr(NULL) { return; }
		const_randIt(value_type	*ptr) { _ptr = ptr; }

		const_randIt &operator=(const_randIt const &src) { _ptr = src._ptr; return *this; } // Marc a mis *a
		virtual ~const_randIt() {}

		bool	operator==(const_randIt const &rhs) const { return(_ptr == rhs._ptr ? 1 : 0); }
		bool	operator!=(const_randIt const &rhs) const { return(_ptr != rhs._ptr ? 1 : 0); }
		bool	operator>(const_randIt const &rhs) const { return(_ptr > rhs._ptr ? 1 : 0); }
		bool	operator<(const_randIt const &rhs) const { return(_ptr < rhs._ptr ? 1 : 0); }
		bool	operator<=(const_randIt const &rhs) const  { return(_ptr <= rhs._ptr ? 1 : 0); }
		bool	operator>=(const_randIt const &rhs) const { return(_ptr >= rhs._ptr ? 1 : 0); }
		
		reference	operator*(void) const { return(*_ptr); }
		const_randIt		&operator++(void) { _ptr++; return(*this); } // ++ avant
		const_randIt		operator++(int) { const_randIt tmp(*this); ++this->_ptr; return(tmp); } // ++ apres;
		const_randIt		&operator--(void) { _ptr--; return(*this); } // -- avant
		const_randIt		operator--(int) { const_randIt tmp(*this); --this->_ptr; return(tmp); } // -- apres;
		// const_randIt		operator+(difference_type n) const;
		// const_randIt		operator-(difference_type n) const;
		// const_randIt	operator-(const_randIt const &rhs) const;
		reference	operator[](value_type i) const { return(_ptr[i]); } // faux ds peu de tps

	protected:
		value_type							*_ptr;

	};

}

#endif