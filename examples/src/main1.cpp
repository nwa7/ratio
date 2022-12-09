#include <iostream>
#include "ratio.hpp"
#include <cmath>

int main() {

    Ratio a(1,2);
    std::cout << "a = "; 
    a.displayRatio();

    Ratio a_copy(a);
    std::cout << "a_copy = "; 
    a_copy.displayRatio();

    Ratio b(3,4);
    std::cout << "b = ";
    b.displayRatio();

    Ratio c = a + b;
    std::cout << "a + b = "; 
    c.displayRatio();

    Ratio d = a - b;
    std::cout << "a - b = "; 
    d.displayRatio();

    Ratio e = a*b; 
    std::cout << "a * b = "; 
    e.displayRatio();

    Ratio f = a/b;
    std::cout << "a / b = ";
    f.displayRatio();

    Ratio g(8,6);
    std::cout << "8/6 = ";
    g.reduce();
    g.displayRatio();

    Ratio h(15,11);
    std::cout << "15/11 = ";
    h.reduce();
    h.displayRatio();

    Ratio i = - a;
    std::cout << "-a = ";
    i.displayRatio();

    Ratio j = a.inverse();
    std::cout << "1/a = ";
    j.displayRatio();

    Ratio k(-2,5);
    std::cout << "k = "; 
    k.displayRatio();
    Ratio l = k.ratio_abs();
    std::cout << "abs(k) = ";
    l.displayRatio();

    Ratio m(-7,2);
    std::cout << "m = "; 
    m.displayRatio();
    std::cout << "|m| = " << m.ratio_intpart() << std::endl;


    return 0;
}
