#ifndef __VEC_H__
#define __VEC_H__

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

namespace util_vec {

	template<class C, class T>
	auto contains(const C& v, const T& x)-> decltype(end(v), true) {
		return end(v) != std::find(begin(v), end(v), x);
	}


	template <class T>
	std::string join( const std::vector<T>& v, const std::string& token ) {
		std::ostringstream result;
		for (typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); i++) {
			if (i != v.begin()) { result << token; }
			result << *i;
		}
		return result.str();
	}


}
#endif