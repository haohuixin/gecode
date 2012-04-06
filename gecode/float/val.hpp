/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Vincent Barichard <Vincent.Barichard@univ-angers.fr>
 *
 *  Contributing authors:
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Christian Schulte, 2012
 *     Vincent Barichard, 2012
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

namespace Gecode {

  /*
   * Floating point value: member functions
   *
   */
  forceinline
  FloatVal::FloatVal(void) {}
  forceinline
  FloatVal::FloatVal(const FloatNum& n) : x(n) {}
  forceinline
  FloatVal::FloatVal(const FloatNum& l, const FloatNum& u) : x(l,u) {}
  forceinline
  FloatVal::FloatVal(const FloatValImpType& i) : x(i) {}
  forceinline
  FloatVal::FloatVal(const FloatVal& v) : x(v.x) {}

  forceinline FloatVal&
  FloatVal::operator =(const FloatNum& n) {
    x = n; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator =(const FloatVal& v) {
    x = v.x; return *this;
  }
    
  forceinline void
  FloatVal::assign(FloatNum const &l, FloatNum const &u) {
    x.assign(l,u);
  }

  forceinline FloatNum
  FloatVal::lower(void) const {
    return x.lower();
  }
  forceinline FloatNum
  FloatVal::upper(void) const {
    return x.upper();
  }
  forceinline FloatNum
  FloatVal::width(void) const {
    return boost::numeric::width(x);
  }
  forceinline FloatNum
  FloatVal::median(void) const {
    return boost::numeric::median(x);
  }

  forceinline bool
  FloatVal::singleton(void) const {
    return boost::numeric::singleton(x);
  }
  forceinline bool
  FloatVal::in(FloatNum n) const {
    return boost::numeric::in(n,x);
  }
  forceinline bool
  FloatVal::zero_in(void) const {
    return boost::numeric::zero_in(x);
  }
    
  forceinline FloatVal
  FloatVal::hull(FloatNum x, FloatNum y) {
    FloatVal h(FloatVal::hull(x,y)); return h;
  }
  forceinline FloatVal
  FloatVal::pi_half(void) {
    FloatVal p(boost::numeric::interval_lib::pi_half<FloatValImpType>());
    return p;
  }
  forceinline FloatVal
  FloatVal::pi(void) {
    FloatVal p(boost::numeric::interval_lib::pi<FloatValImpType>());
    return p;
  }
  forceinline FloatVal
  FloatVal::pi_twice(void) {
    FloatVal p(boost::numeric::interval_lib::pi_twice<FloatValImpType>());
    return p;
  }
    
  forceinline FloatVal&
  FloatVal::operator +=(const FloatNum& n) {
    x += n; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator -=(const FloatNum& n) {
    x -= n; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator *=(const FloatNum& n) {
    x *= n; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator /=(const FloatNum& n) {
    x /= n; return *this;
  }

  forceinline FloatVal&
  FloatVal::operator +=(const FloatVal& v) {
    x += v.x; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator -=(const FloatVal& v) {
    x -= v.x; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator *=(const FloatVal& v) {
    x *= v.x; return *this;
  }
  forceinline FloatVal&
  FloatVal::operator /=(const FloatVal& v) {
    x /= v.x; return *this;
  }

  /*
   * Operators and functions on float values
   *
   */

//   /* arithmetic operators involving intervals */
  forceinline FloatVal
  operator+(const FloatVal& x) {
    return FloatVal(+x.x);
  }
  forceinline FloatVal
  operator-(const FloatVal& x) {
    return FloatVal(-x.x);
  }
  forceinline FloatVal
  operator+(const FloatVal& x, const FloatVal& y) {
    return FloatVal(x.x+y.x);
  }
  forceinline FloatVal
  operator+(const FloatVal& x, const FloatNum& y) {
    return FloatVal(x.x+y);
  }
  forceinline FloatVal
  operator+(const FloatNum& x, const FloatVal& y) {
    return FloatVal(x+y.x);
  }

  forceinline FloatVal
  operator-(const FloatVal& x, const FloatVal& y) {
    return FloatVal(x.x-y.x);
  }
  forceinline FloatVal
  operator-(const FloatVal& x, const FloatNum& y) {
    return FloatVal(x.x-y);
  }
  forceinline FloatVal
  operator-(const FloatNum& x, const FloatVal& y) {
    return FloatVal(x-y.x);
  }

  forceinline FloatVal
  operator*(const FloatVal& x, const FloatVal& y) {
    return FloatVal(x.x*y.x);
  }
  forceinline FloatVal
  operator*(const FloatVal& x, const FloatNum& y) {
    return FloatVal(x.x*y);
  }
  forceinline FloatVal
  operator*(const FloatNum& x, const FloatVal& y) {
    return FloatVal(x*y.x);
  }

  forceinline FloatVal
  operator/(const FloatVal& x, const FloatVal& y) {
    return FloatVal(x.x/y.x);
  }
  forceinline FloatVal
  operator/(const FloatVal& x, const FloatNum& y) {
    return FloatVal(x.x/y);
  }
  forceinline FloatVal
  operator/(const FloatNum& x, const FloatVal& y) {
    return FloatVal(x/y.x);
  }

  forceinline FloatVal
  abs(const FloatVal& x) {
    return FloatVal(abs(x.x));
  }
  forceinline FloatVal
  sqrt(const FloatVal& x) {
    return FloatVal(sqrt(x.x));
  }
  forceinline FloatVal
  square(const FloatVal& x) {
    return FloatVal(square(x.x));
  }
  forceinline FloatVal
  pow(const FloatVal& x, int n) {
    return FloatVal(pow(x.x,n));
  }
  forceinline FloatVal
  nth_root(const FloatVal& x, int n) {
    return FloatVal(nth_root(x.x,n));
  }

#ifdef GECODE_HAS_MPFR

  forceinline FloatVal
  exp(const FloatVal& x) {
    return FloatVal(exp(x.x));
  }
  forceinline FloatVal
  log(const FloatVal& x) {
    return FloatVal(log(x.x));
  }

  forceinline FloatVal
  fmod(const FloatVal& x, const FloatVal& y) {
    return FloatVal(fmod(x.x,y.x));
  }
  forceinline FloatVal
  fmod(const FloatVal& x, const FloatNum& y) {
    return FloatVal(fmod(x.x,y));
  }
  forceinline FloatVal
  fmod(const FloatNum& x, const FloatVal& y) {
    return FloatVal(fmod(x,y.x));
  }

  forceinline FloatVal
  sin(const FloatVal& x) {
    return FloatVal(sin(x.x));
  }
  forceinline FloatVal
  cos(const FloatVal& x) {
    return FloatVal(cos(x.x));
  }
  forceinline FloatVal
  tan(const FloatVal& x) {
    return FloatVal(tan(x.x));
  }
  forceinline FloatVal
  asin(const FloatVal& x) {
    return FloatVal(asin(x.x));
  }
  forceinline FloatVal
  acos(const FloatVal& x) {
    return FloatVal(acos(x.x));
  }
  forceinline FloatVal
  atan(const FloatVal& x) {
    return FloatVal(atan(x.x));
  }

  forceinline FloatVal
  sinh(const FloatVal& x) {
    return FloatVal(sinh(x.x));
  }
  forceinline FloatVal
  cosh(const FloatVal& x) {
    return FloatVal(cosh(x.x));
  }
  forceinline FloatVal
  tanh(const FloatVal& x) {
    return FloatVal(tanh(x.x));
  }
  forceinline FloatVal
  asinh(const FloatVal& x) {
    return FloatVal(asinh(x.x));
  }
  forceinline FloatVal
  acosh(const FloatVal& x) {
    return FloatVal(acosh(x.x));
  }
  forceinline FloatVal
  atanh(const FloatVal& x) {
    return FloatVal(atanh(x.x));
  }

#endif

  forceinline FloatVal
  max(const FloatVal& x, const FloatVal& y) {
    return FloatVal(max(x.x,y.x));
  }
  forceinline FloatVal
  max(const FloatVal& x, const FloatNum& y) {
    return FloatVal(max(x.x,y));
  }
  forceinline FloatVal
  max(const FloatNum& x, const FloatVal& y) {
    return FloatVal(max(x,y.x));
  }
  forceinline FloatVal
  min(const FloatVal& x, const FloatVal& y) {
    return FloatVal(min(x.x,y.x));
  }
  forceinline FloatVal
  min(const FloatVal& x, const FloatNum& y) {
    return FloatVal(min(x.x,y));
  }
  forceinline FloatVal
  min(const FloatNum& x, const FloatVal& y) {
    return FloatVal(min(x,y.x));
  }

  forceinline bool
  subset(const FloatVal& x, const FloatVal& y) {
    return subset(x.x,y.x);
  }
  forceinline bool
  proper_subset(const FloatVal& x, const FloatVal& y) {
    return proper_subset(x.x,y.x);
  }
  forceinline bool
  overlap(const FloatVal& x, const FloatVal& y) {
    return overlap(x.x,y.x);
  }

  forceinline FloatVal
  intersect(const FloatVal& x, const FloatVal& y) {
    return FloatVal(intersect(x.x,y.x));
  }
  forceinline FloatVal
  hull(const FloatVal& x, const FloatVal& y) {
    return FloatVal(hull(x.x,y.x));
  }
  forceinline FloatVal
  hull(const FloatVal& x, const FloatNum& y) {
    return FloatVal(hull(x.x,y));
  }
  forceinline FloatVal
  hull(const FloatNum& x, const FloatVal& y) {
    return FloatVal(hull(x,y.x));
  }
  forceinline FloatVal
  hull(const FloatNum& x, const FloatNum& y) {
    return FloatVal(hull(x,y));
  }

  forceinline bool
  operator <(const FloatVal& x, const FloatVal& y) {
    return x.x < y.x;
  }
  forceinline bool
  operator <(const FloatVal& x, const FloatNum& y) {
    return x.x < y;
  }

  forceinline bool
  operator <=(const FloatVal& x, const FloatVal& y) {
    return x.x <= y.x;
  }
  forceinline bool
  operator <=(const FloatVal& x, const FloatNum& y) {
    return x.x <= y;
  }

  forceinline bool
  operator >(const FloatVal& x, const FloatVal& y) {
    return x.x > y.x;
  }
  forceinline bool
  operator >(const FloatVal& x, const FloatNum& y) {
    return x.x > y;
  }

  forceinline bool
  operator >=(const FloatVal& x, const FloatVal& y) {
    return x.x >= y.x;
  }
  forceinline bool
  operator >=(const FloatVal& x, const FloatNum& y) {
    return x.x >= y;
  }

  forceinline bool
  operator ==(const FloatVal& x, const FloatVal& y) {
    return x.x == y.x;
  }
  forceinline bool
  operator ==(const FloatVal& x, const FloatNum& y) {
    return x.x == y;
  }

  forceinline bool
  operator !=(const FloatVal& x, const FloatVal& y) {
    return x.x != y.x;
  }
  forceinline bool
  operator !=(const FloatVal& x, const FloatNum& y) {
    return x.x != y;
  }

  forceinline bool
  operator <(const FloatNum& x, const FloatVal& y) {
    return y > x;
  }
  forceinline bool
  operator <=(const FloatNum& x, const FloatVal& y) {
    return y >= x;
  }
  forceinline bool
  operator >(const FloatNum& x, const FloatVal& y) {
    return y < x;
  }
  forceinline bool
  operator >=(const FloatNum& x, const FloatVal& y) {
    return y <= x;
  }
  forceinline bool
  operator ==(const FloatNum& x, const FloatVal& y) {
    return y == x;
  }
  forceinline bool
  operator !=(const FloatNum& x, const FloatVal& y) {
    return y != x;
  }

  template<class Char, class Traits>
  std::basic_ostream<Char,Traits>&
  operator <<(std::basic_ostream<Char,Traits>& os, const FloatVal& x) {
    return os << x.x;
  }

}

// STATISTICS: float-var

