/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:39 by mmaj              #+#    #+#             */
/*   Updated: 2021/07/22 20:55:43 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include "Rand_iterator.hpp"
# include "base.hpp"

namespace	ft	{
	
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:

    typedef T                                        	value_type;
    typedef Allocator                                	allocator_type;
    typedef typename allocator_type::size_type       	size_type;
    typedef typename allocator_type::reference       	reference;
    typedef typename allocator_type::const_reference 	const_reference;
    // typedef implementation-defined                   	iterator;
    // typedef implementation-defined                   	const_iterator;
    typedef typename allocator_type::difference_type 	difference_type;
    typedef typename allocator_type::pointer         	pointer;
    typedef typename allocator_type::const_pointer   	const_pointer;
    // typedef std::reverse_iterator<iterator>          	reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>    	const_reverse_iterator;

	class iterator : public randIt<value_type>
	{
		public:
		iterator() : randIt<value_type>() {};
		iterator(value_type *ptr) : randIt<value_type>(ptr) {};

		iterator	operator+(difference_type n) { return (iterator(randIt<value_type>::_ptr + n)); }
	};

	/*	CONSTRUCTOR	*/
	/* default constructor */
	explicit vector (const allocator_type& alloc = allocator_type())
	: _size(0), _capacity(0), _alloc(alloc) {}

	/* fill constructor */
	explicit vector (size_type n, const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type())
	: _size(n), _capacity(n), _alloc(alloc)
	{	
		// std::cout << "FILL CONSTRUCT" << std::endl;
		size_type	i = 0;

		_tab = _alloc.allocate(n);
		while (i < n)
		{
			_alloc.construct(&_tab[i], val);
			i++;
		}
	}

	/* range constructor */	
	template <class InputIte>
    vector (typename ft::enable_if<!std::numeric_limits<InputIte>::is_integer, InputIte>::type first,
	InputIte last, const allocator_type& alloc = allocator_type())
	: _size(0), _capacity(0), _alloc(alloc)
	{
		// std::cout << "RANGE" << std::endl;
		size_type	i = 0;
		size_type	_size = itlen<size_type, InputIte>(first, last);

		_tab = _alloc.allocate(_size);
		while (first != last)
		{
			_alloc.construct(&_tab[i], *first);
			first++;
			i++;
		}
		_capacity = _size;
	}

	/* copy constructor */
	vector (const vector& x)
	: _size(0), _capacity(0), _alloc(allocator_type()), _tab(NULL) { *this = x; }

	/* destructor */
	~vector()
	{
		size_type	i = 0;

		while (i < _size)
		{
			_alloc.destroy(&_tab[i]);
			i++;
		}
		_alloc.deallocate(_tab, _size);
	}

	/* assignation */
	vector& operator= (const vector& x)
	{
		size_type	i = 0;
		if (this == &x)
			return (*this);
		_size = x._size;
		_capacity = x._capacity;
		_tab = _alloc.allocate(_capacity);
		while (++i < _size)
			_alloc.construct(&_tab[i], x._tab[i]);
		return(*this);
	}

	/* ITERATOR */
	iterator				begin() { return (iterator(_tab)); }
	// const_iterator			begin() const { return (iterator(_tab)); }
	iterator				end() { return(iterator(&_tab[_size])); }
	// const_iterator			end() const { return(iterator(&_tab[_size])); }
	// reverse_iterator		rbegin();
	// const_reverse_iterator	rbegin() const;
	// reverse_iterator		rend();
	// const_reverse_iterator	rend() const;

	/* CAPACITY */
	size_type	size() const { return _size; } // return number of elmt in the vector
	size_type	max_size() const { return (_alloc.max_size()); }
	void		resize (size_type n, value_type val = value_type()) {
		value_type	*tab2;
		size_type	i = -1;

		if (n < _size)
			while (n != _size)
				_alloc.destroy(&_tab[_size--]);
		if (n > _size)
		{
			if (n > _capacity * 2)
			{
				tab2 = _alloc.allocate(n);
				_capacity = n;
			}
			else
			{
				tab2 = _alloc.allocate(_capacity * 2);
				_capacity = _capacity * 2;
			}
			while (++i < _size)
				_alloc.construct(&tab2[i], _tab[i]);
			while (i < n)
				_alloc.construct(&tab2[i++], val);
			i = 0;
			while (i < _size)
				_alloc.destroy(&_tab[i++]);
			_alloc.deallocate(_tab, _size);
			_size = n;
			_tab = tab2;
		}
	}
	size_type	capacity() const { return _capacity; }
	bool		empty() const { if (_size > 0) return 0; return 1; }
	void		reserve (size_type n)
	{
		value_type	*tab2;
		size_type	i = -1;

		if (n > _capacity)
		{
			tab2 = _alloc.allocate(_capacity * 2);
			while (++i < _size)
				_alloc.construct(&tab2[i], _tab[i]);
			_alloc.deallocate(_tab, _size);
			_tab = tab2;
			_capacity = n;
		}
	}
	
	// /* ELEMENT ACCESS */
	value_type			&operator[]( value_type i ) { return (_tab[i]); }
	
	// reference			operator[] (size_type n);
	// const_reference 	operator[] (size_type n) const;
	
	// AT
	reference			at (size_type n)
	{
		if (n < _size)
			return (_tab[n]);
		std::ostringstream ostr; // GNE ??
		ostr << "vector";
		if (!__FILE__) // __APPLE__ on mac :O
		{
			ostr << "::_M_range_check: __n (which is " << n
				<< ") >= this->size() (which is " << this->_size << ")";
		}
		throw std::out_of_range(ostr.str());
	}
	const_reference 	at (size_type n) const
	{
		if (n < _size)
			return (_tab[n]);
		std::ostringstream ostr; // GNE ??
		ostr << "vector";
		if (!__FILE__)
		{
			ostr << "::_M_range_check: __n (which is " << n
				<< ") >= this->size() (which is " << this->_size << ")";
		}
		throw std::out_of_range(ostr.str());
	}
	
	reference			front() { return _tab[0]; }
	const_reference		front() const { return _tab[0]; }	
	reference			back() { return _tab[_size - 1]; }
	const_reference		back() const { return _tab[_size - 1]; }
	
	// /* MODIFIERS */
	template <class InputIte>
	void		assign (typename ft::enable_if<!std::numeric_limits<InputIte>::is_integer, InputIte>::type first, InputIte last)
	{
		size_type	i = 0;
		size_type	len = itlen<size_type, InputIte>(first, last);
		value_type	*tab2;

		while (i < _size)
			_alloc.destroy(&_tab[i++]);
		_alloc.deallocate(_tab, _size);
		if (len > _size)
		{
			tab2 = _alloc.allocate(len);
			_capacity = len;
		}
		else
			tab2 = _alloc.allocate(_capacity);
		i = -1;
		while (++i < len)
			_alloc.construct(&tab2[i], first[i]);
		_size = len;
		_tab = tab2;
	}
	void		assign (size_type n, const value_type& val)
	{
		size_type	i = 0;
		value_type	*tab2;

		while (i < _size)
			_alloc.destroy(&_tab[i++]);
		_alloc.deallocate(_tab, _size);
		if (n > _size)
		{
			tab2 = _alloc.allocate(n);
			_capacity = n;
		}
		else
			tab2 = _alloc.allocate(_capacity);
		i = -1;
		while (++i < n)
			_alloc.construct(&tab2[i], val);
		_size = n;
		_tab = tab2;
	}

	void		push_back (const value_type& val)
	{
		if (_size == _capacity)
			resize(_size + 1, val);
		else
			_alloc.construct(&_tab[++_size], val);
	}
	void		pop_back() { resize(_size - 1); }
	
	void		insert (iterator position, size_type n, const value_type& val)
	{
		size_type	i = 0;
		size_type	final_size = _size + n;
		value_type	*tab2;
		iterator	first = begin();
		// std::cout << final_size << " " << _capacity << std::endl;
		if (n == 0)
			return;
		if (final_size > _capacity * 2)
		{
			_capacity = final_size;
			tab2 = _alloc.allocate(_capacity);
		}
		else if (final_size > _capacity) // if fs > 2 * cap => cap préc : 
		{
			_capacity = _capacity * 2;
			tab2 = _alloc.allocate(_capacity);
		}
		else
			tab2 = _alloc.allocate(_capacity);
		while (first != position)
			_alloc.construct(&tab2[i++], *(first++));
		while (n > 0)
		{
			_alloc.construct(&tab2[i++], val);
			n--;
		}
		while (first != end())
			_alloc.construct(&tab2[i++], *(first++));
		_clear_all(_size);
		_size = final_size;
		_tab = tab2;
	}
	iterator	insert (iterator position, const value_type& val)
	{
		size_type	len = itlen<size_type, iterator>(begin(), position);

		insert(position, 1, val);
		iterator	ret(&_tab[len]);
		return (ret);
	}
	// template <class InputIterator>
    // void		insert (iterator position, InputIterator first, InputIterator last);

	// iterator	erase (iterator position);
	// iterator	erase (iterator first, iterator last);

	// void 		swap (vector& x);

	// void clear();

	private:

	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;
	value_type		*_tab;

	void			_clear_all(size_type oldsize)
	{
		size_type	i = 0;
		while (i < _size)
			_alloc.destroy(&_tab[i++]);
		if (oldsize)
			_alloc.deallocate(_tab, oldsize);
	}

	};
}

#endif
