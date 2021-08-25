/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIte.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:20:33 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/25 15:53:27 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITE_HPP
# define REVERSEITE_HPP

// #include "Rand_iterator.hpp"
#include "base.hpp"
// #include <iostream>

namespace ft
{
	template <class iterator>
	class reverse_iterator : public iterator
	{
	protected :
		iterator _current;

	public:

    typedef iterator                                         		iterator_type;
    typedef typename iterator_traits<iterator>::difference_type		difference_type;
    typedef typename iterator_traits<iterator>::reference       	reference;
    typedef typename iterator_traits<iterator>::pointer         	pointer;

	reverse_iterator() : _current() {}
	explicit reverse_iterator(iterator x) : _current(x) {}
	template <class U> reverse_iterator(const reverse_iterator<U>& u) : _current(u.base()) {}
	template <class U> reverse_iterator& operator=(const reverse_iterator<U>& _u) { _current = _u.base(); return *this; }
	
	iterator base() const {return _current;}
	
	reference			operator*() const {iterator tmp = _current; return *--tmp;}
	pointer				operator->() const {return &this->operator*();}
	reference			operator[](difference_type n) {return *(*this + n);}
    
	reverse_iterator&	operator++() {--_current; return *this;}
    reverse_iterator	operator++(int) {reverse_iterator tmp(*this); --_current; return tmp;}
    reverse_iterator&	operator--() {++_current; return *this;}
    reverse_iterator	operator--(int) {reverse_iterator tmp(*this); ++_current; return tmp;}
    
	template <class U>
	difference_type		operator-(const reverse_iterator<U> &u) { return u.base().operator-(this->_current); }
	reverse_iterator	operator+(difference_type n) const { return reverse_iterator(this->_current.operator-(n)); }
	reverse_iterator&	operator+=(difference_type n) { this->_current.operator-=(n); return *this; }
    reverse_iterator	operator- (difference_type n) const {return reverse_iterator(this->_current.operator+(n));}
    reverse_iterator&	operator-=(difference_type n) {this->_current.operator+=(n); return *this;}
    
	friend reverse_iterator	operator+(difference_type n, reverse_iterator &rhs) {	return rhs.operator+(n); }

	template <class U> bool	operator==(const reverse_iterator<U> &rhs) const { return this->_current.operator==(rhs.base()); }
	template <class U> bool	operator!=(const reverse_iterator<U> &rhs) const { return this->_current.operator!=(rhs.base()); }
	template <class U> bool	operator< (const reverse_iterator<U> &rhs) const { return this->_current.operator> (rhs.base()); }
	template <class U> bool	operator<=(const reverse_iterator<U> &rhs) const { return this->_current.operator>=(rhs.base()); }
	template <class U> bool	operator> (const reverse_iterator<U> &rhs) const { return this->_current.operator< (rhs.base()); }
	template <class U> bool	operator>=(const reverse_iterator<U> &rhs) const { return this->_current.operator<=(rhs.base()); }

	};
}


#endif