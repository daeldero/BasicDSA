#pragma once

template<typename T, bool doubly = false>
struct Node {
	Node(const T& data = T()) : data_{ data } {};

	T data_;
	Node* next_{ nullptr };
};

template<typename T>
struct Node<T, true> {
	Node(const T& data = T()) : data_{ data } {};

	T data_;
	Node* prev_{ nullptr };
	Node* next_{ nullptr };
};