#ifndef __JOIN_H__
#define __JOIN_H__

namespace cpp_util {

     template <class T>
     string vector_join( const vector<T>& v, const string& token ) {
          ostringstream result;
          for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); i++) {
               if (i != v.begin()) { result << token; }
               result << *i;
          }
          return result.str();
     }
};
#endif