#include <iostream>
#include "ratio.hpp"
#include <cmath>

int main() {

    Ratio<int> a(1,2);
    std::cout << "a = "; 
    a.displayRatio();

    Ratio<int> a_copy(a);
    std::cout << "a_copy = "; 
    a_copy.displayRatio();

    Ratio<int> b(3,4);
    std::cout << "b = ";
    b.displayRatio();

    Ratio<int> c = a + b;
    std::cout << "a + b = "; 
    c.displayRatio();

    Ratio<int> d = a - b;
    std::cout << "a - b = "; 
    d.displayRatio();

    Ratio<int> e = a*b; 
    std::cout << "a * b = "; 
    e.displayRatio();

    Ratio<int> f = a/b;
    std::cout << "a / b = ";
    f.displayRatio();

    Ratio<int> g(8,6);
    std::cout << "8/6 = ";
    g.displayRatio();

    std::cout << "-a = " << -a << std::endl;
    std::cout << "1/a = " << a.inverse() << std::endl;
    
    Ratio<int> h(-2,5);
    std::cout << "h = " << h << std::endl;  
    std::cout << "|h| = " << h.ratio_abs() << std::endl;
 
    Ratio<int> i(-7,2);
    std::cout << "i = " << i << std::endl; 
    std::cout << "E(i) = " << i.ratio_intpart() << std::endl;

    Ratio <int> j(1,0);
    j.displayRatio();

    return 0;
}
