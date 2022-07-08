#pragma once
#include "array_interface.h"

template<typename T>
class Array : IArray<T> {
public:
	Array(int capacity = 1);
	~Array();

	int size() const override;
	bool empty() const override;

	T& operator[](int index) override;
	const T& operator[](int index) const override;

	void PushBack(const T& data) override;
	void PushFront(const T& data) override;
	void Insert(int index, const T& data) override;

	void PopBack() override;
	void PopFront() override;
	void Erase(int index) override;

private:
	void MoveBackward(int index);
	void MoveForward(int index);

	void EmptyException() const;
	void OutOfRange(int index) const;

	bool full() const;
	void ChangeCapacity();

private:
	int size_;
	int capacity_;
	T* data_;
};

template<typename T>
Array<T>::Array(int capacity) : capacity_{ capacity }, size_{ 0 } {
	data_ = new T[capacity_];
}

template<typename T>
inline Array<T>::~Array() {
	delete[] data_;
}

template<typename T>
inline int Array<T>::size() const {
	return size_;
}

template<typename T>
inline bool Array<T>::empty() const {
	return size_ == 0;
}

template<typename T>
T& Array<T>::operator[](int index) {
	OutOfRange(index);
	return data_[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
	OutOfRange(index);
	return data_[index];
}

template<typename T>
inline void Array<T>::PushBack(const T& data) {
	Insert(size_, data);
}

template<typename T>
inline void Array<T>::PushFront(const T& data) {
	Insert(0, data);
}

template<typename T>
void Array<T>::Insert(int index, const T& data) {
	if (full()) ChangeCapacity();
	MoveBackward(index);
	data_[index] = data;
	++size_;
}

template<typename T>
inline void Array<T>::PopBack() {
	Erase(size_ - 1);
}

template<typename T>
inline void Array<T>::PopFront() {
	Erase(0);
}

template<typename T>
void Array<T>::Erase(int index) {
	EmptyException();
	data_[index].~T();
	MoveForward(index);
	--size_;
}

template<typename T>
void Array<T>::MoveBackward(int index) {
	for (int i = size_; i > index; --i) {
		data_[i] = data_[i - 1];
	}
}

template<typename T>
void Array<T>::MoveForward(int index) {
	for (int i = index; i < size_; ++i) {
		data_[i] = data_[i + 1];
	}
}

template<typename T>
void Array<T>::EmptyException() const {
	if (empty()) throw "Array is empty";
}

template<typename T>
void Array<T>::OutOfRange(int index) const {
	if (index < 0 || index >= size_) throw "Out of range";
}

template<typename T>
inline bool Array<T>::full() const {
	return size_ == capacity_;
}

template<typename T>
void Array<T>::ChangeCapacity() {
	capacity_ *= 2;
	T* data_new = new T[capacity_];

	for (int i = 0; i < size_; ++i) {
		data_new[i] = data_[i];
	}
	delete[] data_;

	data_ = data_new;
}
