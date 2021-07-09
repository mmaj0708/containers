/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:33 by mmaj              #+#    #+#             */
/*   Updated: 2021/07/09 12:23:23 by mmaj             ###   ########.fr       */
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

	

} // namespace ft


#endif