/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaj <mmaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:26:23 by mmaj              #+#    #+#             */
/*   Updated: 2021/08/25 16:06:59 by mmaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace	ft	{

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container                                container_type;
			typedef typename container_type::value_type      value_type;
			typedef typename container_type::reference       reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type       size_type;

		protected:
    		container_type c;	
		
		public:
			stack(const stack& q) : c(q.c) {}
			explicit stack(const container_type &ctnr = container_type()) : c(ctnr) {};
			virtual ~stack(void) {}
			stack& operator=(const stack& q) {c = q.c; return *this;}

			bool empty()					const { return c.empty(); }
			size_type size()				const { return c.size(); }
			value_type& top()						  { return c.back(); }
			const value_type& top()			const { return c.back(); }
			void push (const value_type& val)		  { c.push_back(val); }
			void pop()							  { c.pop_back(); }
	
			friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c == rhs.c; }
			friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c != rhs.c; }
			friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; }
			friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c <= rhs.c; }
			friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c > rhs.c; }
			friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c >= rhs.c; }
	};
}

#endif