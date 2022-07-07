#pragma once

template<typename T>
class IArray {
//private:
//	int size_;
//	int capacity_;
//	T* data_;

public:
	IArray() {};
	virtual ~IArray() {};

	virtual int size() const = 0;
	virtual bool empty() const = 0;

	virtual T& operator[](int index) = 0;
	virtual const T& operator[](int index) const = 0;

	virtual void PushBack(const T& data) = 0;
	virtual void PushFront(const T& data) = 0;
	virtual void Insert(int index, const T& data) = 0;

	virtual void PopBack() = 0;
	virtual void PopFront() = 0;
	virtual void Erase(int index) = 0;
};
