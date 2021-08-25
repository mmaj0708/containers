/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:26:23 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/25 12:33:06 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <limits>
# include <memory>
# include <stack>
# include <cstddef>
# include <sstream>
# include "Rand_iterator.hpp"
# include "reverseIte.hpp"
# include "base.hpp"
# include "vector.hpp"
# include <iostream>

namespace	ft	{

	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef Container                               container_type;
			typedef typename container_type::value_type      value_type;
			typedef typename container_type::reference       reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type       size_type;
			// static_assert((is_same<_Tp, value_type>::value), "" );

		protected:
    		container_type c;	
		
		public:
			stack(const stack& q) : c(q.c) {}
			explicit stack (const container_type& ctnr = container_type());
			virtual ~stack(void) {}
			stack& operator=(const stack& q) {c = q.c; return *this;}

			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			template <class... Args> void emplace (Args&&... args);
			void pop();
			// void swap (stack& x) noexcept(/*see below*/); 

	};
}

#endif