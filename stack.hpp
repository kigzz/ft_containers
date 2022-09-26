/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:56:39 by bpouchep          #+#    #+#             */
/*   Updated: 2022/09/16 13:56:39 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include <memory>
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;

		protected:
			Container c;

		public:
			explicit stack(const Container& cont = Container()) : c(cont) {}

			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			value_type& top() {
				return c.back();
			}

			const value_type& top() const {
				return c.back();
			}

			void push(const value_type& value) {
				c.push_back(value);
			}

			void pop() {
				c.pop_back();
			}

			template <class Tf, class ContainerF>
			friend bool operator>= (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
			template <class Tf, class ContainerF>
			friend bool operator>  (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
			template <class Tf, class ContainerF>
			friend bool operator<= (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
			template <class Tf, class ContainerF>
			friend bool operator<  (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
			template <class Tf, class ContainerF>
			friend bool operator!= (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
			template <class Tf, class ContainerF>
			friend bool operator== (const stack<Tf,ContainerF>& lhs, const stack<Tf,ContainerF>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c != rhs.c;
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c < rhs.c;
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c <= rhs.c;
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c > rhs.c;
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c >= rhs.c;
	}
}

#endif
