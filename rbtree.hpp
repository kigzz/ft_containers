#ifndef FT_CONTAINERS_RBTREE_H
#define FT_CONTAINERS_RBTREE_H

#include "pair.hpp"
#include "rbtree_iterator.hpp"

#define RED true
#define BLACK false

namespace ft
{
	template<class T>
	class Node
	{
	public:
		typedef Node*	node_pointer;

		T data;
		Node<T> *left;
		Node<T> *right;
		Node<T> *parent;
		bool color;

		Node () : data(), left(NULL), right(NULL), parent(NULL), color(RED) { }
		Node (T d) : data(d), left(NULL), right(NULL), parent(NULL), color(RED) { }
		Node (Node const & node) : data(node.data), left(node.left), right(node.right),
								   parent(node.parent), color(node.color) { }

		bool isLeftChild(void) {
			return this->parent->left == this;
		}
		bool isBlack(void) {
			return this->color == BLACK;
		}

		node_pointer leftmost(node_pointer tnull) {
			if (this == tnull)
				return (tnull);
			node_pointer tmp = this;
			while (tmp->left && tmp->left != tnull) {
				tmp = tmp->left;
			}
			return tmp;
		}

		node_pointer rightmost(node_pointer tnull) {
			if (this == tnull)
				return (tnull);
			node_pointer tmp = this;
			while (tmp->right && tmp->right != tnull)
				tmp = tmp->right;
			return tmp;
		}
	};

	template < class T, class Compare = std::less<typename T::first>,
			class Alloc = std::allocator<T> >
	class rb_tree
	{
	public:
		typedef T											value_type;
		typedef typename value_type::first_type				key_type;
		typedef typename value_type::second_type			mapped_type;
		typedef Node<value_type>							node_t;
		typedef Node<value_type>*							node_pointer;

		typedef Alloc										allocator_type;
		typedef typename Alloc::template
			rebind<node_t>::other							node_allocator;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;

		class iterator;
		class const_iterator;

	protected:
		Compare _key_compare;
		allocator_type _alloc;
		node_allocator _node_alloc;
		node_pointer	_tnull;
		node_pointer	_root;
		size_type	_size;

	public:
		rb_tree(const Compare comp = Compare(), allocator_type alloc = allocator_type())
				: _key_compare(comp), _alloc(alloc) {
			_tnull = _node_alloc.allocate(1);
			_tnull->parent = NULL;
			_tnull->left = NULL;
			_tnull->right = NULL;
			_tnull->color = BLACK;
			_alloc.construct(&_tnull->data, value_type());
			_root = _tnull;
			_size = 0;
		}

		rb_tree(const rb_tree& cpy)
				: _key_compare(cpy._key_compare), _alloc(cpy._alloc), _node_alloc(cpy._node_alloc) {
			_tnull = _node_alloc.allocate(1);
			_tnull->parent = NULL;
			_tnull->left = NULL;
			_tnull->right = NULL;
			_tnull->color = BLACK;
			_alloc.construct(&_tnull->data, value_type());
			_size = cpy._size;
			copy(_tnull, _root, cpy._root, cpy._tnull);
		}

		~rb_tree() {
			freeTree(_root);
			_node_alloc.destroy(_tnull);
			_node_alloc.deallocate(_tnull, 1);
		}

		void swap(rb_tree& x) {
			if (&x == this)
				return ;

			node_pointer tmp = this->_tnull;
			this->_tnull = x._tnull;
			x._tnull = tmp;

			tmp = this->_root;
			this->_root = x._root;
			x._root = tmp;

			size_type tmp_size = this->_size;
			this->_size = x._size;
			x._size = tmp_size;
		}

		node_pointer add(value_type newMapEntry) {
			node_pointer tmp = find(newMapEntry.first, _root);
			if (tmp && tmp != _tnull)
				return tmp;
			node_pointer node = _node_alloc.allocate(1);
			node->color = RED;
			_alloc.construct(&(node->data), newMapEntry);
			node->left = _tnull;
			node->right = _tnull;
			node->parent = _tnull;
			if (_root == _tnull) {
				_root = node;
				_root->color = BLACK;
			}
			else {
				add(_root, node);
			}
			++_size;
			_tnull->left = getMin();
			_tnull->right = getMax();
			_tnull->parent = _root;
			return node;
		}

