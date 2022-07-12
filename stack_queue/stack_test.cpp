#include "stack_array.h"
#include "../test.h"

#include <iostream>

void TestStack() {
	Stack<int> stk;
	for (int i = 1; i <= 10; ++i) stk.Push(i);
	while (!stk.empty()) {
		std::cout << "Size = " << stk.size() << ": " << stk.top() << '\n';
		stk.Pop();
	}
}
