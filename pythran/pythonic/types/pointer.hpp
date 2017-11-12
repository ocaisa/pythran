#ifndef PYTHONIC_TYPES_SET_HPP
#define PYTHONIC_TYPES_SET_HPP

#include "pythonic/include/types/pointer.hpp"

namespace pythonic
{

  namespace types
  {

    template <class T>
    typename pointer<T>::reference pointer<T>::operator[](long i)
    {
      return data[i];
    }

    template <class T>
    typename pointer<T>::value_type pointer<T>::operator[](long i) const
    {
      return data[i];
    }

    template <class T>
    typename pointer<T>::reference pointer<T>::fast(long i)
    {
      return data[i];
    }

    template <class T>
    typename pointer<T>::value_type pointer<T>::fast(long i) const
    {
      return data[i];
    }
  }
}

namespace std
{
  template <size_t I, class T>
  typename pythonic::types::pointer<T>::reference
  get(pythonic::types::pointer<T> &t)
  {
    return t[I];
  }

  template <size_t I, class T>
  typename pythonic::types::pointer<T>::value_type
  get(pythonic::types::pointer<T> const &t)
  {
    return t[I];
  }

  template <size_t I, class T>
  typename pythonic::types::pointer<T>::value_type
  get(pythonic::types::pointer<T> &&t)
  {
    return t[I];
  }
}

#ifdef ENABLE_PYTHON_MODULE

namespace pythonic
{

  template <typename T>
  PyObject *to_python<types::pointer<T>>::convert(types::pointer<T> const &v)
  {
    return nullptr;
  }

  template <class T>
  bool from_python<types::pointer<T>>::is_convertible(PyObject *obj)
  {
    return false;
  }
  template <class T>
  types::pointer<T> from_python<types::pointer<T>>::convert(PyObject *obj)
  {
    return {nullptr};
  }
}

#endif

#endif
