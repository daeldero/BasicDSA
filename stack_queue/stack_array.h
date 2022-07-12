#pragma once
#include "stack_interface.h"
#include "../ordered_list/array.h"

template<typename T, typename List = Array<T>>
class Stack : IStack<T> {
public:
	Stack(int capacity = 1);
	~Stack() = default;

	int size() const override;
	bool empty() const override;

	T& top() override;
	const T& top() const override;

	void Push(const T& data) override;
	void Pop() override;

private:
	Array<T> list_;
};

template<typename T, typename List>
Stack<T, List>::Stack(int capacity) {
	list_ = Array<T>(capacity);
}

template<typename T, typename List>
inline int Stack<T, List>::size() const {
	return list_.size();
}

template<typename T, typename List>
inline bool Stack<T, List>::empty() const {
	return list_.empty();
}

template<typename T, typename List>
inline T& Stack<T, List>::top() {
	return list_[size() - 1];
}

template<typename T, typename List>
inline const T& Stack<T, List>::top() const {
	return list_[size() - 1];
}

template<typename T, typename List>
inline void Stack<T, List>::Push(const T& data) {
	list_.PushBack(data);
}

template<typename T, typename List>
inline void Stack<T, List>::Pop() {
	list_.PopBack();
}
