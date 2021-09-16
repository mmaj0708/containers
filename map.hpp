/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:58:34 by mmaj              #+#    #+#             */
/*   Updated: 2021/09/16 12:54:25 by mmaj             ###   ########.fr       */
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
# include "reverseIteMap.hpp"
# include "base.hpp"
# include "mapIt.hpp"
# include <cmath>
# include <ctgmath>

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
	        typedef ft::reverse_iterator<iterator>				reverse_iterator;
        	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

            void inOrder(node_ptr node) // a virer
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
            : _size(0), _key_cmp(comp), _alloc(alloc)
            {
                _lastEle = _createNode(pair<key_type, mapped_type>());
                _firstEle = _createNode(pair<key_type, mapped_type>());
                _tree = _lastEle;
                _firstEle->left = NULL;
                _lastEle->right = NULL;
            }

            template <class Ite>
            map (Ite first, Ite last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            : _size(0), _key_cmp(comp), _alloc(alloc)
            {
                _lastEle = _createNode(pair<key_type, mapped_type>());
                _firstEle = _createNode(pair<key_type, mapped_type>());
                _tree = _lastEle;
                _firstEle->left = NULL;
                _lastEle->right = NULL;
                while (first != last)
                {
                    insert(ft::pair<key_type, mapped_type>(first->first, first->second));
                    first++;
                }
            }

            map (const map& x) { *this = x; }

            map& operator= (const map& x)
            {
                clear();
                _lastEle = _createNode(ft::pair<const key_type, mapped_type>());
                _firstEle = _createNode(pair<key_type, mapped_type>());
                _tree = _lastEle;
                _firstEle->left = NULL;
                _lastEle->right = NULL;
                insert(x.begin(), x.end());
                return (*this); 
            }

            /* DESTRUCTOR */
            virtual ~map() { 
                clear(); 
                // std::cout << "CHECK destrcut" << std::endl;
                }

            /* ITERATOR */
            iterator begin() { return iterator(fullLeft(_tree)->parent); }
            const_iterator begin() const { return const_iterator(fullLeft(_tree)->parent); }
            iterator end() { return iterator(fullRight(_tree)); }
            const_iterator end() const { return const_iterator(fullRight(_tree)); }

            reverse_iterator rbegin() { return reverse_iterator(fullRight(_tree)->parent); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(fullRight(_tree)->parent); }
            reverse_iterator rend() { return reverse_iterator(begin()); }
            const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

            /* CAPACITY */
            bool empty() const { return (_size == 0 ? 1 : 0); }
            size_type size() const { return _size; }
            // size_type       max_size() const
            // {
            //     if (sizeof(value_type) == 1)
            //         return ((static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1) * 2);
            //     return ((static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1)) ;
            // }
            size_type max_size() const { return (std::numeric_limits<difference_type>::max() / (sizeof(node_type) / 2 ?: 1)); }

            /* ELMT ACCESS */
            mapped_type& operator[] (const key_type& k) {return((*((this->insert(ft::pair<key_type, mapped_type>(k,mapped_type()))).first)).second);}

            /* MODIFIERS */
            pair<iterator,bool> insert (const value_type& val)
            {
                if (_tree != _lastEle && count(val.first))
                    return (ft::pair<iterator, bool>(find(val.first), false));


                node_ptr    newNode = _createNode(val);
                node_ptr    checker = _tree;
                if (_size == 0)
                {
                    newNode->right = _lastEle;
                    newNode->left = _firstEle;
                    _lastEle->parent = newNode;
                    _firstEle->parent = newNode;
                    _tree = newNode;
                    _size++;
                }
                else
                    while (checker != NULL)
                    {
                        if (_key_cmp(val.first, checker->data.first)) // aller dans la branche left
                        {
                            if (checker->left == _firstEle)
                            {
                                newNode->parent = checker;
                                checker->left = newNode;
                                newNode->left = _firstEle;
                                _firstEle->parent = newNode;
                                _size++;
                                return (ft::pair<iterator, bool>(iterator(newNode), true));
                            }
                            else if (checker->left == NULL)
                            {
                                newNode->parent = checker;
                                checker->left = newNode;
                                _size++;
                                return (ft::pair<iterator, bool>(iterator(newNode), true));
                            }
                            checker = checker->left;
                        }
                        else if (!_key_cmp(val.first, checker->data.first)) // aller dans la branche right
                        {
                            if (checker->right == _lastEle)
                            {
                                checker->right = newNode;
                                newNode->right = _lastEle;
                                newNode->parent = checker;
                                _lastEle->parent = newNode;
                                _size++;
                                return (ft::pair<iterator, bool>(newNode, true));
                            }
                            if (checker->right == NULL)
                            {
                                newNode->parent = checker;
                                checker->right = newNode;
                                _size++;
                                return (ft::pair<iterator, bool>(newNode, true));
                            }
                            checker = checker->right;
                        }
                    }
                return (ft::pair<iterator, bool>(newNode, true));
            }

            iterator insert (iterator position, const value_type& val)
            {
                static_cast<void>(position);
                return insert(val).first;
            }
            
            template <class InputIterator> void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
                // insert(*first); 
            }

            void erase (iterator pos)
            {
                iterator    tmp;

                std::cout << "CHECK ROOT " << _tree->data.first << _tree->data.second << std::endl;
                std::cout << "CHECK POS  " << pos->first << pos->second << std::endl;
                std::cout << "CHECK POS  " << &pos._node << std::endl;
                std::cout << "CHECK tree " << &_tree << std::endl;

                // std::cout << "CHECK FIRST " << _firstEle->parent->data.first << std::endl;
                // std::cout << "CHECK LAST  " << _lastEle->parent->data.first << std::endl;

                if (_tree == pos._node)
                    std::cout << "TREE = POS.NODE" << std::endl;

                // case : node is root without children
                if (is_root(pos._node) && (_firstEle->parent == _lastEle->parent))
                {
                    std::cout << "node is root without children" << std::endl;
                    _alloc.destroy(&pos._node->data);
                    pos._node = NULL;
                    _allocNode.deallocate(_tree, 1);
                    _tree = NULL;
                    // DESTROY FIRST && LAST ELE
                    _size--;
                    return;
                }

                // case : node is root with one LEFT child
                else if (is_root(pos._node) && (pos._node->left != NULL && pos._node->right == NULL))
                {
                    std::cout << "node is ROOT with one LEFT child" << std::endl;
                    _tree = pos._node->left;
                    pos._node->left->parent = NULL;
                    _deleteNode(pos._node);
                    _size--;
                    return;
                }

                // case : node is root with one RIGHT child
                else if (is_root(pos._node) && (pos._node->left == NULL && pos._node->right != NULL))
                {
                    std::cout << "node is ROOT with one RIGHT child" << std::endl;
                    _tree = pos._node->right;
                    pos._node->right->parent = NULL;
                    _deleteNode(pos._node);
                    _size--;
                    return;
                }
                
                // case : node is leaf
                else if (pos._node->left == NULL && pos._node->right == NULL)
                {
                    std::cout << "node is LEAF" << std::endl;
                    tmp = pos;
                    if (_isLeftBranch(tmp._node))
                        tmp._node->parent->left = NULL;
                    else
                        tmp._node->parent->right = NULL;
                    _deleteNode(pos._node);
                    // std::cout << "CHECK LEAF" << std::endl;
                    _size--;
                    return;
                }

                // case : node has one LEFT child
                else if ( (pos._node->left != NULL && pos._node->right == NULL) )
                {
                    tmp = pos;
                    // node sits on left branch parent
                    if (_isLeftBranch(tmp._node))
                    {
                        std::cout << "node has one LEFT child and sits on LEFT branch parent" << std::endl;
                        tmp._node->parent->left = tmp._node->left;
                        tmp._node->left->parent = tmp._node->parent;
                        _deleteNode(pos._node);
                    }
                    // node sits on right branch parent
                    else if (!_isLeftBranch(tmp._node))
                    {
                        std::cout << "node has one LEFT child and sits on RIGHT branch parent" << std::endl;
                        tmp._node->parent->right = tmp._node->left;
                        tmp._node->left->parent = tmp._node->parent;
                        _deleteNode(pos._node);
                    }
                }
                // case : node has one RIGHT child
                else if ((pos._node->right != NULL && pos._node->left == NULL))
                {
                    tmp = pos;
                    // node sits on left branch parent
                    if (_isLeftBranch(tmp._node))
                    {
                        std::cout << "node has one RIGHT child and sits on LEFT branch parent" << std::endl;
                        tmp._node->parent->left = tmp._node->right;
                        tmp._node->right->parent = tmp._node->parent;
                        _alloc.destroy(&tmp._node->data);
                        // _deleteNode(pos._node);
                    }
                    // node sits on right branch parent
                    else if (!_isLeftBranch(tmp._node))
                    {
                        std::cout << "node has one RIGHT child and sits on RIGHT branch parent" << std::endl;
                        tmp._node->parent->right = tmp._node->right;
                        tmp._node->right->parent = tmp._node->parent;
                        _deleteNode(pos._node);
                    }
                }
                
                // case : node has TWO children
                else if ((pos._node->right != NULL && pos._node->left != NULL) || (_tree->left != NULL && _tree->right != NULL))
                {
                    iterator    nextNode = pos;

                    std::cout << "node has TWO children" << std::endl;
                    nextNode++;
                    _alloc.construct(&pos._node->data, nextNode._node->data); // copy content of inorder successor
                    std::cout << "SHOULD BE F : " << pos->first << std::endl;
                    erase(nextNode);

                }
                _size--;
            }
            
            size_type erase (const key_type& k)
            {
                if (!count(k))
                    return 0;
                erase(find(k));
                return 1;
            }
            void erase (iterator first, iterator last)
            {
                iterator    tmp = first;
                    // std::cout << "CHECK ERASE" << std::endl;
                // showTree();
                last--;
                // while (tmp != last)
                // {
                // std::cout << "ERASE first " << tmp->first << tmp->second << std::endl;
                // std::cout << "ERASE last  " << last->first << last->second << std::endl;
                    tmp++;
                    erase(first);
                    first = tmp;

                // std::cout << "ERASE first " << tmp->first << tmp->second << std::endl;
                // std::cout << "ERASE last  " << last->first << last->second << std::endl;
                tmp++;
                erase(first);
                first = tmp;

                tmp++;
                // std::cout << "ERASE first " << tmp->first << tmp->second << std::endl;
                // std::cout << "ERASE last  " << last->first << last->second << std::endl;
                erase(first);
                first = tmp;

                std::cout << "ERASE first " << tmp->first << tmp->second << std::endl;
                std::cout << "ERASE last  " << last->first << last->second << std::endl;
                tmp++;
                erase(first);
                first = tmp;
                // showTree();
                // }
                // erase(tmp);
            }

            void swap (map& x)
            {
                _swap(_size, x._size);
                _swap(_key_cmp, x._key_cmp);
                _swap(_alloc, x._alloc);
                _swap(_allocNode, x._allocNode);
                _swap(_tree, x._tree);
            }

            void clear()
            {
                    // std::cout << "CHECK clear" << std::endl;
                if (_tree != _lastEle)
                    erase(begin(), end());
            }

            /* OBSERVERS */
            key_compare key_comp() const { return key_compare(); }
            class value_compare
            {
                friend class map;
                protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
                public:
                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;
                bool operator() (const value_type& x, const value_type& y) const
                {
                    return comp(x.first, y.first);
                }
            };
            value_compare value_comp() const { return value_compare(key_compare()); }

            // /* OPERATIONS */
            iterator find (const key_type& k)
            {
                iterator    it(begin()), it_end(end());
                // it_end--;

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                return it;
            }
            const_iterator find (const key_type& k) const
            {
                const_iterator    it(begin()), it_end(end());
                // it_end--;

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                return it;
            }

            size_type count (const key_type& k) const
            {
                const_iterator    it = this->begin(), it_end = this->end();

                it_end--;

                while (!_equal_key(it->first, k) && it != it_end)
                    it++;
                if (!_equal_key(it->first, k))
                    return 0;
                return 1;
            }

            iterator lower_bound (const key_type& k)
            {
                iterator it = this->begin(), ite = this->end();

                while (it != ite)
                {
                    if (!this->_key_cmp(it->first, k))
                        break;
                    ++it;
                }
                return (it);
            }
            const_iterator lower_bound (const key_type& k) const 
            {
                const_iterator it = this->begin(), ite = this->end();

                while (it != ite)
                {
                    if (!this->_key_cmp(it->first, k))
                        break;
                    ++it;
                }
                return (it);
            }

            iterator upper_bound (const key_type& k)
            {
                iterator it = this->begin(), ite = this->end();

                while (it != ite)
                {
                    if (this->_key_cmp(k, it->first))
                        break;
                    ++it;
                }
                return (it);
            }
            
            const_iterator upper_bound (const key_type& k) const
            {
              	const_iterator it = this->begin(), ite = this->end();

                while (it != ite)
                {
                    if (this->_key_cmp(k, it->first))
                        break;
                    ++it;
                }
                return (it);
            }

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (make_pair<const_iterator, const_iterator>(lower_bound(k),  upper_bound(k))); }
            pair<iterator,iterator>     equal_range (const key_type& k) { return (make_pair<iterator, iterator>(lower_bound(k),  upper_bound(k))); }

            /* ALLOCATOR */
            allocator_type get_allocator() const { return _alloc; }


        private:
            size_type		            _size;
            key_compare		            _key_cmp;
            allocator_type	            _alloc;
            std::allocator<node_type>   _allocNode;
            node_ptr   		            _tree;
            node_ptr                    _lastEle;
            node_ptr                    _firstEle;

            node_ptr    _createNode(const value_type &val)
            {
                node_ptr newNode = _allocNode.allocate(1);
                _alloc.construct(&newNode->data, val);
                newNode->left = NULL;
                newNode->right = NULL;
                newNode->parent = NULL;
                return newNode;
            }

            template <typename U>
            void _swap(U& a, U& b)
            {
                U tmp = a;
                a = b;
                b = tmp;
            }

            void        _deleteNode(node_ptr n)
            {
                _alloc.destroy(&n->data);
                n->left = NULL;
                n->right = NULL;
                n->parent = NULL;
                _allocNode.deallocate(n, 1);
            }

            bool        _isLeftBranch(node_ptr n)
            {
                if (n->parent->left == n)
                    return (true);
                return (false);
            }
            bool        _equal_key(const key_type &k1, const key_type &k2) const {return (!_key_cmp(k1, k2) && !_key_cmp(k2, k1));}
	};
    
    /* RELATIONAL OPERATOR */
    template <class Key, class T, class Compare, class Alloc>
    bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs < rhs)); }

    template <class Key, class T, class Compare, class Alloc>
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
}


            

#endif