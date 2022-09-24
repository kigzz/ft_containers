#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

			vector_iterator() : _current(NULL) {}

			vector_iterator(pointer ptr) : _current(ptr) {}

			vector_iterator(const vector_iterator &cpy) : _current(cpy._current) {}

			virtual ~vector_iterator() {}

			vector_iterator &operator=(const vector_iterator &op) {
				if (this == &op)
					return (*this);
				this->_current = op._current;
				return (*this);
			}

			operator vector_iterator<const T>() const {
				return (this->_current);
			}

			reference operator*() const {
				return (*_current);
			}

			pointer operator->() const {
				return (&(this->operator*()));
			}

			vector_iterator& operator++() {
				++_current;
				return (*this);
			}

			vector_iterator	operator++(int) {
				vector_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			vector_iterator&	operator--() {
				--_current;
				return (*this);
			}

			vector_iterator	operator--(int) {
				vector_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			vector_iterator	operator+(difference_type n) const {
				return (_current + n);
			}

			vector_iterator	operator-(difference_type n) const {
				return (_current - n);
			}

			vector_iterator	operator+=(difference_type n) {
				_current += n;
				return (*this);
			}

			vector_iterator	operator-=(difference_type n) {
				_current -= n;
				return (*this);
			}

			reference	operator[](difference_type n) const {
				return (*(_current + n));
			}

			friend bool operator==(const vector_iterator<T> &it1, const vector_iterator<T> &it2) {
				return (it1._current == it2._current);
			}

			friend bool operator!=(const vector_iterator<T> &it1, const vector_iterator<T> &it2) {
				return (it1._current != it2._current);
			}

			const pointer& base() const	{
				return _current;
			}

		protected:
			pointer _current;

	};

	template<class T>
	bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() == rhs.base();
	}

	template<class T>
	bool operator!=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() != rhs.base();
	}

	template<class T>
	bool operator<(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<class TL, class TR>
	bool operator<(const vector_iterator<TL> &lhs, const vector_iterator<TR> &rhs) {
		return lhs.base() < rhs.base();
	}

	template<class T>
	bool operator>(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<class TL, class TR>
	bool operator>(const vector_iterator<TL> &lhs, const vector_iterator<TR> &rhs) {
		return lhs.base() > rhs.base();
	}

	template<class T>
	bool operator<=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<class TL, class TR>
	bool operator<=(const vector_iterator<TL> &lhs, const vector_iterator<TR> &rhs) {
		return lhs.base() <= rhs.base();
	}

	template<class TL, class TR>
	bool operator>=(const vector_iterator<TL> &lhs, const vector_iterator<TR> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<class T>
	bool operator>=(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
		return lhs.base() >= rhs.base();
	}

	template<class T>
	vector_iterator<T>
	operator+(typename vector_iterator<T>::difference_type lhs, const vector_iterator<T> rhs) {
		return lhs + rhs.base();
	}

	template <class T, class U>
	typename vector_iterator<T>::difference_type
	operator-(const vector_iterator<T> lhs, const vector_iterator<U> rhs) {
		return lhs.base() - rhs.base();
	}
}

#endif
