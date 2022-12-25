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

    Ratio b_square1 = b.ratio_pow(3);
    std::cout << "std::sqrt(b) = ";
    b_square1.displayRatio();

    Ratio b_square2 = b.ratio_pow(3);
    std::cout << "Ratio::sqrt(b) = ";
    b_square2.displayRatio();

}