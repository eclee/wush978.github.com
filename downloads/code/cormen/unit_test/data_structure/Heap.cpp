/*
 * Heap.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: wush
 */
#include <cstring>
#include <iostream>
#include <data_structure/Heap.hpp>

using namespace std;
using namespace cormen::data_structure;

template<class _T>
ostream& operator<<(ostream& os, Heap<_T>& A) {
	for (int i = 0;i < A.size();) {
		os << A[i++];
		if (i != A.size())
			os << ",";
	}
	return os;
}

int main(int argc, char* argv[]) {
	cout << Heap<int>::parent(5) << endl;
	cout << Heap<int>::parent(6) << endl;
	cout << Heap<int>::left(7) << endl;
	cout << Heap<int>::left(8) << endl;
	cout << Heap<int>::right(9) << endl;
	cout << Heap<int>::right(10) << endl;
	int A[] = {27,17,3,16,13,10,1,5,7,12,4,8,9,0};
	Heap<int> heap_int(14,0);
	memcpy((void*) heap_int.getRootPtr(), (const void*) &A[0], 14 * sizeof(int));
	cout << heap_int << endl;
	heap_int.heapify();
	cout << heap_int << endl;
	return 0;
}

