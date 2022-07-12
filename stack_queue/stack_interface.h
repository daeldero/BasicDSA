#pragma once

template<typename T>
class IStack {
public:
	IStack() {};
	virtual ~IStack() {};

	virtual int size() const = 0;
	virtual bool empty() const = 0;

	virtual T& top() = 0;
	virtual const T& top() const = 0;

	virtual void Push(const T& data) = 0;
	virtual void Pop() = 0;

//private:
//	List list_;
};
