//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <complex>

// template<class T>
//   complex<T>
//   cosh(const complex<T>& x);

#include <complex>
#include <cassert>

#include "../cases.h"

template <class T>
void
test(const std::complex<T>& c, std::complex<T> x)
{
    assert(cosh(c) == x);
}

template <class T>
void
test()
{
    test(std::complex<T>(0, 0), std::complex<T>(1, 0));
}

void test_edges()
{
    typedef std::complex<double> C;
    const double pi = std::atan2(+0., -0.);
    const unsigned N = sizeof(x) / sizeof(x[0]);
    for (unsigned i = 0; i < N; ++i)
    {
        std::complex<double> r = cosh(x[i]);
        if (x[i].real() == 0 && x[i].imag() == 0)
        {
            assert(r.real() == 1);
            assert(r.imag() == 0);
            assert(std::signbit(r.imag()) == std::signbit(x[i].imag()));
        }
        else if (x[i].real() == 0 && std::isinf(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(r.imag() == 0);
        }
        else if (x[i].real() == 0 && std::isnan(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(r.imag() == 0);
        }
        else if (std::isfinite(x[i].real()) && std::isinf(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(std::isnan(r.imag()));
        }
        else if (std::isfinite(x[i].real()) && std::isnan(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(std::isnan(r.imag()));
        }
        else if (std::isinf(x[i].real()) && x[i].imag() == 0)
        {
            assert(std::isinf(r.real()));
            assert(!std::signbit(r.real()));
            assert(r.imag() == 0);
            assert(std::signbit(r.imag()) == std::signbit(x[i].imag()));
        }
        else if (std::isinf(x[i].real()) && std::isfinite(x[i].imag()))
        {
            assert(std::isinf(r.real()));
            assert(std::signbit(r.real()) == std::signbit(cos(x[i].imag())));
            assert(std::isinf(r.imag()));
            assert(std::signbit(r.imag()) == std::signbit(x[i].real() * sin(x[i].imag())));
        }
        else if (std::isinf(x[i].real()) && std::isinf(x[i].imag()))
        {
            assert(std::isinf(r.real()));
            assert(std::isnan(r.imag()));
        }
        else if (std::isinf(x[i].real()) && std::isnan(x[i].imag()))
        {
            assert(std::isinf(r.real()));
            assert(r.real() > 0);
            assert(std::isnan(r.imag()));
        }
        else if (std::isnan(x[i].real()) && x[i].imag() == 0)
        {
            assert(std::isnan(r.real()));
            assert(r.imag() == 0);
        }
        else if (std::isnan(x[i].real()) && std::isfinite(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(std::isnan(r.imag()));
        }
        else if (std::isnan(x[i].real()) && std::isnan(x[i].imag()))
        {
            assert(std::isnan(r.real()));
            assert(std::isnan(r.imag()));
        }
    }
}

int main()
{
    test<float>();
    test<double>();
    test<long double>();
    test_edges();
}
