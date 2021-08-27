/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIt.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:11:00 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/27 14:55:42 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAPIT_HPP
# define MAPIT_HPP

#include "base.hpp"
#include <cstddef>

template <typename T, typename node_type>
class mapIt
{
    protected:
        node_type    *_node;

    public:
        typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;

        mapIt() : _node(NULL) {}
        mapIt(const mapIt &src) { *this = src; }
        mapIt&   operator=(const mapIt &src) {_node = src._node; return *this;}

        ~mapIt() {}

        bool    operator==(const mapIt &src) { return (_node == src._node ? 1 : 0); }
        bool    operator!=(const mapIt &src) { return (_node != src._node ? 1 : 0); }

        reference      operator*(void) const { return (*this->_node->data); }
        pointer        operator->(void) const { return (this->_node->data); }

        // *a = t
        // ++a
        // a++
        // *a++

        // --a
        // a--
        // *a--

};

#endif