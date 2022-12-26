#include "ratio.hpp"
#include <iostream>
#include <numeric>
#include <cmath>


Ratio::Ratio(const int num, const unsigned int denom): m_num(num), m_denom(denom){}

Ratio::Ratio(const Ratio &r):m_num(r.m_num), m_denom(r.m_denom){}

Ratio::Ratio(const double &x){
    m_num = convert_float_to_ratio(x,4,0.01).m_num;
    m_denom = convert_float_to_ratio(x,4,0.01).m_denom;
}

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

void Ratio::setNum(int num){
   (*this).m_num = num;
}

void Ratio::setDenom(unsigned int denom){
   (*this).m_denom = denom;
}


Ratio& Ratio::operator=(const Ratio &r) {

    if(&r == this) return *this;

    this->setNum(r.m_num);
    this->setDenom(r.m_denom);
    return *this;
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


/*VOIR SI POSSIBLE DE REUNIR LES DEUX * INT ET FLOAT DANS UN TEMPLATE ?*/


Ratio Ratio::operator*(const int &n) const {

    Ratio result; 

    result.m_num = m_num*n;
    result.m_denom = m_denom;

    result.reduce();

    return result;
}


Ratio Ratio::operator*(const float &x) const { // à bosser dans le cas où le nombre à virgule serait infini
    Ratio result; 
    uint mantissa=1;
    result.m_num = m_num*x;
    while (m_num*mantissa < 0){
        mantissa *=10;
    }
    result.setNum(m_num * mantissa);
    result.setDenom(m_denom * mantissa);

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


Ratio& Ratio::operator+=(const Ratio &r){
    *this = *this+r;
    return *this;
}

Ratio& Ratio::operator-=(const Ratio &r){
    *this = *this-r;
    return *this;
}

Ratio& Ratio::operator*=(const Ratio &r){
    *this = *this*r;
    return *this;
}

Ratio& Ratio::operator/=(const Ratio &r){
    *this = *this/r;
    return *this;
}

Ratio Ratio::operator-() const {
    Ratio result;
    result.m_num = -m_num;
    result.m_denom = m_denom;
    return result;
}


Ratio Ratio::inverse() const {

    if(m_num<0){
        Ratio result(-m_denom, -m_num);
    }

    Ratio result(m_denom, m_num);
    return result;
}


///voir si on peut le faire directement pour les cas simples ? mais jsp si on y gagne bcp vu qu'on rajoute du code idk
Ratio Ratio::ratio_sqrt2() const {

    double float_sqrt = std::sqrt(this->convert_to_float());
    return best_convert_float_to_ratio(float_sqrt, 100, 0.000001);

}


double Ratio::real_ratio_sqrt(const double &n) const {

   const double PRECISION = 0.00000001;
   double guess, newGuess; 

   guess = n/2;
   newGuess = n/4; 

   while(std::fabs(guess - newGuess) > PRECISION){
       newGuess = guess;
       guess = (guess + n / guess)*0.5;
   }

   return guess;
}


//gerer exception ici <0 
Ratio Ratio::ratio_sqrt() const {

    if(m_num < 0){
        std::cout << "Cannot find square root of negative number"
        << std::endl;
    }

    double float_sqrt = real_ratio_sqrt(this->convert_to_float());
    return best_convert_float_to_ratio(float_sqrt, 100, 0.000001);

}


Ratio Ratio::ratio_pow2(const int &n) const{

    Ratio result = *(this); 
    result.m_num = std::pow(result.m_num, n);
    result.m_denom = std::pow(result.m_denom, n);
    
    result.reduce();

    return result;

}


Ratio Ratio::ratio_pow(const double &n) const{

    Ratio result;
    if ((int)n==0 || (m_num ==1 && m_denom ==1)){
        return result;
    }
    if( (int)n==1){
        return *(this);
    }
    if((int)n%2==0){
        Ratio calculPair = ratio_pow(n/2);
        return calculPair*calculPair;
    }
    else{ 
        Ratio calculImpair = ratio_pow((n-1)/2);
        return (*this)*(calculImpair*calculImpair);
      
    }

}

/*Ratio Ratio::ratio_pow2(const int &p) const{

    Ratio result;
    if (p==0 || (m_num ==1 && m_denom ==1)){
        return result;
    }
    if( p==1){
        return *(this);
    }
    if(p%2==0){
        Ratio calculPair = ratio_pow(p/2);
        return calculPair*calculPair;
    }
    else{ 
        Ratio calculImpair = ratio_pow((p-1)/2);
        return (*this)*(calculImpair*calculImpair);
      
    }

}*/

template<typename T>
T Ratio::real_ratio_exp(const T &x) const{

    const T x0 = std::abs(x);

    const unsigned int max_iter = 28; 
    T result = static_cast<T>(1) +  (x0 / max_iter);

    for(unsigned int i=max_iter-1; i>=1; --i)
        result = static_cast<T>(1) + (x0 / i) * result;

    return (x >= 0) ? result : static_cast<T>(1) / result;
}


Ratio Ratio::ratio_exp() const{

    double float_exp = real_ratio_exp(this->convert_to_float());
    return best_convert_float_to_ratio(float_exp, 100, 0.000001);


    //J'ai essaye d'appliquer horner directement sur un ratio mais ça marche pas trop si tu veux tenter de le faire toi

    /*Ratio x = this->ratio_abs();

    const unsigned int max_iter = 21;
    Ratio test(max_iter, 1); 
    Ratio result;
    result += x / test;

    for(unsigned int i=max_iter-1; i>=1; --i){
        Ratio add(1,1);
        Ratio add2(i,1);
        result = add + (x / add2) * result;

    }

    return (this->convert_to_float() >= 0) ? result : result.inverse();*/

}



Ratio Ratio::ratio_exp2() const{
    double float_exp = std::exp(this->convert_to_float());
    return best_convert_float_to_ratio(float_exp, 100, 0.000001);
}

//taylor series
template<typename T>
T Ratio::real_ratio_sin(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<12; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i+1)*(2*i));
    }
    result*= x;
    return result;
}


