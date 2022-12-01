#include "ratio.hpp"
#include <iostream>
#include <numeric>

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

bool Ratio::operator==(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();
    
    Ratio thistmp = *this; 
    thistmp.reduce();

    return thistmp.m_num == rtmp.m_num && thistmp.m_denom == rtmp.m_denom;

}

bool Ratio::operator!=(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();
    
    Ratio thistmp = *this; 
    thistmp.reduce();

    return !(thistmp == rtmp);

}

bool Ratio::operator>(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    int a = thistmp.m_num * rtmp.m_denom; 
    int b = thistmp.m_denom * rtmp.m_num;

    return a > b;

 
}


bool Ratio::operator<(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    int a = thistmp.m_num * rtmp.m_denom; 
    int b = thistmp.m_denom * rtmp.m_num;

    return a < b;

}

bool Ratio::operator<=(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    return ( (thistmp < rtmp) || (thistmp == rtmp) );

}


bool Ratio::operator>=(const Ratio &r) const {

    Ratio rtmp = r;
    rtmp.reduce();

    Ratio thistmp = *this; 
    thistmp.reduce();

    return ( (thistmp > rtmp) || (thistmp == rtmp) );

}