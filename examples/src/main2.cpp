#include <iostream>
#include "ratio.hpp"


int main(){

    Ratio a(1,2);
    std::cout << "a = "; 
    a.displayRatio();

    Ratio b(3,4);
    std::cout << "b = ";
    b.displayRatio();

    Ratio c = a;

    if(a == b){
        std::cout << "error a != b" << std::endl;
    }else{
        std::cout << "success a != b"<<std::endl;
    }


    if( a == c){
        std::cout <<"success a = c "<<std::endl;
    }else{
        std::cout << "error a = c "<<std::endl;
    }


    if(a != b){
        std::cout << "success a != b" << std::endl;
    }else{
        std::cout << "error a != b"<<std::endl;
    }


    if( a != c){
        std::cout <<"error a = c "<<std::endl;
    }else{
        std::cout << "success a = c "<<std::endl;
    }


    if(a > b){
        std::cout << "error a < b" << std::endl;
    }else{
        std::cout << "success a < b"<<std::endl;
    }

    if(a < b){
        std::cout << "sucess a < b" << std::endl;
    }else{
        std::cout << "error a < b"<<std::endl;
    }

    if(a >= b){
        std::cout << "error a < b" << std::endl;
    }else{
        std::cout << "success a < b"<<std::endl;
    }

    if(a <= b){
        std::cout << "success a < b" << std::endl;
    }else{
        std::cout << "error a < b"<<std::endl;
    }


    if(a >= c){
        std::cout << "success a = c" << std::endl;
    }else{
        std::cout << "error a = c"<<std::endl;
    }

    if(a <= c){
        std::cout << "success a = c" << std::endl;
    }else{
        std::cout << "error a = c"<<std::endl;
    }


    return 0;
}