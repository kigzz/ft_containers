/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector_std.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:55:02 by bpouchep          #+#    #+#             */
/*   Updated: 2022/09/16 13:55:03 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main(void)
{
	std::cout << "=========   VECTOR   =========" << std::endl;
	std::vector<int>	a;
	std::vector<int>::iterator	a_it;

	std::cout << "Empty? " << (a.empty() == 1 ? "yes." : "no.") << std::endl;
	std::cout << "Size(): " << a.size() << std::endl;
	std::cout << "Max_size(): " << a.max_size() << std::endl;
	std::cout << "Capacity(): " << a.capacity() << std::endl;
	std::cout << "\n";
	std::cout << "=========================================================" << std::endl;
	std::cout << "\n";
	std::cout << "Reserve():" << std::endl;
	a.reserve(918273645);
	std::cout << "Capacity after Reserve(): " << a.capacity() << std::endl;
	std::cout << "Resize()" << std::endl;
	a.resize(16, 42);
	std::cout << "Size() after Resize(): " << a.size() << std::endl;
	std::cout << "Capacity() after Resive(): " << a.capacity() << std::endl;
	std::cout << "Front(): " << a.front() << std::endl;
	std::cout << "Back(): " << a.back() << std::endl;
	a_it = a.end();
	a.insert(a_it, 69);
	std::cout << "\n";
	std::cout << "=========================================================" << std::endl;
	std::cout << "\n";
	std::cout << "Insert() - 69" << std::endl;
	std::cout << "Back() after Insert() - 69: " << a.back() << std::endl;
	++a_it;
	std::cout << "Insert() - 137" << std::endl;
	a.insert(a_it, 137);
	std::cout << "Back() after Insert() - 137: " << a.back() << std::endl;
	std::cout << "Last value with operator[] (should be 69)" << std::endl;
	std::cout << "Value of vector[vector.size() - 2]: " << a[a.size() - 2] << std::endl;
	std::cout << "Value of first element with at(): " << a.at(0) << std::endl;
	std::cout << "Value of last element with at(): " << a.at(a.size() - 1) << std::endl;

	std::cout << "\n";
	std::cout << "Testing all constructors" << std::endl;
	std::cout << "\n";

	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third
	std::cout << "Constructors OK" << std::endl;
	std::cout << "\n";
	std::cout << "			Assign()" << std::endl;
	std::cout << "=========================================================" << std::endl;
	std::cout << "\n";
	std::vector<int> c;
	std::vector<int> b;
	std::vector<int>::iterator ft_it;
	std::vector<int>::reverse_iterator rev_ft_it;
	std::vector<int>::const_reverse_iterator const_rev_ft_it;
	std::vector<int>::const_iterator const_ft_it;

	c.assign(16, 42);
	b.reserve(15);
	b.resize(16);
	b.clear();
	b.assign(16, 69);
	std::cout << "Assign() OK" << std::endl;
	std::cout << "\n";
	std::cout << "                     Iterators                   " << std::endl;
	std::cout << "\n";
	ft_it = b.begin();
	b.insert(ft_it, 42);
	ft_it = b.begin();
	const_ft_it = b.begin();
	std::cout << "Begin iterator : OK" << std::endl;
	std::cout << "Value it(begin): " << *(ft_it) << std::endl;
	std::cout << "Value const it(begin): " << *(const_ft_it) << std::endl;
	rev_ft_it = b.rbegin();
	const_rev_ft_it = b.rbegin();
	std::cout << "Value it(rbegin): " << *(rev_ft_it) << std::endl;
	std::cout << "Value const it(rbegin): " << *(const_rev_ft_it) << std::endl;
	b.insert(ft_it, 666);
	ft_it = b.end();
	const_ft_it = b.end();
	b.insert(ft_it, 666);
	rev_ft_it = b.rend();
	const_rev_ft_it = b.rend();
	std::cout << "Value it(rend): " << *(rev_ft_it) << std::endl;
	std::cout << "Value const it(rend): " << *(const_rev_ft_it) << std::endl;
	std::cout << "End iterator OK" << std::endl;
	std::cout << "Value it: " << *(ft_it) << std::endl;
	std::cout << "Value const it: " << *(const_ft_it) << std::endl;
	std::cout << "Value last element vector b: " << b.at(b.size() - 1) << std::endl;
	std::cout << "Value last element vector c : " << c.at(c.size() - 1) << std::endl;
	std::cout << "\n";
	std::cout << "                     Size()                   " << std::endl;
	std::cout << "\n";
	std::vector<int> int_vec;
	std::vector<char> char_vec;
	std::vector<std::string> string_vec;

	int_vec.insert(int_vec.begin(), 69);
	int_vec.insert(int_vec.begin(), 690);
	int_vec.insert(int_vec.begin(), 6900);
	char_vec.insert(char_vec.begin(), 'a');
	char_vec.insert(char_vec.begin(), 'b');
	string_vec.insert(string_vec.begin(), "bonjour");
	string_vec.insert(string_vec.begin(), "World");
	string_vec.insert(string_vec.begin(), "Je m'appelle");
	string_vec.insert(string_vec.begin(), "Didier");

	std::cout << "Size() char vector: " << char_vec.size() << std::endl;
	std::cout << "Size() int vector: " << int_vec.size() << std::endl;
	std::cout << "Size() string vector: " << string_vec.size() << std::endl;

	std::cout << "\n";
	std::cout << "                   Max_Size()                 " << std::endl;
	std::cout << "\n";

	std::cout << "Max_size() char vector : " << char_vec.max_size() << std::endl;
	std::cout << "Max_size() int vector : " << int_vec.max_size() << std::endl;
	std::cout << "Max_size() string vector : " << string_vec.max_size() << std::endl;

	std::cout << "\n";
	std::cout << "                    Resize()                       " << std::endl;
	std::cout << "\n";

	char_vec.resize(690);
	int_vec.resize(6900);
	string_vec.resize(69000);

	std::cout << "Size() char vector after Resize(): " << char_vec.size() << std::endl;
	std::cout << "Size() int vector after Resize(): " << int_vec.size() << std::endl;
	std::cout << "Size() string vector Resize(): " << string_vec.size() << std::endl;

	std::cout << "\n";
	std::cout << "                   Capacity()                " << std::endl;
	std::cout << "\n";

	std::cout << "Capacity() char vector : " << char_vec.capacity() << std::endl;
	std::cout << "Capacity() int vector : " << int_vec.capacity() << std::endl;
	std::cout << "Capacity() string vector : " << string_vec.capacity() << std::endl;


	std::cout << "\n";
	std::cout << "                    Empty check                  " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE CLEAR =====" << std::endl;

	std::cout << "empty of char vector : " << char_vec.empty() << std::endl;
	std::cout << "empty of int vector : " << int_vec.empty() << std::endl;
	std::cout << "empty of string vector : " << string_vec.empty() << std::endl;

	char_vec.clear();
	int_vec.clear();
	string_vec.clear();

	std::cout << "\n";

	std::cout << "====== AFTER CLEAR ======" << std::endl;

	std::cout << "empty of char vector : " << char_vec.empty() << std::endl;
	std::cout << "empty of int vector : " << int_vec.empty() << std::endl;
	std::cout << "empty of string vector : " << string_vec.empty() << std::endl;

	std::cout << "\n";
	std::cout << "                  Reserve()               " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE RESERVE ======" << std::endl;

	std::cout << "Capacity() char vector : " << char_vec.capacity() << std::endl;
	std::cout << "Capacity() int vector : " << int_vec.capacity() << std::endl;
	std::cout << "Capacity() string vector : " << string_vec.capacity() << std::endl;

	std::cout << "\n";

	char_vec.reserve(890);
	int_vec.reserve(8900);
	string_vec.reserve(89000);

	std::cout << "====== AFTER RESERVE ======" << std::endl;

	std::cout << "Capacity() char vector : " << char_vec.capacity() << std::endl;
	std::cout << "Capacity() int vector : " << int_vec.capacity() << std::endl;
	std::cout << "Capacity() string vector : " << string_vec.capacity() << std::endl;

	std::cout << "\n";
	std::cout << "                Operator[]              " << std::endl;
	std::cout << "\n";


	char_vec.insert(char_vec.begin(), 'B');
	int_vec.insert(int_vec.begin(), 137);
	string_vec.insert(string_vec.begin(), "OWO");

	std::cout << "Char vector[0] : " << char_vec[0] << std::endl;
	std::cout << "Int vector[0] : " << int_vec[0] << std::endl;
	std::cout << "String vector[0] : " << string_vec[0] << std::endl;

	std::cout << "\n";
	std::cout << "               AT() element              " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE INSERT ======" << std::endl;

	std::cout << "Char vector[0] : " << char_vec.at(0) << std::endl;
	std::cout << "Int vector[0] : " << int_vec.at(0) << std::endl;
	std::cout << "String vector[0] : " << string_vec.at(0) << std::endl;

	char_vec.insert(char_vec.begin(), 'A');
	int_vec.insert(int_vec.begin(), 777);
	string_vec.insert(string_vec.begin(), "I'm only human after all");

	std::cout << "\n";
	std::cout << "====== AFTER INSERT ======" << std::endl;

	std::cout << "Char vector[0] : " << char_vec.at(0) << std::endl;
	std::cout << "Int vector[0] : " << int_vec.at(0) << std::endl;
	std::cout << "String vector[0] : " << string_vec.at(0) << std::endl;

	std::cout << "\n";
	std::cout << "               FRONT() element               " << std::endl;
	std::cout << "\n";

	std::cout << "Char vector front(): " << char_vec.front() << std::endl;
	std::cout << "Int vector front(): " << int_vec.front() << std::endl;
	std::cout << "String vector front() : " << string_vec.front() << std::endl;


	std::cout << "\n";
	std::cout << "               BACK() element               " << std::endl;
	std::cout << "\n";

	std::cout << "Char vector back(): " << char_vec.back() << std::endl;
	std::cout << "Int vector back(): " << int_vec.back() << std::endl;
	std::cout << "String vector back(): " << string_vec.back() << std::endl;

	std::cout << "\n";
	std::cout << "               ASSIGN element               " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE ASSIGN ======" << std::endl;

	std::cout << "Size() char vector : " << char_vec.size() << std::endl;
	std::cout << "Size() int vector : " << int_vec.size() << std::endl;
	std::cout << "Size() string vector : " << string_vec.size() << std::endl;

	char_vec.assign(42, 'o');
	int_vec.assign(42, 420);
	string_vec.assign(42, "uwu");

	std::cout << "====== AFTER ASSIGN =====" << std::endl;

	std::cout << "Size() char vector : " << char_vec.size() << std::endl;
	std::cout << "Size() int vector : " << int_vec.size() << std::endl;
	std::cout << "Size() string vector : " << string_vec.size() << std::endl;

	std::cout << "\n";
	std::cout << "              PUSH_BACK element check              " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE PUSH_BACK ======" << std::endl;
	std::cout << "Char vector last element: " << char_vec.at(char_vec.size() - 1) << std::endl;
	std::cout << "Int vector last element: " << int_vec.at(int_vec.size() - 1) << std::endl;
	std::cout << "String vector last element : " << string_vec.at(string_vec.size() - 1) << std::endl;


	std::cout << "\n";
	char_vec.push_back('W');
	int_vec.push_back(666);
	string_vec.push_back("After all");

	std::cout << "====== AFTER PUSH_BACK ======" << std::endl;
	std::cout << "Char vector last element: " << char_vec.at(char_vec.size() - 1) << std::endl;
	std::cout << "Int vector last element: " << int_vec.at(int_vec.size() - 1) << std::endl;
	std::cout << "String vector last element: " << string_vec.at(string_vec.size() - 1) << std::endl;

	std::cout << "\n";
	std::cout << "              POP_BACK() element             " << std::endl;
	std::cout << "\n";

	std::cout << "====== BEFORE POP_BACK ======" << std::endl;
	std::cout << "Char vector last element: " << char_vec.at(char_vec.size() - 1) << std::endl;
	std::cout << "Int vector last element: " << int_vec.at(int_vec.size() - 1) << std::endl;
	std::cout << "String vector last element: " << string_vec.at(string_vec.size() - 1) << std::endl;


	std::cout << "\n";
	char_vec.pop_back();
	int_vec.pop_back();
	string_vec.pop_back();

	std::cout << "====== AFTER POP_BACK ======" << std::endl;
	std::cout << "Char vector last element: " << char_vec.at(char_vec.size() - 1) << std::endl;
	std::cout << "Int vector last element: " << int_vec.at(int_vec.size() - 1) << std::endl;
	std::cout << "String vector last element: " << string_vec.at(string_vec.size() - 1) << std::endl;

	std::cout << "\n";
	std::cout << "              INSERT() element              " << std::endl;
	std::cout << "\n";
	std::cout << "======= BEFORE INSERT ======" << std::endl;

	std::cout << "Char vector at[0]: " << char_vec.at(0) << std::endl;
	std::cout << "Int vector at[0]: " << int_vec.at(0) << std::endl;
	std::cout << "String vector at[0]: " << string_vec.at(0) << std::endl;

	char_vec.insert(char_vec.begin(), 'B');
	int_vec.insert(int_vec.begin(), 42424242);
	string_vec.insert(string_vec.begin(), "Rise!");

	std::cout << "\n";
	std::cout << "====== AFTER INSERT ======" << std::endl;
	std::cout << "Char vector at[0]: " << char_vec.at(0) << std::endl;
	std::cout << "Int vector at[0]: " << int_vec.at(0) << std::endl;
	std::cout << "String vector at[0]: " << string_vec.at(0) << std::endl;

	std::cout << "\n";
	std::cout << "              ERASE() element             " << std::endl;
	std::cout << "\n";

	std::cout << "======= BEFORE ERASE ======" << std::endl;
	std::cout << "Size() char vector : " << char_vec.size() << std::endl;
	std::cout << "Siz() int vector : " << int_vec.size() << std::endl;
	std::cout << "Size() string vector : " << string_vec.size() << std::endl;

	char_vec.erase(char_vec.begin());
	int_vec.erase(int_vec.begin());
	string_vec.erase(string_vec.begin());

	std::cout << "======= AFTER ERASE ======" << std::endl;

	std::cout << "Size() of char vector: " << char_vec.size() << std::endl;
	std::cout << "Size() int vector: " << int_vec.size() << std::endl;
	std::cout << "Size() string vector: " << string_vec.size() << std::endl;


	std::cout << "\n";
	std::cout << "              SWAP() element             " << std::endl;
	std::cout << "\n";
	std::cout << "======= BEFORE SWAP ======" << std::endl;
	std::cout << "Value last element vector b: " << b.at(b.size() - 1) << std::endl;
	std::cout << "Value last element vector c : " << c.at(c.size() - 1) << std::endl;
	std::cout << "======= AFTER SWAP ======" << std::endl;
	b.swap(c);
	std::cout << "Value last element vector b: " << b.at(b.size() - 1) << std::endl;
	std::cout << "Value last element vector c : " << c.at(c.size() - 1) << std::endl;

	std::cout << "\n";
	std::cout << "              CLEAR()            " << std::endl;
	std::cout << "\n";
	std::cout << "====== BEFORE CLEAR ======" << std::endl;

	std::cout << "Size()char vector : " << char_vec.size() << std::endl;
	std::cout << "Size() int vector : " << int_vec.size() << std::endl;
	std::cout << "Size() tring vector : " << string_vec.size() << std::endl;

	std::cout << "\n";
	char_vec.clear();
	int_vec.clear();
	string_vec.clear();

	std::cout << "======= AFTER CLEAR =======" << std::endl;

	std::cout << "Size()char vector : " << char_vec.size() << std::endl;
	std::cout << "Size() int vector : " << int_vec.size() << std::endl;
	std::cout << "Size() tring vector : " << string_vec.size() << std::endl;

}
