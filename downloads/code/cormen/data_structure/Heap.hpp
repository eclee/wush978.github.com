#include <vector>
#include <boost/shared_ptr.hpp>
#include "cormen.h"
#include "data_structure/Array.hpp"

namespace cormen {

	namespace data_structure {

		template<class _T>
		class Heap {
			boost::shared_ptr<Array<_T> > _array;
		public:
			Heap(const Count size, const _T& src) : _array(new Array<_T>(size, src)) { }
			Heap(const Heap& src) : _array(src._array) { }
			Heap(_T* src, const Count size) : _array(new Array<_T>(src, size)) { }
			~Heap() { }
			
			/**
			 * data interfaces
			 */
			void operator=(const Heap& src) { _array = src._array; }
			_T& operator[](const Index index) { return _array->get(index); }
			const size_t size() { return _array->size(); }
			_T* getRootPtr() { return &(_array->get(0)); }
			void setSize(Count size) { _array->setSize(size); }

			/**
			 * Cormen 6.3
			 */
			void heapify() {
				if (!this->size()) {
					return;
				}
				for(Index i( (this->size() - 1) / 2 + 1 ); i > 0;) {
					this->heapify(--i);
				}
			}

			static const Index parent(const Index src) { return (src - 1)/2; }
			static const Index left(const Index src) { return 2 * src + 2; }
			static const Index right(const Index src) { return 2 * src + 1; }
		private:
			/**
			 * Cormen 6.2
			 * Requirement: left(i) and right(i) are root of 2 heap subtree
			 * ( satisfying heap property )
			 */
			void heapify(Index i) {
				Heap<_T>& A(*this);
				Index
					l = Heap<_T>::left(i),
					r = Heap<_T>::right(i);
				Index largest;
				if (l < A._array->size() & A[l] > A[i])
					largest = l;
				else
					largest = i;
				if (r < A._array->size() & A[r] > A[largest])
					largest = r;
				if (largest != i) {
					_T temp(A[i]);
					A[i] = A[largest];
					A[largest] = temp;
					A.heapify(largest);
				}
			}
		};
	}

}
