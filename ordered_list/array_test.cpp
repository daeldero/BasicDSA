#include "array.h"
#include "../test.h"

#include <iostream>

void PrintArray(const Array<int>& arr) {
	std::cout << "Size = " << arr.size() << ": ";
	for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << ' ';
	std::cout << '\n';
}

void TestArray() {
	std::cout << "Array Test\n";

	Array<int> arr;
	for (int i = 1; i <= 5; ++i) {
		arr.PushBack(i);
		PrintArray(arr);
	}
	for (int i = 6; i <= 10; ++i) {
		arr.PushFront(i);
		PrintArray(arr);
	}

	int idx = 0;
	while (!arr.empty()) {
		if (idx % 2 == 0) arr.PopBack();
		else arr.PopFront();
		PrintArray(arr);
	}

	std::cout << "Array Test End\n\n";
}
