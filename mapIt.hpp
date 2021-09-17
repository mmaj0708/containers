/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIt.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:11:00 by mmaj              #+#    #+#             */
/*   Updated: 2021/09/17 16:02:11 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPIT_HPP
# define MAPIT_HPP

#include "base.hpp"
#include <cstddef>

// regler le probleme de const dans la fct end() implementer un ghost qd on arrive a la fin
// GO POKEMON

namespace ft {

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
        mapIt(node_type *src) { _node = src; }
        mapIt(const mapIt &src) { *this = src; }
        mapIt&   operator=(const mapIt &src) {_node = src._node; return *this;}

        ~mapIt() {}

        bool    operator==(const mapIt &src) { return (_node == src._node ? 1 : 0); }
        bool    operator!=(const mapIt &src) { return (_node != src._node ? 1 : 0); }

        reference      operator*(void) const { return (this->_node->data); }
        pointer        operator->(void) const { return (&this->operator*()); }
        mapIt          operator++(void)
        {
            if (is_end(_node))
            {
                node_type *ghost_node = std::allocator<node_type>().allocate(1);

                ghost_node->parent = _node;
                // set_is_ghost(true);
                _node = ghost_node;
                return (*this);
            }
            // std::cout << "CHECK ++" << std::endl;
            if (_node->right == NULL)
            {
                while (_node->parent->left != _node) // est ce un parent dont il est la branche left ?
                    _node = _node->parent;
                _node = _node->parent;
                return *this;
            }
            else
            {
                _node = _node->right;
                while (_node->left != NULL)
                    _node = _node->left;
                return *this;
            }
        }
        mapIt           operator++(int) {mapIt	tmp(*this); ++(*this); return (tmp);}
        mapIt          operator--(void)
        {
            if (is_begin(_node))
                return (*this);
            if (_node->left == NULL)
            {
                while (_node->parent->right != _node) // est ce un parent dont il est la branche left ?
                {
                    _node = _node->parent;
                }
                _node = _node->parent;
                return *this;
            }
            else
            {
                _node = _node->left;
                while (_node->right != NULL)
                    _node = _node->right;
                return *this;
            }
        }
        mapIt           operator--(int) {mapIt	tmp(*this); --(*this); return (tmp);}

		operator mapIt<const T, node_type>(void) const {
			return mapIt<const T, node_type>(this->_node);
		}

        template <class, class, class, class>
		friend class map;
        
		template <class, class>
		friend class mapIt;
};
}
#endif