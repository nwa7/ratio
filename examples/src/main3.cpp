#include <iostream>
#include "ratio.hpp"
#include "math.h"
#include <iomanip> 

int main(){
 

    Ratio<int> a(0.333);
    std::cout << "a = " << a << std::endl;
    std::cout << "float a = " << a.convert_to_float() << std::endl;

    Ratio<int> b(-164,290);
    std::cout << "b = " << b << std::endl;
    std::cout << "b*2=" << b*2<< std::endl;
    std::cout << "b*2=" << 2*b<< std::endl;
    std::cout << "b*2.33333="<< b*2.33333<< std::endl;


    std::cout << "pow(b,3) = " << b.ratio_pow(3) << std::endl;
    std::cout << "std::pow(b,3) = " << b.ratio_pow2(3) << std::endl;
    

    Ratio<int> c(121,256);
    std::cout << "c = ";
    c.displayRatio();
    std::cout << "qrt(c) = " << c.ratio_sqrt() << std::endl;
    std::cout << "std::sqrt(c) = " << c.ratio_sqrt2() << std::endl;

    Ratio<long int> d(8,3);
    std::cout << "d = ";
    d.displayRatio();
    std::cout << "exp(d) = " << d.ratio_exp() << std::endl;
    std::cout << "std::exp(d) = " << d.ratio_exp2() << std::endl;

    Ratio<int> e(7,2);
    std::cout << "e = ";
    e.displayRatio();

    std::cout << "sin(e) = " << e.ratio_sin() << std::endl;
    std::cout << "std::sin(e) = " << e.ratio_sin2() << std::endl;

    Ratio<int> f(3,2);
    std::cout << "f = ";
    f.displayRatio();
    std::cout << "cos(f) = " << f.ratio_cos() << std::endl;
    std::cout << "std::cos(f) = " << f.ratio_cos() << std::endl;


}
