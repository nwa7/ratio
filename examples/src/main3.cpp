#include <iostream>
#include "ratio.hpp"
#include "math.h"
#include <iomanip> 


//Ne pas suppr pour l'instant, sert à avoir le nombre de digits après la virgule d'un nombre flottant

/*int digits_number(double x){
    int count = 0; 
    while((int) x != x){
        x*=10;
        count++;
    }
    return count;
}*/


int main(){
 

    Ratio a(3.456);
    std::cout << "a = ";
    a.displayRatio();
    std::cout << "float a = ";
    std::cout << a.convert_to_float() << std::endl;

    Ratio b(-164,290);
    std::cout << "b = ";
    b.displayRatio();

    std::cout << "b*2=" << b*2<< std::endl;
    //std::cout << b*0.5<< std::endl; = soucis je planche dessus quand je peux

    Ratio b_pow = b.ratio_pow(3);
    std::cout << "Ratio::pow(b) = ";
    b_pow.displayRatio();

    Ratio b_pow2 = b.ratio_pow2(3);
    std::cout << "std::pow(b) = ";
    b_pow2.displayRatio();

    std::cout << b.ratio_exp() << std::endl;

    Ratio c(121,256);
    std::cout << "c = ";
    c.displayRatio();

    Ratio c_sqrt = c.ratio_sqrt();
    std::cout << "Ratio::sqrt(c) = ";
    c_sqrt.displayRatio();
    
    Ratio c_sqrt2 = c.ratio_sqrt2();
    std::cout << "std::sqrt(c) = ";
    c_sqrt2.displayRatio();

    Ratio d(8,3);
    std::cout << "d = ";
    d.displayRatio();

    Ratio d_exp = d.ratio_exp();
    std::cout << "Ratio::exp(d) = ";
    d_exp.displayRatio();
    
    Ratio d_exp2 = d.ratio_exp2();
    std::cout << "std::exp(d) = ";
    d_exp2.displayRatio();

    d_exp2 = d + c;
    d_exp2.displayRatio();

    Ratio e(7,2);
    std::cout << "e = ";
    e.displayRatio();

    Ratio e_sin = e.ratio_sin();
    std::cout << "Ratio::sin(e) = ";
    e_sin.displayRatio();


    Ratio e_sin2 = e.ratio_sin2();
    std::cout << "std::sin(e) = ";
    e_sin2.displayRatio();


    Ratio f(3,2);
    std::cout << "f = ";
    f.displayRatio();

    Ratio f_cos = f.ratio_cos();
    std::cout << "Ratio::cos(f) = ";
    f_cos.displayRatio();


    Ratio f_cos2 = f.ratio_cos2();
    std::cout << "std::cos2(f) = ";
    f_cos2.displayRatio();
}