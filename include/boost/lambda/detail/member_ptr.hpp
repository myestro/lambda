// Boost Lambda Library -- member_ptr.hpp ---------------------

// Copyright (C) 1999, 2000 Jaakko J�rvi (jaakko.jarvi@cs.utu.fi)
// Copyright (C) 2000 Gary Powell (gary.powell@sierra.com)
//
// Permission to copy, use, sell and distribute this software is granted
// provided this copyright notice appears in all copies. 
// Permission to modify the code and to distribute modified code is granted
// provided this copyright notice appears in all copies, and a notice 
// that the code was modified is included with the copyright notice.
//
// This software is provided "as is" without express or implied warranty, 
// and with no claim as of its suitability for any purpose.
//
// For more information, see www.boost.org

// --------------------------------------------------------------------------

#if !defined(BOOST_LAMBDA_MEMBER_PTR_HPP)
#define BOOST_LAMBDA_MEMBER_PTR_HPP

namespace boost { 
namespace lambda {

namespace detail {

// the boost type_traits member_pointer traits are not enough, 
// need to know more details.
template<class T>
struct member_pointer {
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = false);
};

template<class T, class U>
struct member_pointer<T U::*> {
  typedef typename boost::add_reference<T>::type type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = true);
  BOOST_STATIC_CONSTANT(bool, is_function_member = false);
};

template<class T, class U>
struct member_pointer<const T U::*> {
  typedef typename boost::add_reference<const T>::type type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = true);
  BOOST_STATIC_CONSTANT(bool, is_function_member = false);
};

template<class T, class U>
struct member_pointer<volatile T U::*> {
  typedef typename boost::add_reference<volatile T>::type type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = true);
  BOOST_STATIC_CONSTANT(bool, is_function_member = false);
};

template<class T, class U>
struct member_pointer<const volatile T U::*> {
  typedef typename boost::add_reference<const volatile T>::type type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = true);
  BOOST_STATIC_CONSTANT(bool, is_function_member = false);
};

// -- nonconst member functions --
template<class T, class U>
struct member_pointer<T (U::*)()> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1>
struct member_pointer<T (U::*)(A1)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2>
struct member_pointer<T (U::*)(A1, A2)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3>
struct member_pointer<T (U::*)(A1, A2, A3)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4>
struct member_pointer<T (U::*)(A1, A2, A3, A4)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8, class A9>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9)> {
  typedef T type;
  typedef U class_type;
  typedef U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
// -- const member functions --
template<class T, class U>
struct member_pointer<T (U::*)() const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1>
struct member_pointer<T (U::*)(A1) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2>
struct member_pointer<T (U::*)(A1, A2) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3>
struct member_pointer<T (U::*)(A1, A2, A3) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4>
struct member_pointer<T (U::*)(A1, A2, A3, A4) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8, class A9>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const> {
  typedef T type;
  typedef U class_type;
  typedef const U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
  // -- volatile --
template<class T, class U>
struct member_pointer<T (U::*)() volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1>
struct member_pointer<T (U::*)(A1) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2>
struct member_pointer<T (U::*)(A1, A2) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3>
struct member_pointer<T (U::*)(A1, A2, A3) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4>
struct member_pointer<T (U::*)(A1, A2, A3, A4) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8, class A9>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) volatile> {
  typedef T type;
  typedef U class_type;
  typedef volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
  // -- const volatile
template<class T, class U>
struct member_pointer<T (U::*)() const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1>
struct member_pointer<T (U::*)(A1) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2>
struct member_pointer<T (U::*)(A1, A2) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3>
struct member_pointer<T (U::*)(A1, A2, A3) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4>
struct member_pointer<T (U::*)(A1, A2, A3, A4) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};
template<class T, class U, class A1, class A2, class A3, class A4, class A5,
         class A6, class A7, class A8, class A9>
struct member_pointer<T (U::*)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const volatile> {
  typedef T type;
  typedef U class_type;
  typedef const volatile U qualified_class_type;
  BOOST_STATIC_CONSTANT(bool, is_data_member = false);
  BOOST_STATIC_CONSTANT(bool, is_function_member = true);
};

} // detail

namespace detail {

  // this class holds a pointer to a member function and the object.
  // when called, it just calls the member function with the parameters 
  // provided

  // It would have been possible to use existing lambda_functors to represent
  // a bound member function like this, but to have a separate template is 
  // safer, since now this functor doesn't mix and match with lambda_functors
  // only thing you can do with this is to call it

