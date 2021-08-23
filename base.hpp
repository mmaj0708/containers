/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:33 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/23 12:15:35 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE__HPP
# define BASE__HPP

namespace ft
{
	
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
	bool lexicographical_compare (Ite1 first1, Ite1 last1,
    								Ite2 first2, Ite2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

} // namespace ft


#endif