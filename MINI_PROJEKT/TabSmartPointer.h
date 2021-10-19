#pragma once

#include "RefCounter.h"

using namespace std;

template <typename T>
class TabSmartPointer {

public:

	TabSmartPointer(T **pointerr, int size_x);
	TabSmartPointer(const TabSmartPointer<T> &other);
	~TabSmartPointer();
	T& operator*() { return(*pointer); };
	T* operator->() { return(pointer); };
	void operator=(const TabSmartPointer<T> &other);
	int getCounter() { return counter->get(); };
private:

	T **pointer;
	RefCounter *counter;
	int tab_size_x = 0;
	void copy(const TabSmartPointer<T> &other);
	void decrease();
};

template <typename T>
TabSmartPointer<T>::TabSmartPointer(T **pointerr, int size_x)
{
	pointer = pointerr;
	tab_size_x = size_x;
	counter = new RefCounter();
	counter->add();
}

template <typename T>
TabSmartPointer<T>::~TabSmartPointer()
{
	decrease();
}

template <typename T>
TabSmartPointer<T>::TabSmartPointer(const TabSmartPointer<T> &other)
{
	copy(other);
}

template <typename T>
void TabSmartPointer<T>::operator=(const TabSmartPointer<T> &other)
{
	decrease();
	copy(other);
}

template <typename T>
void TabSmartPointer<T>::copy(const TabSmartPointer<T> &other)
{
	if (other.tab_size_x != 0) tab_size_x = other.tab_size_x;
	pointer = other.pointer;
	counter = other.counter;
	counter->add();
}

template <typename T>
void TabSmartPointer<T>::decrease()
{
	if (counter->dec() == 0)
	{
		if (tab_size_x > 0) {
			for (int i = 0; i < tab_size_x; i++)
			{
				delete pointer[i];
			}
		}
		delete pointer;
		delete counter;
	}
}