  // note that previously instantiated classes 
  // (other_action<member_pointer_action> and member_pointer_action_helper
  // guarantee, that A and B are 
  // such types, that for objects a and b of corresponding types, a->*b leads 
  // to the builtin ->* to be called. So types that would end in a  call to 
  // a user defined ->* do not create a member_pointer_caller object.

template<class RET, class A, class B>
class member_pointer_caller {
  A a;
  B b;
public:
  member_pointer_caller(A aa, B bb) : a(aa), b(bb) {}

  RET operator()() const { return (a->*b)(); } 

  template<class A1>
  RET operator()(const A1& a1) const { return (a->*b)(a1); } 

  template<class A1, class A2>
  RET operator()(const A1& a1, const A2& a2) const { return (a->*b)(a1, a2); } 

  template<class A1, class A2, class A3>
  RET operator()(const A1& a1, const A2& a2, const A3& a3) const { 
    return (a->*b)(a1, a2, a3); 
  } 

  template<class A1, class A2, class A3, class A4>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, 
                 const A4& a4) const { 
    return (a->*b)(a1, a2, a3, a4); 
  } 

  template<class A1, class A2, class A3, class A4, class A5>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, const A4& a4, 
                 const A5& a5) const { 
    return (a->*b)(a1, a2, a3, a4, a5); 
  } 

  template<class A1, class A2, class A3, class A4, class A5, class A6>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, const A4& a4, 
                 const A5& a5, const A6& a6) const { 
    return (a->*b)(a1, a2, a3, a4, a5, a6); 
  } 

  template<class A1, class A2, class A3, class A4, class A5, class A6, 
           class A7>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, const A4& a4, 
                 const A5& a5, const A6& a6, const A7& a7) const { 
    return (a->*b)(a1, a2, a3, a4, a5, a6, a7); 
  } 

  template<class A1, class A2, class A3, class A4, class A5, class A6, 
           class A7, class A8>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, const A4& a4, 
                 const A5& a5, const A6& a6, const A7& a7,
                 const A8& a8) const { 
    return (a->*b)(a1, a2, a3, a4, a5, a6, a7, a8); 
  } 

  template<class A1, class A2, class A3, class A4, class A5, class A6, 
           class A7, class A8, class A9>
  RET operator()(const A1& a1, const A2& a2, const A3& a3, const A4& a4, 
                 const A5& a5, const A6& a6, const A7& a7,
                 const A8& a8, const A9& a9) const { 
    return (a->*b)(a1, a2, a3, a4, a5, a6, a7, a8, a9); 
  } 

};

// helper templates for return type deduction and action classes
// different cases for data member, function member, neither

// true-true case
template <bool Is_data_member, bool Is_function_member>
struct member_pointer_action_helper;
  // cannot be both, no body provided

  // data member case
template <>
struct member_pointer_action_helper<true, false> {
public:
  template<class RET, class A, class B>
  static RET apply(A& a, B& b) { 
    return a->*b; 
  }

  template<class A, class B>
  struct return_type {

    typedef typename detail::remove_reference_and_cv<B>::type plainB;

    typedef typename detail::member_pointer<plainB>::type type1;

    // A is a pointer type
    typedef typename ::boost::remove_pointer<A>::type non_pointer_A; 

    // For non-reference types, we must add const and/or volatile if
    // the pointer type has these qualifiers
    // If the member is a reference, these do not have any effect
    //   (cv T == T if T is a reference type)
    typedef typename detail::IF<
      ::boost::is_const<non_pointer_A>::value, 
      typename ::boost::add_const<type1>::type,
      type1
    >::RET type2;
    typedef typename detail::IF<
      ::boost::is_volatile<non_pointer_A>::value, 
      typename ::boost::add_volatile<type2>::type,
      type2
    >::RET type3;
    typedef typename ::boost::add_reference<type3>::type type;
  };
};

  // neither case
template <>
struct member_pointer_action_helper<false, false> {
public:
  template<class RET, class A, class B>
  static RET apply(A& a, B& b) { 
// not a built in member pointer operator, just call ->*
    return a->*b; 
  }
  // an overloaded member pointer operators, user should have specified
  // the return type
  template<class A, class B>
  struct return_type {
    typedef typename 
      detail::generate_error<A>::return_type_not_specified type; 
  };
  
};


// member pointer function case
// This is a built in ->* call for a member function, 
// the only thing that you can do with that, is to give it some arguments
template <>
struct member_pointer_action_helper<false, true> {
  public:

