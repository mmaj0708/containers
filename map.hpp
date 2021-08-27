/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:58:34 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/27 15:22:08 by mmaj             ###   ########.fr       */
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
# include "mapIt.hpp"

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

            typedef typename allocator_type::pointer               pointer;
            typedef typename allocator_type::const_pointer         const_pointer;
            typedef typename allocator_type::reference             reference;
            typedef typename allocator_type::const_reference       const_reference;
            typedef size_t                                         size_type;
            typedef ptrdiff_t                                      difference_type;
 
            // class value_compare : public std::binary_function<value_type, value_type, bool>
            // {
            //     friend class map;
            //     protected:
            //         key_compare comp;
            //         value_compare(key_compare c) : comp(c) {}
            //     public:
            //         bool operator()(const value_type& x, const value_type& y) const {return comp(x.first, y.first);}
            // };
            typedef ft::node<value_type>						node_type;
            typedef node_type*           						node_ptr;
            
            typedef mapIt<value_type, node_type>                        iterator;
            // typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
            // typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
            // typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
            
            // typedef __insert_return_type<iterator, node_type> insert_return_type;


            /* CONSTRUCTOR */
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _size(0), _key_cmp(comp), _alloc(alloc), _tree(NULL) { _tree = new node_type; }

            // template <class InputIterator>
            // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            // map (const map& x);

            /* DESTRUCTOR */
            ~map() { delete _tree; }
            
            /* ITERATOR */
            //               iterator begin();
            //         const_iterator begin() const;
            //               iterator end();
            //         const_iterator end() const;
            //       reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            //       reverse_iterator rend();
            // const_reverse_iterator rend() const;

            /* CAPACITY */
            bool empty() const { return (_size == 0 ? 1 : 0); }
            size_type size() const { return _size; }
            size_type max_size() const { return (_alloc.max_size()); }

            /* ELMT ACCESS */
            // mapped_type& operator[] (const key_type& k); // (*((this->insert(make_pair(k,mapped_type()))).first)).second

            /* MODIFIERS */
            pair<iterator,bool> insert (const value_type& val)
            {
                  // (void) val;
                  // le premier insert est toujours le root ?
                  // root = plus petite key ?
                  // A new key is always inserted at the leaf
                 
                  // 1. Start from the root. 
                  // 2. Compare the inserting element with root, if less than root, then recurse for left, else recurse for right. 
                  // 3. After reaching the end, just insert that node at left(if less than current) else right. 
                  return (make_pair(iterator(), true));
            }

            // iterator insert (iterator position, const value_type& val);
            // template <class InputIterator> void insert (InputIterator first, InputIterator last);

            // void erase (iterator position);
            // size_type erase (const key_type& k);
            // void erase (iterator first, iterator last);

            // void swap (map& x);
            // void clear();

            /* OBSERVERS */
            // key_compare key_comp() const;
            // value_compare value_comp() const;
            // template <class Key, class T, class Compare, class Alloc>
            // class map<Key,T,Compare,Alloc>::value_compare
            // {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            // friend class map;
            // protected:
            // Compare comp;
            // value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            // public:
            // typedef bool result_type;
            // typedef value_type first_argument_type;
            // typedef value_type second_argument_type;
            // bool operator() (const value_type& x, const value_type& y) const
            // {
            // return comp(x.first, y.first);
            // }
            // }

            // /* OPERATIONS */
            // iterator find (const key_type& k);
            // const_iterator find (const key_type& k) const;

            // size_type count (const key_type& k) const;

            // iterator lower_bound (const key_type& k);
            // const_iterator lower_bound (const key_type& k) const;

            // iterator upper_bound (const key_type& k);
            // const_iterator upper_bound (const key_type& k) const;

            // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            // pair<iterator,iterator>             equal_range (const key_type& k);

            /* ALLOCATOR */
            allocator_type get_allocator() const { return _alloc; }


        private:
            size_type		_size;
            key_compare		_key_cmp;
            allocator_type	_alloc;
            node_ptr   		_tree;

	};
}

#endif