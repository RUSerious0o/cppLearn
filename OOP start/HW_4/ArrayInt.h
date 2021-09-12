#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert>

class ArrayInt {
public:
    ArrayInt();
	ArrayInt(int);

    ~ArrayInt();
	
	int& operator[](int);
	
	int getLength();
	void erase();	    
    void resize(int);
    void insertBefore(int, int);	
	ArrayInt& push_back(int);
	// 4.1
	ArrayInt& pop_back();
	ArrayInt& pop_front();
	void sort();
	void print() const;
	
private:
    int m_length;
    int *m_data;
	int deletedCount = 0;
	const int SHRINK_LINE = 5;
	
	void shrink();
};

#include "ArrayInt.cpp"
#endif

