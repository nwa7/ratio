#include <iostream>
#include "ratio.hpp"


Ratio convert_float_to_ratio(double x, const unsigned int nb_iter){
    Ratio result;
    int q=0;
    if(x==0){
        Ratio result(0,1);
        return result;
    }

    if(nb_iter==0){
        Ratio result(0,1);
        return result;
    }

    if(x<1.){
        return convert_float_to_ratio((double) 1/x,nb_iter).inverse();
    }

    if(x >= 1){
        q = (int) x;
        Ratio quotient(q,1);
        return quotient + convert_float_to_ratio(x-q, nb_iter -1);
    }

    return result;
}

int main(){
    //double a = 5.28 ;
    double a = 5.28;
    Ratio a_ratio = convert_float_to_ratio(a, 1000); 
    //a_ratio.convert_float_to_ratio(a, 5); 
    a_ratio.reduce();
    a_ratio.displayRatio();
}