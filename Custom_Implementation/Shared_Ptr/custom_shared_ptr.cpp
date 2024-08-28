/*
Explicit Keyword in C++ is used to mark constructors to not implicitly convert types in C++. It is optional for constructors that 
take exactly one argument and work on constructors(with a single argument) since those are the only constructors that can be used in 
typecasting.

Reference : https://www.geeksforgeeks.org/use-of-explicit-keyword-in-cpp/

*/

#include <iostream>
using namespace std;

// Class representing a reference counter class
class ReferenceCounter 
{
public:
	// Constructor
	ReferenceCounter() : m_counter(0){};

	//delete the copy constructor and assignment operator implementation
	ReferenceCounter(const ReferenceCounter&) = delete;
	ReferenceCounter& operator=(const ReferenceCounter&) = delete;

	// Destructor
	~ReferenceCounter() = default;

	void reset() noexcept { m_counter = 0; }
	unsigned int get() const noexcept	{ return m_counter; }

	// Operator functions
	void operator++() noexcept { m_counter++; }
	void operator++(int) noexcept { m_counter++; }

	// Operator functions
	void operator--() noexcept { m_counter--; }
	void operator--(int) noexcept {  m_counter--; }

	// Overloading << operator
	friend ostream& operator<<(ostream& os,	const ReferenceCounter& counter);
	

private:
	unsigned int m_counter;
};

ostream& operator<<(ostream& os,const ReferenceCounter& counter)
{
	os << "Counter Value : " << counter.m_counter<< endl;
	return os;
}

// Class representing a shared pointer
template <typename T>
class Shared_ptr 
{
public:
	// Constructor
	explicit Shared_ptr(T* ptr = nullptr) noexcept : m_ptr(ptr)
	{
		//m_ptr = ptr;
		m_counter = new ReferenceCounter();
		(*m_counter)++;
	}

	// Copy constructor
	Shared_ptr(Shared_ptr<T>& sp) noexcept : m_ptr(sp.m_ptr), m_counter(sp.m_counter)
	{
		(*m_counter)++;
	}

	void swap(Shared_ptr<T>& source)
	{
		std::swap(this->m_counter, source->m_counter);
		std::swap(this->m_ptr, source->m_ptr);
	}

	//Copy Assignment operator
	Shared_ptr<T>& operator=(const Shared_ptr<T>& source) noexcept
	{
		if(this != &source)
		{
			Shared_ptr tmp(source);
			this->swap(tmp);
		}
		*this->m_counter++;
		return *this;
	}

	// Move Constructor
	Shared_ptr(Shared_ptr<T>&& sp) noexcept :m_ptr(std::move(sp.m_ptr)), m_counter(std::move(sp.m_counter))
	{
		sp.m_ptr = nullptr;
		sp.m_counter = 0;
		(*m_counter)++;
	}

	//Copy Assignment operator
	Shared_ptr<T>& operator=(const Shared_ptr<T>&& source) noexcept
	{
		if(this != &source)
		{
			Shared_ptr tmp(std::move(source));
			this->swap(tmp);
		}
		*this->m_counter++;
		return *this;
	}

	// Reference count
	unsigned int use_count() const noexcept
	{ 
		return m_counter->get(); 
	}

	// Get the pointer 
	T* get() const noexcept
	{ 
		return m_ptr; 
	}
	
	// * operator implemenation
	T& operator*() const noexcept
	{ 
		return *m_ptr; 
	}

	// -> operator implemenation
	T* operator->() const noexcept
	{ 
		return m_ptr;
	}

	// Destructor
	~Shared_ptr() noexcept
	{
		(*m_counter)--;
		if (m_counter->get() == 0) 
		{
			delete m_counter;
			delete m_ptr;
		}
	}

	friend ostream& operator<<(ostream& os,	Shared_ptr<T>& sp);

private:
	// Reference counter
	ReferenceCounter* m_counter;
	// Shared pointer
	T* m_ptr;
};

template<class T>
ostream& operator<<(ostream& os, Shared_ptr<T>& sp)
{
	os << "Address pointed : " << sp.get() << endl;
	os << *(sp.m_counter) << endl;
	return os;
}

int main()
{
	// ptr1 pointing to an integer.
	Shared_ptr<int> ptr1(new int(151));
	cout << "--- Shared pointers ptr1 ---\n";
	*ptr1 = 100;
	cout << " ptr1's value now: " << *ptr1 << endl;
	cout << ptr1;

	{
		// ptr2 pointing to same integer
		// which ptr1 is pointing to
		// Shared pointer reference counter
		// should have increased now to 2.
		Shared_ptr<int> ptr2 = ptr1;
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;

		{
			// ptr3 pointing to same integer
			// which ptr1 and ptr2 are pointing to.
			// Shared pointer reference counter
			// should have increased now to 3.
			Shared_ptr<int> ptr3(ptr2);
			cout << "--- Shared pointers ptr1, ptr2, ptr3 "
					"---\n";
			cout << ptr1;
			cout << ptr2;
			cout << ptr3;
		}

		// ptr3 is out of scope.
		// It would have been destructed.
		// So shared pointer reference counter
		// should have decreased now to 2.
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;
	}

	// ptr2 is out of scope.
	// It would have been destructed.
	// So shared pointer reference counter
	// should have decreased now to 1.
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;

	return 0;
}
