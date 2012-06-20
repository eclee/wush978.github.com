/*
 * HeapSort.cpp
 *
 *  Created on: Jun 20, 2012
 *      Author: wush
 */

#include <iostream>
#include <sorting/HeapSort.hpp>

using namespace std;

class B {
	int b;
public:
	B() : b(0) { }
	B(int src) : b(src) { }
	virtual ~B() { }

	void set(int src) { b = src; }
	int get() { return b; }
	bool operator>(const B& src) { return b > src.b; }

	B(const B& src) : b(src.b) { }
	void operator=(const B& src) { b = src.b; }
};

int main() {
	cout << "heap_sort unit test" << endl;
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	B* b(new B[10]);
	for(int i(0);i < 10;i++) {
		b[i].set(A[i]);
	}
	cormen::sorting::heap_sort<B>(b, 10);
	for(int i(0);i < 10;i++) {
		cout << b[i].get() << ",";
	}
	cout << endl;
	return 0;
}


