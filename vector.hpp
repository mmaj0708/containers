
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>
# include "Rand_iterator.hpp"

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
	};

	/*	CONSTRUCTOR	*/
	/* default constructor */
	explicit vector (const allocator_type& alloc = allocator_type())
	: _size(0), _max_size(alloc.max_size()), _capacity(0), _alloc(alloc) {}

	/* fill constructor */
	explicit vector (size_type n, const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type())
	: _size(n), _max_size(alloc.max_size()), _capacity(n), _alloc(alloc) {
		
		size_type	i = 0;

		_tab = _alloc.allocate(n);
		while (i < n)
		{
			_alloc.construct(&_tab[i], val);
			i++;
		}
	}

	/* range constructor */	
	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	: _size(0), _max_size(alloc.max_size()), _capacity(0), _alloc(alloc)
	{
		while (first != last)
		{
			_size++;
			_capacity++;
			first++;
			_tab = _alloc.allocate(_size + 1);
		}
	}

	// /* copy constructor */
	// vector (const vector& x) {}

	/* destructor */
	~vector() {
		size_type	i = 0;

		while (i < _size)
		{
			_alloc.destroy(&_tab[i]);
			i++;
		}
		_alloc.deallocate(_tab, _size);
	}

	// /* assignation */
	// vector& operator= (const vector& x);

	// /* ITERATOR */
	iterator				begin() { return (iterator(_tab)); }
	// const_iterator			begin() const;
	iterator				end() { return(iterator(&_tab[_size])); }
	// const_iterator			end() const;
	// reverse_iterator		rbegin();
	// const_reverse_iterator	rbegin() const;
	// reverse_iterator		rend();
	// const_reverse_iterator	rend() const;

	// /* CAPACITY */
	size_type	size() const { return _size; } // return number of elmt in the vector
	size_type	max_size() const { return _max_size; }
	// void		resize (size_type n, value_type val = value_type());
	size_type	capacity() const { return _capacity; }	// return size of allocated storage
	bool		empty() const { if (_size > 0) return 0; return 1; }
	// void		reserve (size_type n);
	
	// /* ELEMENT ACCESS */
	value_type			&operator[]( value_type i ) { return (_tab[i]); }
	
	// reference			operator[] (size_type n);
	// const_reference 	operator[] (size_type n) const;
	
	// reference			at (size_type n);
	// const_reference 	at (size_type n) const;
	
	// reference			front();
	// const_reference		front() const;	
	
	// reference			back();
	// const_reference		back() const;
	
	// /* MODIFIERS */
	// template <class InputIterator>
	// void		assign (InputIterator first, InputIterator last);
	// void		assign (size_type n, const value_type& val);

	void		push_back (const value_type& val) {
		if (++_size > _capacity)
			capacity = capacity * 2;
		if (capacity == 0)
			capacity = 1;
		_size = val;
	}
	// void		pop_back();
	
	// iterator	insert (iterator position, const value_type& val);
	// void		insert (iterator position, size_type n, const value_type& val);
	// template <class InputIterator>
    // void		insert (iterator position, InputIterator first, InputIterator last);

	// iterator	erase (iterator position);
	// iterator	erase (iterator first, iterator last);

	// void 		swap (vector& x);

	// void clear();

	private:

	size_type		_size;
	size_type		_max_size;
	size_type		_capacity;
	allocator_type	_alloc;
	value_type		*_tab;

	};
}

#endif
