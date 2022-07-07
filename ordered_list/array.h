#pragma once
#include "array_interface.h"

template<typename T>
class Array : IArray<T> {
private:
	int size_;
	int capacity_;
	T* data_;

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
inline T& Array<T>::operator[](int index) {
	return data_[index];
}

template<typename T>
inline const T& Array<T>::operator[](int index) const {
	return data_[index];
}

template<typename T>
inline void Array<T>::PushBack(const T& data) {
	data_[size_++] = data;
}

template<typename T>
void Array<T>::PushFront(const T& data) {
	MoveBackward(0);
	data_[0] = data;
	++size_;
}

template<typename T>
void Array<T>::Insert(int index, const T& data) {
	MoveBackward(index);
	data_[index] = data;
	++size_;
}

template<typename T>
inline void Array<T>::PopBack() {
	data_[--size_].~T();
}

template<typename T>
void Array<T>::PopFront() {
	data_[0].~T();
	MoveForward(0);
	--size_;
}

template<typename T>
void Array<T>::Erase(int index) {
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
