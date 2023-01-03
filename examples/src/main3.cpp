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

    Ratio<int> c(121,256);
    std::cout << "c = ";
    c.displayRatio();
    std::cout << "qrt(c) = " << c.ratio_sqrt() << std::endl;
   

    Ratio<long int> d(8,3);
    std::cout << "d = ";
    d.displayRatio();
    std::cout << "exp(d) = " << d.ratio_exp() << std::endl;


    Ratio<int> e(4,3);
    std::cout << "e = ";
    e.displayRatio();

    std::cout << "sin(e) = " << e.ratio_sin() << std::endl;

    Ratio<int> f(3,2);
    std::cout << "f = ";
    f.displayRatio();
    std::cout << "cos(f) = " << f.ratio_cos() << std::endl;
  

}