Ratio Ratio::ratio_sin() const{
    double float_sin = real_ratio_sin(this->convert_to_float());
    return best_convert_float_to_ratio(float_sin, 100, 0.000001);
}


Ratio Ratio::ratio_sin2() const{
    double float_sin = std::sin(this->convert_to_float());
    return best_convert_float_to_ratio(float_sin, 100, 0.000001);
}

//taylor series
template<typename T>
T Ratio::real_ratio_cos(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<12; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i-1)*(2*i));
    }
    return result;
}

Ratio Ratio::ratio_cos() const{
    double float_cos = real_ratio_cos(this->convert_to_float());
    return best_convert_float_to_ratio(float_cos, 100, 0.000001);
}


Ratio Ratio::ratio_cos2() const{
    double float_cos = std::cos(this->convert_to_float());
    return best_convert_float_to_ratio(float_cos, 100, 0.000001);
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

double Ratio::compare_closest(const double &num, const double &a, const double &b) const {
    if(std::fabs(num-a) <= std::fabs(num-b)){
        return a;
    }

    return b;
}

Ratio Ratio::convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const {
    Ratio result;
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
      
        return convert_float_to_ratio((double) 1/x,nb_iter, precision).inverse();
    }

    if(x >= 1){
       
       
        q = (int) x;
        Ratio quotient(q,1);

        if((x-q)<precision){
            nb_iter=1;
        }
        return ((quotient + convert_float_to_ratio(x-q, nb_iter -1,precision))*signe);
    }

    return result;
}

Ratio Ratio::best_convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const {
    double result1 = convert_float_to_ratio(x,4, precision).convert_to_float();
    double result2 = convert_float_to_ratio(x,max_nb_iter, precision).convert_to_float();

    if(compare_closest(x, result1, result2) == result1){
        return convert_float_to_ratio(x,4, precision);
    }

    return convert_float_to_ratio(x,max_nb_iter, precision);

}

//gerer le cas division par 0
double Ratio::convert_to_float() const {
   return (double) m_num/m_denom;
}
