#pragma once
#include <iostream>
using namespace std;

namespace Vector
{
	template<typename T>
	class vector
	{
	private:
		size_t sz;
		T* elem;
		size_t space;

	public:
		vector() : sz(0), elem(nullptr), space(0) {}
		explicit vector(size_t s) : sz(s), elem(new T[s]), space(s) {}

		vector(const vector&);//copy constructor
		vector& operator=(const vector&);//copy assignment
		~vector() { delete[] elem; cout << "Destructor called" << endl; }

		//checked access, throw an exception if out of bounds
		T& at(size_t n);
		const T& at(size_t n) const;

		//unchecked access
		T& operator[](size_t n);
		const T& operator[](size_t n) const;

		size_t size() const { return sz; }
		int capacity() const { return space; }

		void resize(size_t newsize);
		void reserve(size_t malloc);
		void push_back(T d);
	};

	struct out_of_range_ {};

	template<typename T>
	T& vector<T>::operator[](size_t n)
	{
		return elem[n];
	}

	template<typename T>
	const T& vector<T>::operator[](size_t n) const
	{
		return elem[n];
	}

	template<typename T>
	T& vector<T>::at(size_t n)
	{
		if (n < 0 || n >= sz) throw out_of_range_();
		return elem[n];
	}

	template<typename T>
	const T& vector<T>::at(size_t n) const
	{
		if (n < 0 || n >= sz) throw out_of_range_();
		return elem[n];
	}

	template<typename T>
	vector<T>::vector(const vector<T>& a) : sz (a.sz), elem( new T[a.sz]), space(a.sz)
	{
		cout << "Copy constructor" << endl;
		for (size_t i = 0; i < sz; i++)
		{
			elem[i] = a.elem[i];
		}
	}

	template<typename T>
	vector<T>& vector<T>::operator=(const vector<T>& a)
	{
		cout << "Copy assignment" << endl;

		if (this == &a) return *this; //self-assignment, no work needed
		if (a.sz <= space)
		{
			for (size_t i = 0; i < sz; i++) elem[i] = a.elem[i];
			sz = a.sz;
			return *this;
		}
		else
		{
			T* p = new T[a.sz];
			for (size_t i = 0; i < sz; i++) p[i] = a.elem[i];
			delete[] elem;
			elem = p;
			space = a.sz;
			sz = a.sz;
			return *this;
		}
	}

	template<typename T>
	void vector<T>::reserve(size_t newalloc)
	{
		if (newalloc <= space) return; 
		T* p = new T[newalloc];
		for (size_t i = 0; i < sz; i++) p[i] = elem[i];
		delete[] elem;
		elem = p;
		space = newalloc;
	}

	template<typename T>
	void vector<T>::resize(size_t newsize)
	{
		reserve(newsize);
		for (size_t i = sz; i < newsize; i++) elem[i] = T();
		sz = newsize;
	}

	template<typename T>
	void vector<T>::push_back(T d)
	{
		if (sz == 0) reserve(8);
		else if (sz == space) reserve(2 * space);
		elem[sz] = d;
		++sz;
	}

	template<typename T>
	ostream& operator<<(ostream& os, const vector<T>& v)
	{
		for (size_t i = 0; i < v.size(); i++)
		{
			os << v[i] << " ";
		}
		return os;
	}

}


