#pragma once

#include "list_node.h"
#include "linked_list_interface.h"

template<typename T, bool doubly = false, bool circular = false>
class LinkedList : ILinkedList<T, Node<T>> {
public:
	LinkedList() = default;
	~LinkedList();

	int size() const override;
	bool empty() const override;

	Node<T>* head() override;
	const Node<T>* head() const override;
	Node<T>* tail() override;
	const Node<T>* tail() const override;
	Node<T>* operator[](int index) override;
	const Node<T>* operator[](int index) const override;

	void PushBack(const T& data) override;
	void PushFront(const T& data) override;
	void Insert(int index, const T& data) override;
	void Insert(Node<T>* node, const T& data) override;

	void PopBack() override;
	void PopFront() override;
	void Erase(int index) override;
	void Erase(Node<T>* node) override;

private:


private:
	int size_{ 0 };
	NodePtr head_{ nullptr };
	NodePtr tail_{ nullptr };
};

template<typename T, bool doubly, bool circular>
LinkedList<T, doubly, circular>::~LinkedList() {
	while (!empty()) {
		PopFront();
	}
}

template<typename T, bool doubly, bool circular>
inline int LinkedList<T, doubly, circular>::size() const {
	return size_;
}

template<typename T, bool doubly, bool circular>
inline bool LinkedList<T, doubly, circular>::empty() const {
	return size_ == 0;
}

template<typename T, bool doubly, bool circular>
inline Node<T>* LinkedList<T, doubly, circular>::head() {
	return head_;
}

template<typename T, bool doubly, bool circular>
inline const Node<T>* LinkedList<T, doubly, circular>::head() const {
	return head_;
}

template<typename T, bool doubly, bool circular>
inline Node<T>* LinkedList<T, doubly, circular>::tail() {
	return tail_;
}

template<typename T, bool doubly, bool circular>
inline const Node<T>* LinkedList<T, doubly, circular>::tail() const {
	return tail_;
}

