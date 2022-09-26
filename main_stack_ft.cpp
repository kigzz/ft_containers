/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:54:14 by bpouchep          #+#    #+#             */
/*   Updated: 2022/09/16 13:54:15 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "vector.hpp"
#include <stack>
#include <vector>
#include <iostream>

int	main(void)
{
	ft::stack<int> stack1;
	std::cout << "=============   Stack   =============" << std::endl;
	std::cout << "Empty() " << (stack1.empty() == 1 ? "Yes." : "No.") << std::endl;
	std::cout << "Size() stack1 before adding 3 values : " << stack1.size() << std::endl;
	stack1.push(42);
	stack1.push(666);
	stack1.push(137);
	std::cout << stack1.size() << std::endl;
	std::cout << "Tricks with pop() to show all stack1 values " << std::endl;
	for (ft::stack<int> dump = stack1; !dump.empty(); dump.pop())
		std::cout << dump.top() << std::endl;
	std::cout << "Empty() " << (stack1.empty() == 1 ? "Yes." : "No.") << std::endl;
	std::cout << "\n";
	std::cout << "Testing operators" << std::endl;

	ft::stack<int> stack2;
	stack2.push(84);
	stack2.push(1337);
	stack2.push(2727);

	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << "<=" << std::endl;
	if (stack1 <= stack2)
		std::cout << "stack1 is <= than stack2" << std::endl;
	else
		std::cout << "stack1 is not <= than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << "<" << std::endl;
	if (stack1 < stack2)
		std::cout << "stack1 is < than stack2" << std::endl;
	else
		std::cout << "stack1 is not < than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << "==" << std::endl;
	if (stack1 == stack2)
		std::cout << "Both stacks are equal" << std::endl;
	else
		std::cout << "Both stacks are not equal" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << ">" << std::endl;
	if (stack1 > stack2)
		std::cout << "stack1 is > than stack2" << std::endl;
	else
		std::cout << "stack1 is not > than stack2" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << ">=" << std::endl;
	if (stack1 >= stack2)
		std::cout << "stack1 is >= than stack2" << std::endl;
	else
		std::cout << "stack 1 is not >= than stack2" << std::endl;

	std::cout << "================================" << std::endl;
	std::cout << "Operator : " << "!=" << std::endl;
	if (stack1 != stack2)
		std::cout << "Both stacks are differents" << std::endl;
	else
		std::cout << "Both stacks are equal" << std::endl;
	std::cout << "================================" << std::endl;
}
