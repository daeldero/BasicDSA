#pragma once

template<typename T, typename NodePtr>
class ILinkedList {
public:
	ILinkedList() {};
	virtual ~ILinkedList() {};

	virtual int size() const = 0;
	virtual bool empty() const = 0;

	virtual NodePtr head() = 0;
	virtual const NodePtr head() const = 0;
	virtual NodePtr tail() = 0;
	virtual const NodePtr tail() const = 0;
	virtual NodePtr operator[](int index) = 0;
	virtual const NodePtr operator[](int index) const = 0;

	virtual void PushBack(const T& data) = 0;
	virtual void PushFront(const T& data) = 0;
	virtual void Insert(int index, const T& data) = 0;
	virtual void Insert(NodePtr node, const T& data) = 0;

	virtual void PopBack() = 0;
	virtual void PopFront() = 0;
	virtual void Erase(int index) = 0;
	virtual void Erase(NodePtr node) = 0;
};