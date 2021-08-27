/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:33 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/27 14:59:26 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

namespace ft
{
	template <class Iterator> class iterator_traits
	{
		public:
		typedef typename Iterator::difference_type				difference_type;
		typedef typename Iterator::value_type					value_type;
		typedef typename Iterator::pointer						pointer;
		typedef typename Iterator::reference					reference;
		typedef typename std::random_access_iterator_tag	iterator_category;
	};
	
	template <class It> class iterator_traits<It*>
	{
		public:
			typedef It											value_type;
			typedef	value_type&									reference;
			typedef	value_type const&							const_reference;
			typedef	value_type*									pointer;
			typedef ptrdiff_t									difference_type;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};

	template <class It> class iterator_traits<const It*>
	{
		public:
			typedef It											value_type;
			typedef	value_type&									reference;
			typedef	value_type const&							const_reference;
			typedef	value_type*									pointer;
			typedef ptrdiff_t									difference_type;
			typedef typename std::random_access_iterator_tag	iterator_category;
	};
	
	template <bool Cond, class T = void>
	struct enable_if;

	template<class T> 
	struct enable_if<true, T> // pk true ??
	{
		typedef T type; 
	};

	template<typename size_type, class ite>
	size_type	itlen(ite first, ite last)
	{
		size_type	i = 0;
		while (first != last)
		{
			first++;
			i++;
		}
		return i;
	}

	template <class Ite1, class Ite2>
	bool equal ( Ite1 first1, Ite1 last1, Ite2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
			return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class Ite1, class Ite2>
	bool lexicographical_compare (Ite1 first1, Ite1 last1, Ite2 first2, Ite2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <typename T>
	struct node
	{
		T		data;
		node	*parent;
		node	*left;
		node	*right;

		node(const T &src = T()) : data(src), parent(NULL), left(NULL), right(NULL) {}
	};

	template <class T1, class T2> 
	struct pair
	{
		typedef	T1		first_type;
		typedef	T2		second_type;

		T1	first;
		T2	second;

		pair() : first(), second() {}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		pair& operator= (const pair& pr) {first = pr.first; second = pr.second; return *this;}
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}

} // namespace ft


#endif