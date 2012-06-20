/*
 * HeapSort.hpp
 *
 *  Created on: Jun 20, 2012
 *      Author: wush
 */

#ifndef HEAPSORT_HPP_
#define HEAPSORT_HPP_

#include "data_structure/Heap.hpp"

namespace cormen {
	namespace sorting {
		template<class _T>
		void heap_sort(_T* start, Count size) {
			if (!size)
				return;
			cormen::data_structure::Heap<_T> heap(start, size);
			heap.heapify();
			_T swap;
			for( Index i(size);i > 0; ) {
				swap = heap[0];
				heap[0] = heap[--i];
				heap[i] = swap;
				heap.setSize(--size);
				heap.heapify();
			}
		}

	}
}
#endif /* HEAPSORT_HPP_ */
