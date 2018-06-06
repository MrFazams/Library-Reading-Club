#ifndef SET_H
#define SET_H

#include <iostream>

template<typename T>
class Set
{

	T** objects;
	int capacity;
	int size;

	void resizeUp()
	{
		capacity *= 2;
		T** temp = objects;
		objects = new T*[capacity];
		for (int i = 0; i < size; i++) {
			objects[i] = new T;
			*(objects[i]) = *(temp[i]);
		}
		for (int i = size; i < capacity; i++) {
			objects[i] = NULL;
		}
		for (int i = 0; i < size; i++) {
			delete temp[i];
		}
		delete[] temp;
	}
	void resizeDown()
	{
		capacity /= 2;
		T** temp = objects;
		objects = new T*[capacity];
		for (int i = 0; i < size; i++) {
			objects[i] = new T;
			*(objects[i]) = *(temp[i]);
		}
		for (int i = 0; i < size; i++) {
			delete temp[i];
		}
		delete[] temp;
	}

public:

	Set() : capacity(1), size(0)
	{
		objects = new T*[capacity];
		for (int i = 0; i < capacity; i++) objects[i] = NULL;
	}
	Set(const Set & s) : objects(NULL)
	{
		*(this) = s;
	}
	~Set()
	{
		for (int i = 0; i < size; i++) {
			delete objects[i];
		}
		delete[] objects;
	}

	int getCapacity() const
	{
		return capacity;
	}
	int getSize() const
	{
		return size;
	}

	void print() const
	{
		for (int i = 0; i < size; i++) {
			cout << (*this)[i];
		}
	}
	bool has(const T & obj) const
	{
		for (int i = 0; i < size; i++) {
			if ((*this)[i] == obj) return true;
		}
		return false;
	}
	void insert(const T & obj)
	{
		if (this->has(obj)) return;
		if (size == capacity) resizeUp();
		objects[size] = new T;
		*(objects[size]) = obj;
		++size;
	}
	void remove(const T & obj)
	{
		if (this->has(obj)) {
			int pos = 0;
			while ((*this)[pos] != obj) ++pos;
			for (int i = pos + 1; i < size; i++) {
				objects[i - 1] = objects[i];
			}
			--size;
			delete objects[size];
			objects[size] = NULL;
			if (size == capacity / 2) resizeDown();
		}
	}
	bool isEmpty() const
	{
		return size == 0;
	}

	const Set & operator=(const Set & s)
	{
		capacity = s.getCapacity();
		size = s.getSize();
		objects = new T*[capacity];
		for (int i = 0; i < size; i++) {
			objects[i] = new T;
			*(objects[i]) = s[i];
		}
		for (int i = size; i < capacity; i++) {
			objects[i] = NULL;
		}
		return *this;
	}

	T & operator[](unsigned int idx)
	{
		return *(objects[idx]);
	}

	const T & operator[](unsigned int idx) const
	{
		return *(objects[idx]);
	}

};

#endif SET_H