  template<class RET, class A, class B>
  static RET apply(A& a, B& b) { 

    typedef typename ::boost::remove_cv<B>::type plainB;
    typedef typename detail::member_pointer<plainB>::type ret_t; 

    return detail::member_pointer_caller<ret_t, A&, B&>(a, b); 
  }

  template<class A, class B>
  struct return_type {
    typedef typename detail::remove_reference_and_cv<B>::type plainB;
    typedef typename detail::member_pointer<plainB>::type ret_t; 
    typedef detail::member_pointer_caller<ret_t, A, B> type;  
  };
};

} // detail

class member_pointer_action {};

template<> class other_action<member_pointer_action>  {
public:
  template<class RET, class A, class B>
  static RET apply(A& a, B& b) {

    typedef typename 
      ::boost::remove_cv<B>::type plainB;

    return 
      detail::member_pointer_action_helper<
        detail::member_pointer<plainB>::is_data_member,
        detail::member_pointer<plainB>::is_function_member
      >::template apply<RET>(a, b); 
    }
};

  // return type deduction --

  // If the right argument is a pointer to data member, 
  // and the left argument is of compatible pointer to class type
  // return type is a reference to the data member type

  // if right argument is a pointer to a member function, and the left 
  // argument is of a compatible type, the return type is a 
  // member_pointer_caller (see above)

  // Otherwise, return type deduction fails. There is either an error, 
  // or the user is trying to call an overloaded ->*
  // In such a case either ret<> must be used, or a return_type_2 user 
  // defined specialization must be provided

template<class A, class B>
struct return_type_2<other_action<member_pointer_action>, A, B> {

  typedef typename 
    detail::remove_reference_and_cv<B>::type plainB;
  typedef typename
    detail::member_pointer<plainB>::qualified_class_type B_class;

  typedef typename 
    detail::member_pointer_action_helper<
      detail::member_pointer<plainB>::is_data_member,
      detail::member_pointer<plainB>::is_function_member
    >::template return_type<A, B>::type type; 
};


template<class Arg1, class Arg2>
inline const
lambda_functor<
  lambda_functor_args<
    action<2, other_action<member_pointer_action> >,
    tuple<lambda_functor<Arg1>, typename const_copy_argument<Arg2>::type>,
    combine_arities<Arg1, Arg2>::value
  >
>
operator->*(const lambda_functor<Arg1>& a1, const Arg2& a2)
{
  return 
    lambda_functor<
      lambda_functor_args<
        action<2, other_action<member_pointer_action> >,
        tuple<lambda_functor<Arg1>, typename const_copy_argument<Arg2>::type>,
        combine_arities<Arg1, Arg2>::value
      >
    > (tuple<lambda_functor<Arg1>, 
             typename const_copy_argument<Arg2>::type>(a1, a2));
}

template<class Arg1, class Arg2>
inline const
lambda_functor<
  lambda_functor_args<
    action<2, other_action<member_pointer_action> >,
    tuple<lambda_functor<Arg1>, lambda_functor<Arg2> >,
    combine_arities<Arg1, Arg2>::value
  >
>
operator->*(const lambda_functor<Arg1>& a1, const lambda_functor<Arg2>& a2)
{
  return 
    lambda_functor<
      lambda_functor_args<
        action<2, other_action<member_pointer_action> >,
        tuple<lambda_functor<Arg1>, lambda_functor<Arg2> >,
        combine_arities<Arg1, Arg2>::value
      >
    > (tuple<lambda_functor<Arg1>, lambda_functor<Arg2> >(a1, a2));
}

template<class Arg1, class Arg2>
inline const
lambda_functor<
  lambda_functor_args<
    action<2, other_action<member_pointer_action> >,
    tuple<typename const_copy_argument<Arg1>::type, lambda_functor<Arg2> >,
    combine_arities<Arg1, Arg2>::value
  >
>
operator->*(const Arg1& a1, const lambda_functor<Arg2>& a2)
{
  return 
    lambda_functor<
      lambda_functor_args<
        action<2, other_action<member_pointer_action> >,
        tuple<typename const_copy_argument<Arg1>::type, lambda_functor<Arg2> >,
        combine_arities<Arg1, Arg2>::value
      >
    > (tuple<typename const_copy_argument<Arg1>::type, 
             lambda_functor<Arg2> >(a1, a2));
}


} // namespace lambda 
} // namespace boost


#endif





