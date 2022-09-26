/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map_std.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:54:07 by bpouchep          #+#    #+#             */
/*   Updated: 2022/09/16 13:54:08 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include "map.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs<rhs;}
};

int main(void)
{
	std::cout << "======================= TESTING ALL CONSTRUCTORS =======================" << std::endl;
	std::cout << "\n";

	std::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	std::cout << "Default constructor : OK " << std::endl;
	std::map<char,int> second (first.begin(),first.end());
	std::cout << "Range constructor : OK " << std::endl;

	std::cout << "Copy constructor : OK " << std::endl;
	std::map<char,int> third (second);

	std::map<char,int,classcomp> fourth;                 // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	third = second;
	std::cout << "Overload operator = : OK" << std::endl;
	std::map<std::string, std::string> test;
	std::map<std::string, std::string>::iterator test_it;
	std::map<std::string, std::string>::reverse_iterator rev_test_it;

	test.insert(std::pair<std::string, std::string>("Hello", "World"));
	test.insert(std::pair<std::string, std::string>("This is", "The End"));


	std::cout << "============= ITERATORS =============" << std::endl;
	test_it = test.begin();

	std::cout << "============= BEGIN ITERATOR =============" << std::endl;
	std::cout << "pair of elements : {" << test_it->first << "} {" << test_it->second << "} " << std::endl;
	test_it = test.end();
	--test_it;

	std::cout << "============= END ITERATOR =============" << std::endl;
	std::cout << "pair of elements : {" << test_it->first << "} {" << test_it->second << "} " << std::endl;

	std::cout << "============= RBEGIN ITERATOR =============" << std::endl;
	rev_test_it = test.rbegin();
	std::cout << "pair of elements : {" << test_it->first << "} {" << test_it->second << "} " << std::endl;

	std::cout << "============= REND ITERATOR =============" << std::endl;
	rev_test_it = test.rend();
	--test_it;
	std::cout << "pair of elements : {" << test_it->first << "} {" << test_it->second << "} " << std::endl;

	std::cout << "============= CAPACITY =============" << std::endl;

	std::map<int, std::string>               int_string;
	std::map<std::string, std::string>       string_string;
	std::map<char, char>                     char_char;
	std::map<char, bool>                     char_bool;

	std::cout << "============= BEFORE INSERT =============" << std::endl;
	std::cout << "\n";

	std::cout << "===== Are my containers empty ? =====" << std::endl << std::endl;
	std::cout << "int_string is empty? " << (int_string.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "string_string is empty? " << (string_string.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "char_char is empty? " << (char_char.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "char_bool is empty? " << (char_bool.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "\n";

	std::cout << "===== Size of my containers =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl;
	std::cout << "string_string size: " << string_string.size() << std::endl;
	std::cout << "char_char size: " << char_char.size() << std::endl;
	std::cout << "char_bool size: " << char_bool.size() << std::endl;
	std::cout << "\n";

	std::cout << "===== Max_size of my containers =====" << std::endl << std::endl;
	std::cout << "int_string max_size: " << int_string.max_size() << std::endl;
	std::cout << "string_string max_size: " << string_string.max_size() << std::endl;
	std::cout << "char_char max_size: " << char_char.max_size() << std::endl;
	std::cout << "char_bool max_size: " << char_bool.max_size() << std::endl;
	std::cout << "\n";



	int_string.insert(std::pair<int, std::string>(42, "Hello World!"));
	string_string.insert(std::pair<std::string, std::string>("uwu", "Hello World!"));
	char_char.insert(std::pair<char, char>('o', 'w'));
	char_bool.insert(std::pair<char, bool>('o',false));

	std::cout << "============= AFTER INSERT =============" << std::endl;
	std::cout << "\n";

	std::cout << "===== Empty() =====" << std::endl << std::endl;
	std::cout << "int_string is empty? " << (int_string.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "string_string is empty? " << (string_string.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "char_char is empty? " << (char_char.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "char_bool is empty? " << (char_bool.empty() ? "yes" : "no" ) << std::endl;
	std::cout << "\n";

	std::cout << "===== Size() =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl;
	std::cout << "string_string size: " << string_string.size() << std::endl;
	std::cout << "char_char size: " << char_char.size() << std::endl;
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl;

	std::cout << "===== Max_size() =====" << std::endl << std::endl;
	std::cout << "int_string max_size: " << int_string.max_size() << std::endl;
	std::cout << "string_string max_size: " << string_string.max_size() << std::endl;
	std::cout << "char_char max_size: " << char_char.max_size() << std::endl;
	std::cout << "char_bool max_size: " << char_bool.max_size() << std::endl;
	std::cout << "\n";


	std::cout << "============= ELEMENT ACCESS =============" << std::endl;
	std::cout << "\n";

	std::cout << "===== First element of my containers =====" << std::endl;
	std::cout << "\n";
	std::cout << "int_string " << int_string[42] << std::endl;
	std::cout << "string_string " << string_string["uwu"] << std::endl;
	std::cout << "char_char " << char_char['o'] << std::endl;
	std::cout << "char_bool " << char_bool['o'] << std::endl << std::endl;

	std::cout << "=============  MODIFIERS ============= " << std::endl;
	std::cout << "\n";

	std::cout << "===== Insert() =====" << std::endl << std::endl;

	int_string.insert(std::pair<int, std::string>(43, "a"));
	int_string.insert(std::pair<int, std::string>(44, "b"));
	int_string.insert(std::pair<int, std::string>(45, "c"));
	int_string.insert(std::pair<int, std::string>(46, "d"));
	int_string.insert(std::pair<int, std::string>(47, "e"));
	int_string.insert(std::pair<int, std::string>(48, "f"));
	int_string.insert(std::pair<int, std::string>(49, "g"));

	string_string.insert(std::pair<std::string, std::string>("blabla", "coucou"));
	string_string.insert(std::pair<std::string, std::string>("bonjour", "aurevoir"));
	string_string.insert(std::pair<std::string, std::string>("Only", "Human"));
	string_string.insert(std::pair<std::string, std::string>("After", "All"));
	string_string.insert(std::pair<std::string, std::string>("Soulja", "Boy"));

	char_char.insert(std::pair<char, char>('q', 'a'));
	char_bool.insert(std::pair<char, bool>('w',false));
	char_char.insert(std::pair<char, char>('e', 's'));
	char_bool.insert(std::pair<char, bool>('r',true));
	char_char.insert(std::pair<char, char>('t', 'd'));
	char_bool.insert(std::pair<char, bool>('y',false));
	char_char.insert(std::pair<char, char>('u', 'f'));
	char_bool.insert(std::pair<char, bool>('i',true));

	std::cout << "===== Size() after insert =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl;
	std::cout << "string_string size: " << string_string.size() << std::endl;
	std::cout << "char_char size: " << char_char.size() << std::endl;
	std::cout << "char_bool size: " << char_bool.size() << std::endl;
	std::cout << "\n";

	std::cout << "===== Erase() =====" << std::endl << std::endl;

	int_string.erase(int_string.begin());
	string_string.erase(string_string.begin());
	char_char.erase(char_char.begin());
	char_bool.erase(char_bool.begin());


	std::cout << "===== Size() after erase =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl;
	std::cout << "string_string size: " << string_string.size() << std::endl;
	std::cout << "char_char size: " << char_char.size() << std::endl;
	std::cout << "char_bool size: " << char_bool.size() << std::endl;
	std::cout << "\n";


	std::cout << "===== Clear() =====" << std::endl << std::endl;

	int_string.clear();
	string_string.clear();
	char_char.clear();
	char_bool.clear();

	std::cout << "===== Size() after clear =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl;
	std::cout << "string_string size: " << string_string.size() << std::endl;
	std::cout << "char_char size: " << char_char.size() << std::endl;
	std::cout << "char_bool size: " << char_bool.size() << std::endl;
	std::cout << "\n";

	std::map<std::string, std::string>   map_a;
	std::map<std::string, std::string>::iterator   map_a_it;
	std::map<std::string, std::string>   map_b;
	std::map<std::string, std::string>::iterator   map_b_it;


	std::cout << "============================ SWAP =======================" << std::endl;
	std::cout << "\n";

	std::cout << "===== Before swaping values =====" << std::endl;
	std::cout << "\n";

	std::map<char, int> foo;
	std::map<char, int> bar;
	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	foo.swap(bar);

	std::cout << "===== After swaping values =====" << std::endl;
	std::cout << "\n";
	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "============= KEY_COMP ============= " << std::endl;
	std::cout << "\n";

	std::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;	 // key value of last element

	std::map<char,int>::iterator it = mymap.begin();
	do
		std::cout << it->first << " => " << it->second << std::endl;
	while ( mycomp((*it++).first, highest) );

	std::cout << "\n";

	std::cout << "============= VALUE_COMP ============= " << std::endl;
	std::cout << "\n";

	std::map<char,int> test_map;

	test_map['x']=1001;
	test_map['y']=2002;
	test_map['z']=3003;

	std::cout << "test_map contains:\n";

	std::pair<char,int> highest_pair = *test_map.rbegin();          // last element

	std::map<char,int>::iterator it_val = test_map.begin();
	do {
		std::cout << it_val->first << " => " << it_val->second << '\n';
	} while ( test_map.value_comp()(*it_val++, highest_pair) );

	std::cout << "============= FIND =============" << std::endl;
	std::cout << "\n";
	std::map<int, int>	map2;
	std::map<int, int>::iterator	map2_ite;

	map2.insert(std::pair<int, int>(42, 11238));
	map2.insert(std::pair<int, int>(25, 88907));
	map2.insert(std::pair<int, int>(125, 18));
	map2.insert(std::pair<int, int>(16857, 132));
	map2.insert(std::pair<int, int>(568, 18));
	map2.insert(std::pair<int, int>(67568, 658));
	map2.insert(std::pair<int, int>(5687, 5678));
	map2.insert(std::pair<int, int>(64, 54754));
	map2.insert(std::pair<int, int>(5623123, 56782));
	map2.insert(std::pair<int, int>(213, 56754));
	map2.insert(std::pair<int, int>(568, 5687));

	std::cout << "===== Searching element 42 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.find(42);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;
	map2_ite = map2.find(41232);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;

	std::cout << "============= COUNT =============" << std::endl;
	std::cout << "\n";
	std::cout << "===== Counting element 42 =====" << std::endl;
	std::cout << "\n";
	std::cout << "Element 42 has been found " << map2.count(42) << " times" << std::endl;

	std::cout << "===== Counting element 84 =====" << std::endl;
	std::cout << "\n";
	std::cout << "Element 84 have been found " << map2.count(84) << " times" << std::endl;

	std::cout << "===== Counting element 123897 =====" << std::endl;
	std::cout << "\n";
	std::cout << "Element 123897 have been found " << map2.count(123897) << " times" << std::endl;

	std::cout << "============= LOWER_BOUND =============" << std::endl;
	std::cout << "\n";

	std::cout << "===== Lower_bound for 184 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.lower_bound(184);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;

	std::cout << "===== Lower_bound for 1 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.lower_bound(1);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;


	std::cout << "===== Lower_bound for -1 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.lower_bound(-1);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;

	std::cout << "============= UPPER_BOUND =============" << std::endl;
	std::cout << "\n";
	std::cout << "===== Upper_bound for 184 =====" << std::endl;
	std::cout << "\n";

	map2_ite = map2.upper_bound(184);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;

	std::cout << "===== Upper_bound for -1 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.upper_bound(-1);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;


	std::cout << "===== upper_bound for 123 =====" << std::endl;
	std::cout << "\n";
	map2_ite = map2.upper_bound(123);
	if (map2_ite == map2.end())
		std::cout << "No value found" << std::endl;
	else
		std::cout << "[" << map2_ite->first << "] ["<< map2_ite->second << "] "<< std::endl;

	std::cout << "\n";
	std::cout << "============= EQUAL_RANGE ============= " << std::endl;
	std::cout << "\n";
	std::map<char, int> equal_range_map;

	equal_range_map['a']=10;
	equal_range_map['b']=20;
	equal_range_map['c']=30;

	std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> ret;
	ret = equal_range_map.equal_range('b');

	std::cout << "Lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;

	std::cout << "Upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << std::endl;
}