		size_type del(key_type key) {
			return (del(find(key, _root)));
		}

		void clear() {
			freeTree(_root);
			_size = 0;
			_root = _tnull;
		}

		node_pointer find (key_type key) const {
			return find(key, _root);
		}

		node_pointer lower_bound(const key_type& key) const {
			node_pointer current = _root;
			node_pointer ret = _tnull;
			while (current != _tnull) {
				if (_key_compare(current->data.first, key) == false) {
					ret = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return ret;
		}

		node_pointer upper_bound(const key_type& key) const {
			node_pointer current = _root;
			node_pointer ret = _tnull;
			while (current != _tnull) {
				if (_key_compare(key, current->data.first)) {
					ret = current;
					current = current->left;
				}
				else {
					current = current->right;
				}
			}
			return ret;
		}

		node_pointer getRoot() const {
			return _root;
		}

		node_pointer getEnd() const {
			return _tnull;
		}

		allocator_type getAllocator() const {
			return _alloc;
		}

		node_pointer getMin() const {
			return (_root->leftmost(_tnull));
		}

		node_pointer getMax() const {
			return (_root->rightmost(_tnull));
		}

		Compare getKeyComp(void) const {
			return _key_compare;
		}

		rb_tree &operator=(const rb_tree &op) {
			if (this == &op)
				return (*this);
			freeTree(_root);
			copy(_tnull, _root, op._root, op._tnull);
			_size = op._size;
			_tnull->left = getMin();
			_tnull->right = getMax();
			_tnull->parent = _root;
			return (*this);
		}

		size_type size() const {
			return _size;
		}
		size_type max_size() const {
			return _node_alloc.max_size();
		}

	private:
		node_pointer copy(node_pointer& parent, node_pointer& node, const node_pointer src, node_pointer cpy_tnull)
		{
			if (src && src != cpy_tnull) {
				node = _node_alloc.allocate(1);
				_alloc.construct(&(node->data), src->data);
				node->color = src->color;
				node->parent = parent;
				node->left = _tnull;
				node->right = _tnull;
				if (src->left && src->left != cpy_tnull)
					node->left = copy(node, node->left, src->left, cpy_tnull);
				if (src->right && src->right != cpy_tnull)
					node->right = copy(node, node->right, src->right, cpy_tnull);
			}
			else
				node = _tnull;
			return (node);
		}

		void freeTree(node_pointer node) {
			if (node == NULL || node == _tnull)
				return ;
			freeTree(node->left);
			freeTree(node->right);
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
			node = NULL;
		}

		void rotate (node_pointer node) {
			if (node->isLeftChild()) {
				if (node->parent->isLeftChild()) {
					rightRotate(node->parent->parent);
					node->color = RED;
					node->parent->color = BLACK;
					if (node->parent->right != _tnull)
						node->parent->right->color = RED;
				}
				else {
					rightLeftRotate(node->parent->parent);
					node->color = BLACK;
					node->right->color = RED;
					node->left->color = RED;
				}
			}
			else {
				if (!node->parent->isLeftChild()) {
					leftRotate(node->parent->parent);
					node->color = RED;
					node->parent->color = BLACK;
					if (node->parent->left != _tnull)
						node->parent->left->color = RED;
				}
				else {
					leftRightRotate(node->parent->parent);
					node->color = BLACK;
					node->left->color = RED;
					node->right->color = RED;
				}
			}
		}

		void leftRotate(node_pointer node) {
			node_pointer tmp = node->right;
			node->right = tmp->left;
			if (node->right != _tnull) {
				node->right->parent = node;
			}
			if (node->parent == _tnull) {
				_root = tmp;
				tmp->parent = _tnull;
			}
			else {
				tmp->parent = node->parent;
				if (node->isLeftChild()) {
					tmp->parent->left = tmp;
				}
				else {
					tmp->parent->right = tmp;
				}
			}
			tmp->left = node;
			node->parent = tmp;
		}

		void rightRotate(node_pointer node) {
			node_pointer tmp = node->left;
			node->left = tmp->right;
			if (node->left != _tnull) {
				node->left->parent = node;
			}
			if (node->parent == _tnull) {
				_root = tmp;
				tmp->parent = _tnull;
			}
			else {
				tmp->parent = node->parent;
				if (!node->isLeftChild()) {
					tmp->parent->right = tmp;
				}
				else {
					tmp->parent->left = tmp;
				}
			}
			tmp->right = node;
			node->parent = tmp;
		}

		void leftRightRotate(node_pointer node) {
			leftRotate(node->left);
			rightRotate(node);
		}

		void rightLeftRotate(node_pointer node) {
			rightRotate(node->right);
			leftRotate(node);
		}
		void checkColor(node_pointer node) {
			if (node == _root) {
				if (!node->isBlack())
					node->color = BLACK;
				return;
			}
			if (!node->isBlack() && !node->parent->isBlack()) {
				correctTree(node);
			}
			if (node != _root)
				checkColor(node->parent);
		}

		void correctTree(node_pointer node) {
			if (node->parent->isLeftChild()) {
				if (node->parent->parent->right == _tnull || node->parent->parent->right->isBlack()) {
					rotate(node);
					return ;
				}
				if (node->parent->parent->right != _tnull)
					node->parent->parent->right->color = BLACK;
				node->parent->parent->color = RED;
				node->parent->color = BLACK;
			}
			else {
				if (node->parent->parent->left == _tnull || node->parent->parent->left->isBlack()) {
					rotate(node);
					return ;
				}
				if (node->parent->parent->left != _tnull)
					node->parent->parent->left->color = BLACK;
				node->parent->parent->color = RED;
				node->parent->color = BLACK;
			}
		}

		void add(node_pointer parent, node_pointer newNode) {
			if (_key_compare(parent->data.first, newNode->data.first)) {
				if (parent->right == _tnull) {
					parent->right = newNode;
					newNode->parent = parent;
				}
				else
					add(parent->right, newNode);
			}
			else {
				if (parent->left == _tnull) {
					parent->left = newNode;
					newNode->parent = parent;
				}
				else
					add(parent->left, newNode);
			}
			checkColor(newNode);
		}

		void fixDelete(node_pointer node) {
			node_pointer tmp;
			while (node != _root && node->color == BLACK) {
				if (node->isLeftChild()) {
					tmp = node->parent->right;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						leftRotate(node->parent);
						tmp = node->parent->right;
					}

					if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					}
					else {
						if (tmp->right->color == BLACK) {
							tmp->left->color = BLACK;
							tmp->color = RED;
							rightRotate(tmp);
							tmp = node->parent->right;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->right->color = BLACK;
						leftRotate(node->parent);
						node = _root;
					}
				}
				else {
					tmp = node->parent->left;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						rightRotate(node->parent);
						tmp = node->parent->left;
					}

					if (tmp->right->color == BLACK && tmp->right->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					}
					else {
						if (tmp->left->color == BLACK)
						{
							tmp->right->color = BLACK;
							tmp->color = RED;
							leftRotate(tmp);
							tmp = node->parent->left;
						}

						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->left->color = BLACK;
						rightRotate(node->parent);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}

		void transplant(node_pointer u, node_pointer v) {
			if (u == _root)
				_root = v;
			else if (u->isLeftChild())
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		size_type del(node_pointer node) {
			if (node == NULL || node == _tnull)
				return 0;
			--_size;
			node_pointer z = node;
			node_pointer y = z;
			node_pointer x = z;
			bool y_color = y->color;
			if (z->left == _tnull || z->right == _tnull) {
				x = z->left == _tnull ? z->right : z->left;
				transplant(z, x);
			}
			else {
				y = z->right;
				while (y->left != _tnull)
					y = y->left;
				y_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else {
					transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			if (y_color == BLACK)
				fixDelete(x);
			_tnull->left = getMin();
			_tnull->right = getMax();
			_tnull->parent = _root;
			return 1;
		}

		node_pointer find (key_type key, node_pointer node) const {
			if (node == _tnull)
				return (_tnull);
			if (_key_compare(key, node->data.first))
				return (find(key, node->left));
			else if (_key_compare(node->data.first, key))
				return (find(key, node->right));
			else
				return node;
		}
	};
}

#endif
