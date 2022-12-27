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
    g.reduce();
    g.displayRatio();

    Ratio<int> h(15,11);
    std::cout << "15/11 = ";
    h.reduce();
    h.displayRatio();

    Ratio<int> i = - a;
    std::cout << "-a = ";
    i.displayRatio();

    Ratio<int> j = a.inverse();
    std::cout << "1/a = ";
    j.displayRatio();

    Ratio<int> k(-2,5);
    std::cout << "k = "; 
    k.displayRatio();

    Ratio<int> l = k.ratio_abs();
    std::cout << "abs(k) = ";
    l.displayRatio();

    Ratio<int> m(-7,2);
    std::cout << "m = "; 
    m.displayRatio();
    std::cout << "|m| = " << m.ratio_intpart() << std::endl;


    return 0;
}
