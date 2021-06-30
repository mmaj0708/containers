
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <vector>
# include <cstddef>
# include <sstream>

namespace	ft	{
	
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:

    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::size_type       size_type;

	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _alloc(alloc)
	{}

	explicit vector (size_type n, const value_type& val = value_type(),
	const allocator_type& alloc = allocator_type()) : _size(n), _alloc(alloc)
	{
		size_type	i = 0;

		_tab = new value_type[n];
		while (i < n)
		{
			_tab[i] = val;
			i++;
		}
	}
	
	value_type	& operator[]( value_type i )
	{
		return (_tab[i]);
	}

	int		size() {return _size;}
	
	// PROCHAINE FOIS CONSTRUCTEUR SUIVANT !!

	~vector() {}
    // typedef typename allocator_type::reference       reference;
    // typedef typename allocator_type::const_reference const_reference;
    // typedef implementation-defined                   iterator;
    // typedef implementation-defined                   const_iterator;
    // typedef typename allocator_type::difference_type difference_type;
    // typedef typename allocator_type::pointer         pointer;
    // typedef typename allocator_type::const_pointer   const_pointer;
    // typedef std::reverse_iterator<iterator>          reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		
	// explicit vector (size_type n, const value_type& val = value_type(),
	//                  const allocator_type& alloc = allocator_type());

	// template <class InputIterator>
	// vector (InputIterator first, InputIterator last,
	//                  const allocator_type& alloc = allocator_type());
	// vector (const vector& x);
	
	private:

	int			_size;
	Allocator	_alloc;
	value_type	*_tab;

	};
}

#endif
