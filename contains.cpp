#ifndef __CONTAINS_H__
#define __CONTAINS_H__

namespace std_plus {


	template<class C, class T>
	auto contains(const C& v, const T& x)
	-> decltype(end(v), true) {
		return end(v) != std::find(begin(v), end(v), x);
	}

}
#endif