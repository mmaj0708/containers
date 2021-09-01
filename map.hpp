/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:58:34 by mmaj              #+#    #+#             */
/*   Updated: 2021/09/01 18:13:23 by mmaj             ###   ########.fr       */
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
            typedef typename allocator_type::size_type       	   size_type;
            typedef ptrdiff_t                                      difference_type;
 
            typedef ft::node<value_type>						node_type;
            typedef node_type*           						node_ptr;
            typedef mapIt<value_type, node_type>                iterator;
            typedef mapIt<const value_type, node_type>          const_iterator;


            void inOrder(node_ptr node)
            {
                if (node == NULL) {
                return;
                }
                inOrder(node->left);
                std::cout << "KEY " << node->data.first << std::endl;
                inOrder(node->right);
            }

            void showTree() { inOrder(_tree); }

            /* CONSTRUCTOR */
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _size(0), _key_cmp(comp), _alloc(alloc), _tree(NULL) { /*_tree = new node_type;*/ }

            // template <class InputIterator>
            // map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
            // map (const map& x);

            /* DESTRUCTOR */
            ~map() { delete _tree; }
            
            /* ITERATOR */
            iterator begin() { return iterator(fullLeft(_tree)); }
            const_iterator begin() const { return const_iterator(fullLeft(_tree)); }
            iterator end() { return iterator(fullRight(_tree)); }
            const_iterator end() const { return const_iterator(fullRight(_tree)); }
            //       reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            //       reverse_iterator rend();
            // const_reverse_iterator rend() const;

            /* CAPACITY */
            bool empty() const { return (_size == 0 ? 1 : 0); }
            size_type size() const { return _size; }
            size_type max_size() const { return (_alloc.max_size()); }

            /* ELMT ACCESS */
            mapped_type& operator[] (const key_type& k) {return((*((this->insert(make_pair(k,mapped_type()))).first)).second);}

            /* MODIFIERS */
            pair<iterator,bool> insert (const value_type& val)
            {
                if (_tree != NULL && count(val.first))
                    return (make_pair(find(val.first), false));

                node_ptr    newNode = _createNode(val);
                node_ptr    checker = _tree;

                if (_size == 0)
                {
                    _tree = newNode;
                    _size++;
                }
                else
                    while (checker != NULL)
                    {
                        if (val.first < checker->data.first)
                        {
                            if (checker->left == NULL)
                            {
                                newNode->parent = checker;
                                checker->left = newNode;
                                _size++;
                                return (make_pair(iterator(newNode), true));
                            }
                            checker = checker->left;
                        }
                        else if (val.first > checker->data.first)
                        {
                            if (checker->right == NULL)
                            {
                                newNode->parent = checker;
                                checker->right = newNode;
                                _size++;
                                return (make_pair(newNode, true));
                            }
                            checker = checker->right;
                        }
                    }
                return (make_pair(newNode, true));
            }

            // iterator insert (iterator position, const value_type& val);
            // template <class InputIterator> void insert (InputIterator first, InputIterator last);

            // void erase (iterator position);
            // size_type erase (const key_type& k);
            // void erase (iterator first, iterator last);

            // void swap (map& x);
            // void clear();

            /* OBSERVERS */
            key_compare key_comp() const { return key_compare(); }
            // value_compare value_comp() const { return value_compare(key_compare()); }
    
            // class map<Key,T,Compare,Alloc>::value_compare
            // {
            //     friend class map;
            //     protected:
            //     Compare comp;
            //     value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
            //     public:
            //     typedef bool result_type;
            //     typedef value_type first_argument_type;
            //     typedef value_type second_argument_type;
            //     bool operator() (const value_type& x, const value_type& y) const
            //     {
            //         return comp(x.first, y.first);
            //     }
            // };

            // /* OPERATIONS */
            iterator find (const key_type& k)
            {
                iterator    it(begin()), it_end(end());

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                return it;
            }
            const_iterator find (const key_type& k) const
            {
                const_iterator    it(begin()), it_end(end());

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                return it;
            }

            size_type count (const key_type& k) const
            {
                const_iterator    it = this->begin(), it_end = this->end();

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                if (!_equal_key(it->first, k))
                    return 0;
                return 1;
            }

            // iterator lower_bound (const key_type& k);
            // const_iterator lower_bound (const key_type& k) const;

            // iterator upper_bound (const key_type& k);
            // const_iterator upper_bound (const key_type& k) const;

            // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
            // pair<iterator,iterator>             equal_range (const key_type& k);

            /* ALLOCATOR */
            allocator_type get_allocator() const { return _alloc; }

        private:
            size_type		            _size;
            key_compare		            _key_cmp;
            allocator_type	            _alloc;
            std::allocator<node_type>   _allocNode;
            node_ptr   		            _tree;

            node_ptr    _createNode(const value_type &val)
            {
                node_ptr newNode = _allocNode.allocate(1);
                _alloc.construct(&newNode->data, val);
                newNode->left = NULL;
                newNode->right = NULL;
                newNode->parent = NULL;
                return newNode;
            }

            bool        _equal_key(const key_type &k1, const key_type &k2) const {return (!_key_cmp(k1, k2) && !_key_cmp(k2, k1));}

	};
}

#endif