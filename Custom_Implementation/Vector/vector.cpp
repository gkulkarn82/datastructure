
#include<bits/stdc++.h>
using namespace std;

template<class T>
class MyVector
{
public:
	//default constructor
	MyVector() noexcept : m_size(0), m_ptr(nullptr) 
	{}
	
	//desructor
	~MyVector() noexcept
	{
		m_size = 0;
		if(m_ptr)
			delete[] m_ptr;
		m_ptr = nullptr;
	}
	
	//parameterised constructor
	MyVector(int num_element, int defaul_val) noexcept : m_size(num_element)
	{
		m_ptr = new T[m_size];
		for(int i = 0 ; i < m_size; ++i)
			m_ptr[i] = defaul_val;
	}
	
	//copy constructor
	MyVector(const MyVector& source) noexcept
	{
		int size = source.size();
		m_ptr = new T[size];
		for(int i = 0; i < size; ++i)
		{
			m_ptr[i] = source[i];
		}
	}
	
	void swap(MyVector& source) noexcept
	{
		std::swap(this->m_ptr, source->m_ptr);
		std::swap(this->m_size, source->m_size);
	}
	
	//assignment operator
	MyVector& operator=(const MyVector& source) noexcept
	{
		if(this != &source)
		{
			MyVector temp(source);
			this->swap(temp);
		}
		return *this;		
	}
	
	MyVector(MyVector&& source) noexcept : m_ptr(std::move(source->m_ptr)), m_size(std::move(source->size))
	{
		// source->m_ptr = nullptr;
		// source->size = 0;
	}
	
	MyVector& operator=(const MyVector&& source) noexcept
	{
		if(this != &source)
		{
			MyVector temp(std::move(source)); 
			// keep this thing in mind as we need to create temp or initialise object first as this is preexisting 
			//so we can not call this= std::move(source)
			
			this->swap(temp); 
			// keep this thing in mind do not use this = std::move(temp) this will call move assignment which was we are 
			//writting so it will go in to recursive loop 
		}
		return *this;
	}
	
	std::size_t size() const noexcept  // this is readonly function
	{
		return this->m_size;
	}
	
	T& operator[](std::size_t index)  noexcept
	{	
		return this->m_ptr[index];
	}
	
	T& at(std::size_t index)
	{
		if(index >= size())
			throw("Index out of bound exception");
		
		return (*this)[index] ;//this->operator[](index); //this->m_ptr[index];
	}
	
	void push_back(const T& value)
	{		
		T* temp = new T[m_size + 1];
		
		if(this->m_ptr != nullptr)
		{
			memcpy(temp , this->m_ptr, size() * sizeof(T));
			temp[m_size] = value;
		}
		else
		{
			temp[m_size] = value;
		}
		++m_size;
		
		if(!this->m_ptr)
			delete this->m_ptr;
		
		this->m_ptr = temp;
	}
	
	/*
		vector<int> arr(5, 0);
		arr[0] = 10;
		int i = arr[0];
	*/

private:
	std::size_t m_size; // size_t is 8 byte unsined as size cannot be negative
	T* m_ptr;	
};

int main()
{
	MyVector<int> vint(5, 0);
	vint.push_back(1);
	
	vint[5] = 4;
	vint[0] = 10;
	for(int i = 0 ; i < vint.size(); ++i)
		cout << vint[i] << " " ;

	cout << endl;
	cout << "at = " << vint.at(5) << endl;

	cout << "at = " << vint.at(7) << endl;
	return 0;
}

/*
lvalue = who has or posses the address
rvalue = which do not contains the address
l = std::move(r)


int&& r_ref = std::move(i);

int arr = new arr[10] 

vector<int> vec;



1. default constructor
2. prameterised constructor
3. copy constructor
4. copy assignment operator
5. Move constructor
6. move assignment
7. push back
8. size
9. [] subscript operator
*/