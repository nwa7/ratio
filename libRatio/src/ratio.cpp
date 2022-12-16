#include "ratio.hpp"
#include <iostream>
#include <numeric>
#include <cmath>

Ratio::Ratio(const int num, const unsigned int denom): m_num(num), m_denom(denom){}

Ratio::Ratio(const Ratio &r):m_num(r.m_num), m_denom(r.m_denom){}

void Ratio::displayRatio() const {

    std::cout << m_num << "/" << m_denom << std::endl;
    
}

void Ratio::reduce(){
    int pgcd = std::gcd(m_num, m_denom);
    if(pgcd != 0){
    m_num = m_num/pgcd;
    m_denom = m_denom/pgcd; 
        
    }
}

int Ratio::getNum(){
   return m_num;
}

int Ratio::getDenom(){
   return m_denom;
}


Ratio Ratio::operator+(const Ratio &r) const {

    Ratio result; 

    result.m_num = m_num*r.m_denom + m_denom*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}

Ratio Ratio::operator-(const Ratio &r) const {

    Ratio result; 

    result.m_num = m_num*r.m_denom - m_denom*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}

Ratio Ratio::operator*(const Ratio &r) const {

    Ratio result; 

    result.m_num = m_num*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}

Ratio Ratio::operator/(const Ratio &r) const {

    Ratio result; 

    result.m_num = m_num*r.m_denom;
    result.m_denom = m_denom * r.m_num;

    result.reduce();

    return result;
}

Ratio Ratio::operator-() const {
    Ratio result;
    result.m_num = -m_num;
    result.m_denom = m_denom;
    return result;
}


//gerer negatif
Ratio Ratio::inverse() const {
    
    /*if(m_num == 0){
        return *this;
    }*/

    if(m_num<0){
         Ratio result(-m_denom, -m_num);
    }

    Ratio result(m_denom, m_num);
    return result;
}


///plutot convertir en reel puis faire sqrt et ensuite reconvertir en ratio
///a faire quand on aura la fonction de conversion
Ratio Ratio::ratio_sqrt() const {
    Ratio result;
    /*result.m_num = std::sqrt(result.m_num);
    result.m_denom = std::sqrt(result.m_denom);*/

    return result;
}


Ratio Ratio::ratio_abs() const {
    Ratio result = *(this); 
    
    if(result.m_num < 0){
        result.m_num = -result.m_num;
    }
    
    return result;
}

int Ratio::ratio_intpart() const {
   int result = 0;
   if (m_denom != 0){
       result = static_cast<int>(m_num/(int)m_denom);
   }
   return result;
}


bool Ratio::operator==(const Ratio &r) const {

    return m_num * r.m_denom == r.m_num * m_denom;

}

bool Ratio::operator!=(const Ratio &r) const {


    return !((*this) == r);

}

bool Ratio::operator>(const Ratio &r) const {

    return m_num * r.m_denom > r.m_num * m_denom;
 
}


bool Ratio::operator<(const Ratio &r) const {

    return m_num * r.m_denom < r.m_num * m_denom;

}

bool Ratio::operator<=(const Ratio &r) const {

    return (m_num * r.m_denom < r.m_num * m_denom) || ((*this) == r) ;

}


bool Ratio::operator>=(const Ratio &r) const {

    return (m_num * r.m_denom > r.m_num * m_denom) || ((*this) == r) ;

}

Ratio Ratio::convert_float_to_ratio(double x, const unsigned int nb_iter){
    Ratio result;
    int q;
    if(x==0){
        //result.m_num=0;
        //result.m_denom=1; 
        Ratio result(0,1);
        return result;
    }

    if(nb_iter==0){
        //result.m_num=0;
        //result.m_denom=1; 
        Ratio result(0,1);
        return result;
    }

    if(x<1.){
        return convert_float_to_ratio(1/x,nb_iter).inverse();
    }

    if(x >= 1){
        q = (int) x;
        Ratio quotient(q,1);
        return quotient + convert_float_to_ratio(x-q, nb_iter -1);
    }

}