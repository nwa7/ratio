#include <iostream>
#include "ratio.hpp"
#include "math.h"
#include <iomanip> 
#include <limits>


/*int digits_nb(double x){
    int decimalPlaces = 0;
    x = std::abs(x);
    x = x - std::round(x);
    //x = x - (int) x;

    while (
        std::abs(x) - std::numeric_limits<float>::epsilon() > std::numeric_limits<float>::epsilon() && 
        decimalPlaces <= std::numeric_limits<float>::digits10)
    {
        //std::cout << x << ", ";

        x = x * 10;
        ++decimalPlaces;
        //x = x - (int) x;
        x = x - std::round(x);

       // x = x - (int) x;
    }

    return decimalPlaces;
}*/


//Ne pas suppr pour l'instant, sert à avoir le nombre de digits après la virgule d'un nombre flottant

/*int digits_number(double x){
    int count = 0; 
    while((int) x != x){
        x*=10;
        count++;
    }


    x = abs(x);
    x = x - int(x);
    while (x != 0){

    x = x * 10;
    count++;
    x = x - int(x);
    }

    return count;
}*/


/*Ratio<int> convert_float_to_ratio2(double x, const unsigned int max_nb_iter, const double precision){

    //Ratio<int> result;
    unsigned int nb_iter = max_nb_iter;
    int signe = 1;
    int q=0;

    if(x==0 || nb_iter==0){
        Ratio result(0,1);
        return result;
    }

    if(nb_iter==0){
        Ratio result(0,1);
        return result;
    }

    if(x<0.){
        signe = -1;
        x = -x;
    }

    if(x<1.){

        if(digits_nb(x) >= 7){
        x = std::round(x * 1000.0) / 1000.0;
        }
        return convert_float_to_ratio2((double) (1/x),nb_iter, precision).inverse();
    }   

    else{
      
        q = (int) x;
        Ratio quotient(q,1);

      
        if(std::fabs(x-q)<=precision){
            nb_iter=1;
        }
        
        return ((quotient + convert_float_to_ratio2((x-q), nb_iter -1,precision))*signe);
    }

    //return result;
}*/


int main(){
 

    //double test = 123456.9087654;
    //double test = 0.9054054054;
    //double test = 0.12349;
    //double test = 45624963.2;
    //double test = 5.28;
    
    /*double test = 3.87;
    std::cout << "test : " << convert_float_to_ratio2(test, 17, 0.01) << std::endl;
    std::cout << "test : " << convert_float_to_ratio2(test, 4, 0.0001) << std::endl;
    std::cout << "digitnumber : " << digits_nb(test) << std::endl;*/
    //std::cout << trunc_decs(test, 10) << std::endl;

    //std::cout << "digitnumber : " << digits_number(test) << std::endl;
    Ratio<int> a(3.456);
    std::cout << "a = ";
    a.displayRatio();
    std::cout << "float a = ";
    std::cout << a.convert_to_float() << std::endl;

    Ratio<int> b(-164,290);
    std::cout << "b = ";
    b.displayRatio();

    std::cout << "b*2=" << b*2<< std::endl;
    std::cout << "b*2=" << 2*b<< std::endl;
    std::cout << "b*2.33333="<< b*2.33333<< std::endl;


    std::cout << "Ratio::pow(b,3) = " << b.ratio_pow(3) << std::endl;
    std::cout << "std::pow(b,3) = " << b.ratio_pow2(3) << std::endl;
    

    Ratio<int> c(121,256);
    std::cout << "c = ";
    c.displayRatio();
    std::cout << "Ratio::sqrt(c) = " << c.ratio_sqrt() << std::endl;
    std::cout << "std::sqrt(c) = " << c.ratio_sqrt2() << std::endl;


    Ratio<long int> d(8,3);
    std::cout << "d = ";
    d.displayRatio();
    std::cout << "Ratio::exp(d) = " << d.ratio_exp() << std::endl;
    std::cout << "std::exp(d) = " << d.ratio_exp2() << std::endl;

    //Ratio<long int> d_exp2 = d + c;
    //d_exp2.displayRatio();

    Ratio<int> e(7,2);
    std::cout << "e = ";
    e.displayRatio();

    std::cout << "Ratio::sin(e) = " << e.ratio_sin() << std::endl;
    std::cout << "std::sin(e) = " << e.ratio_sin2() << std::endl;

    Ratio<int> f(3,2);
    std::cout << "f = ";
    f.displayRatio();
    std::cout << "Ratio::cos(f) = " << f.ratio_cos() << std::endl;
    std::cout << "std::cos(f) = " << f.ratio_cos() << std::endl;


}
