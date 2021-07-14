/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:50 by mmaj              #+#    #+#             */
/*   Updated: 2021/07/14 17:00:46 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// pk besoin de rajouter une classe iterator dans vector_decl.hpp ??
// pk pas tous les operators dans rand_it ??
// comment tu fais ++a, a++, *a++
// Cé KOI difference_type/ptrdiff_t ??

// iterator = pointer enveloppé dans une classe

// PK LA FONCTION AT A BESOIN DE CA ?

PROCHAINE FOIS GERER INSERT AC RANGE ET PR UNE VALEUR

#ifndef RAND_ITERATOR_HPP
# define RAND_ITERATOR_HPP

namespace ft
{

	template<typename T>
	class randIt
	{

	public:

	    typedef T							value_type;
		typedef	value_type&					reference;
		typedef	value_type*					pointer;
		typedef ptrdiff_t					difference_type;

		randIt() : _ptr(NULL) { return; }
		randIt(value_type	*ptr) { _ptr = ptr; }

		randIt &operator=(randIt const &src) { _ptr = src._ptr; return *this; } // Marc a mis *a
		virtual ~randIt() {}

		// bool	operator==(randIt const &rhs) const;
		bool	operator!=(randIt const &rhs) const { return(_ptr != rhs._ptr ? 1 : 0); }
		// bool	operator>(randIt const &rhs) const;
		// bool	operator<(randIt const &rhs) const;
		// bool	operator<=(randIt const &rhs) const;
		// bool	operator>=(randIt const &rhs) const;
		
		reference	operator*(void) const { return(*_ptr); }
		randIt		&operator++(void) { _ptr++; return(*this); } // ++ avant
		randIt		operator++(int) { randIt tmp(*this); ++this->_ptr; return(tmp); } // ++ apres;
		randIt		&operator--(void) { _ptr--; return(*this); } // -- avant
		randIt		operator--(int) { randIt tmp(*this); --this->_ptr; return(tmp); } // -- apres;
		// randIt		operator+(difference_type n) const;
		// randIt		operator-(difference_type n) const;
		// randIt	operator-(randIt const &rhs) const;
		reference	operator[](value_type i) const { return(_ptr[i]); } // faux ds peu de tps

	protected:
		value_type							*_ptr;

	};

}

#endif