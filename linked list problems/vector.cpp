#include <iostream>
using namespace std;

template < typename T >
class vector {
	vector();
	vector(int size, T value=T());
	private:
		T* m_data;
		T m_size;
		T m_capacity;	
};

template < typename T >
vector<T>::vector() :
	m_size(0),
	m_capacity(0),
	m_data(nullptr)
{  }

template < typename T>
vector<T>::vector(int size, T value) :
	m_size(size),
	m_capacity(size),
	m_data(new T[m_size])
{
	for (int i = 0; i < m_size; i++) {
		m_data[i] = value;
	}
}



int main()
{
	vector<int> vec;
	return 0;
}