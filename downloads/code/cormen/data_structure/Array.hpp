/*
 * Array.hpp
 *
 *  Created on: Jun 20, 2012
 *      Author: wush
 */

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include "cormen.h"

namespace cormen {
	namespace data_structure {

		template<class _T>
		class Array {
			_T* _array;
			Count _size;
			bool _is_new;
		public:
			Array(const Count size) : _array(new _T[size]), _size(size), _is_new(true) { }
			Array(const Count size, const _T& src) : _array(new _T[size]), _size(size), _is_new(true) {
				for (Index i = 0;i < size;i++) {
					*(_array + i) = src;
				}
			}
			/**
			 * The pointer src must not be deleted before any access of Array object
			 */
			Array(_T* src, const Count size) : _array(src), _size(size), _is_new(false) { }
			~Array() {
				if (_is_new)
					delete [] _array;
			}
			_T& get(const Index size) { return _array[size]; }
			const Count size() { return _size; }
			void setSize(Count size) { _size = size; }
		private:
			Array(const Array& src);
			void operator=(const Array& src);
		};

	}
}


#endif /* ARRAY_HPP_ */
