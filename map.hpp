/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:58:34 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/26 14:38:07 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include <iostream>
// # include "Rand_iterator.hpp"
# include "reverseIte.hpp"
# include "base.hpp"

namespace	ft	{

    template < class Key,                                     // map::key_type
            class T,                                       // map::mapped_type
            class Compare = std::less<Key>,                     // map::key_compare
            class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
            >
	class map
	{
        public:
            
            typedef Key                                            key_type;
            typedef T                                              mapped_type;
            typedef pair<const key_type, mapped_type>              value_type;
            typedef Compare                                        key_compare;
            typedef Alloc                                          allocator_type;
            typedef value_type&                                    reference;
            typedef const value_type&                              const_reference;

            typedef typename allocator_type::pointer               pointer;
            typedef typename allocator_type::const_pointer         const_pointer;
            typedef typename allocator_type::reference             reference;
            typedef typename allocator_type::const_reference       const_reference;
            typedef size_t                                         size_type;
            typedef ptrdiff_t                                      difference_type;
 
            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}
                public:
                    bool operator()(const value_type& x, const value_type& y) const {return comp(x.first, __y.first);}
            };
            
            // typedef __map_iterator<typename __base::iterator>             iterator;
            // typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
            // typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
            // typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
            
            // typedef __map_node_handle<typename __base::__node, allocator_type> node_type;
            // typedef __insert_return_type<iterator, node_type> insert_return_type;

            /* CONSTRUCTOR */
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            map (const map& x);

        private:

	};
}

#endif