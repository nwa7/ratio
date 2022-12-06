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

Ratio Ratio::inverse() const {
    
    if(m_num == 0){
        return *this;
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


bool Ratio::operator==(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();
    
    Ratio thistmp = *this; 
    thistmp.reduce();

    return thistmp.m_num == rtmp.m_num && thistmp.m_denom == rtmp.m_denom;*/

    return m_num * r.m_denom == r.m_num * m_denom;

}

bool Ratio::operator!=(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();
    
    Ratio thistmp = *this; 
    thistmp.reduce();

    return !(thistmp == rtmp);*/

    return !((*this) == r);

}

bool Ratio::operator>(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    int a = thistmp.m_num * rtmp.m_denom; 
    int b = thistmp.m_denom * rtmp.m_num;

    return a > b;*/

    return m_num * r.m_denom > r.m_num * m_denom;

 
}


bool Ratio::operator<(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    int a = thistmp.m_num * rtmp.m_denom; 
    int b = thistmp.m_denom * rtmp.m_num;

    return a < b;*/

    return m_num * r.m_denom < r.m_num * m_denom;

}

bool Ratio::operator<=(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    return ( (thistmp < rtmp) || (thistmp == rtmp) );*/

    return (m_num * r.m_denom < r.m_num * m_denom) || ((*this) == r) ;

}


bool Ratio::operator>=(const Ratio &r) const {

    /*Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    return ( (thistmp > rtmp) || (thistmp == rtmp) );*/

    return (m_num * r.m_denom > r.m_num * m_denom) || ((*this) == r) ;

}