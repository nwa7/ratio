#include "ratio.hpp"
#include <iostream>
#include <numeric>
#include <cmath>


template<typename R>
Ratio<R>::Ratio(const R num, const R denom): m_num(num), m_denom(denom){}

template<typename R>
Ratio<R>::Ratio(const Ratio<R>&r):m_num(r.m_num), m_denom(r.m_denom){}


template<typename R>
Ratio<R>::Ratio(const double &x){
    m_num = convert_float_to_ratio(x,4,0.01).m_num;
    m_denom = convert_float_to_ratio(x,4,0.01).m_denom;
}

template<typename R>
void Ratio<R>::displayRatio() const {

    std::cout << m_num << "/" << m_denom << std::endl;
    
}

template<typename R>
void Ratio<R>::reduce(){
    if (this->getNum() == 0){
        this->setNum(0);
        this->setDenom(1);
    }           
    else {
        int pgcd = std::gcd(m_num, m_denom);
        this->setNum(m_num/pgcd);
        this->setDenom(m_denom/pgcd);     
    }     
}

template<typename R>
int Ratio<R>::getNum() const{
   return m_num;
}

template<typename R>
int Ratio<R>::getDenom() const{
   return m_denom;
}

template<typename R>
void Ratio<R>::setNum(R num){
   (*this).m_num = num;
}

template<typename R>
void Ratio<R>::setDenom(R denom){
   (*this).m_denom = denom;
}


template<typename R>
Ratio<R>& Ratio<R>::operator=(const Ratio<R> &r) {

    if(&r == this) return *this;

    this->setNum(r.m_num);
    this->setDenom(r.m_denom);
    return *this;
}

template<typename R>
Ratio<R> Ratio<R>::operator+(const Ratio<R> &r) const {

    Ratio<R> result; 

    result.m_num = m_num*r.m_denom + m_denom*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}

template<typename R>
Ratio<R> Ratio<R>::operator-(const Ratio<R> &r) const {

    Ratio<R> result; 

    result.m_num = m_num*r.m_denom - m_denom*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}

template<typename R>
Ratio<R> Ratio<R>::operator*(const Ratio<R> &r) const {

    Ratio<R> result; 

    result.m_num = m_num*r.m_num;
    result.m_denom = m_denom * r.m_denom;

    result.reduce();

    return result;
}



template<typename R>
Ratio<R> Ratio<R>::operator/(const Ratio<R> &r) const {

    Ratio<R> result; 

    result.m_num = m_num*r.m_denom;
    result.m_denom = m_denom * r.m_num;

    result.reduce();

    return result;
}


template<typename R>
Ratio<R>& Ratio<R>::operator+=(const Ratio<R> &r){
    *this = *this+r;
    return *this;
}

template<typename R>
Ratio<R>& Ratio<R>::operator-=(const Ratio<R> &r){
    *this = *this-r;
    return *this;
}

template<typename R>
Ratio<R>& Ratio<R>::operator*=(const Ratio<R> &r){
    *this = *this*r;
    return *this;
}

template<typename R>
Ratio<R>& Ratio<R>::operator/=(const Ratio<R> &r){
    *this = *this/r;
    return *this;
}

template<typename R>
Ratio<R> Ratio<R>::operator-() const {
    Ratio<R> result;
    result.m_num = -m_num;
    result.m_denom = m_denom;
    return result;
}


template<typename R>
Ratio<R> Ratio<R>::inverse() const {

    if(m_num<0){
        Ratio<R> result(-m_denom, -m_num);
    }

    Ratio<R> result(m_denom, m_num);
    return result;
}


///voir si on peut le faire directement pour les cas simples ? mais jsp si on y gagne bcp vu qu'on rajoute du code idk

template<typename R>
Ratio<R> Ratio<R>::ratio_sqrt2() const {

    double float_sqrt = std::sqrt(this->convert_to_float());
    return best_convert_float_to_ratio(float_sqrt, 20, 0.01);

}

//Newton 
template<typename R>
double Ratio<R>::real_ratio_sqrt(const double &n) const {

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
template<typename R>
Ratio<R> Ratio<R>::ratio_sqrt() const {

    if(m_num < 0){
        std::cout << "Cannot find square root of negative number"
        << std::endl;
    }

    double float_sqrt = real_ratio_sqrt(this->convert_to_float());
    return best_convert_float_to_ratio(float_sqrt, 20, 0.01);

}


template<typename R>
Ratio<R> Ratio<R>::ratio_pow2(const int &n) const{

    Ratio<R> result = *(this); 
    result.m_num = std::pow(result.m_num, n);
    result.m_denom = std::pow(result.m_denom, n);
    
    result.reduce();

    return result;

}


template<typename R>
Ratio<R> Ratio<R>::ratio_pow(const double &n) const{

    Ratio<R> result;
    if ((int)n==0 || (m_num ==1 && m_denom ==1)){
        return result;
    }
    if( (int)n==1){
        return *(this);
    }
    if((int)n%2==0){
        Ratio<R> calculPair = ratio_pow(n/2);
        return calculPair*calculPair;
    }
    else{ 
        Ratio<R> calculImpair = ratio_pow((n-1)/2);
        return (*this)*(calculImpair*calculImpair);
      
    }

}


template<typename R>
template<typename T>
T Ratio<R>::real_ratio_exp(const T &x) const{

    const T x0 = std::abs(x);

    const unsigned int max_iter = 28; 
    T result = static_cast<T>(1) +  (x0 / max_iter);

    for(unsigned int i=max_iter-1; i>=1; --i)
        result = static_cast<T>(1) + (x0 / i) * result;

    return (x >= 0) ? result : static_cast<T>(1) / result;
}


template<typename R>
Ratio<R> Ratio<R>::ratio_exp() const{

    double float_exp = real_ratio_exp(this->convert_to_float());
    return best_convert_float_to_ratio(float_exp, 20, 0.01);


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



template<typename R>
Ratio<R> Ratio<R>::ratio_exp2() const{
    double float_exp = std::exp(this->convert_to_float());
    return best_convert_float_to_ratio(float_exp, 20, 0.01);
}

//taylor series
template<typename R>
template<typename T>
T Ratio<R>::real_ratio_sin(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<12; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i+1)*(2*i));
    }
    result*= x;
    return result;
}


template<typename R>
Ratio<R> Ratio<R>::ratio_sin() const{
    double float_sin = real_ratio_sin(this->convert_to_float());
    return best_convert_float_to_ratio(float_sin, 20, 0.01);
}


template<typename R>
Ratio<R> Ratio<R>::ratio_sin2() const{
    double float_sin = std::sin(this->convert_to_float());
    return best_convert_float_to_ratio(float_sin, 20, 0.01);
}

//taylor series
template<typename R>
template<typename T>
T Ratio<R>::real_ratio_cos(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<12; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i-1)*(2*i));
    }
    return result;
}

template<typename R>
Ratio<R> Ratio<R>::ratio_cos() const{
    double float_cos = real_ratio_cos(this->convert_to_float());
    return best_convert_float_to_ratio(float_cos, 20, 0.01);
}


template<typename R>
Ratio<R> Ratio<R>::ratio_cos2() const{
    double float_cos = std::cos(this->convert_to_float());
    return best_convert_float_to_ratio(float_cos, 20, 0.01);
}



template<typename R>
Ratio<R> Ratio<R>::ratio_abs() const {
    Ratio<R> result = *(this); 
    
    if(result.m_num < 0){
        result.m_num = -result.m_num;
    }
    
    return result;
}

template<typename R>
int Ratio<R>::ratio_intpart() const {
   int result = 0;
   if (m_denom != 0){
       result = static_cast<int>(m_num/(int)m_denom);
   }
   return result;
}


template<typename R>
bool Ratio<R>::operator==(const Ratio<R> &r) const {

    return m_num * r.m_denom == r.m_num * m_denom;

}

template<typename R>
bool Ratio<R>::operator!=(const Ratio<R> &r) const {


    return !((*this) == r);

}

template<typename R>
bool Ratio<R>::operator>(const Ratio<R> &r) const {

    return m_num * r.m_denom > r.m_num * m_denom;
 
}


template<typename R>
bool Ratio<R>::operator<(const Ratio<R> &r) const {

    return m_num * r.m_denom < r.m_num * m_denom;

}

template<typename R>
bool Ratio<R>::operator<=(const Ratio<R> &r) const {

    return (m_num * r.m_denom < r.m_num * m_denom) || ((*this) == r) ;

}


template<typename R>
bool Ratio<R>::operator>=(const Ratio<R> &r) const {

    return (m_num * r.m_denom > r.m_num * m_denom) || ((*this) == r) ;

}

template<typename R>
double Ratio<R>::compare_closest(const R &num, const double &a, const double &b) const {
    if(std::fabs(num-a) <= std::fabs(num-b)){
        return a;
    }

    return b;
}

template<typename R>
Ratio<R> Ratio<R>::convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const {
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
      
        return convert_float_to_ratio((double) 1/x,nb_iter, precision).inverse();
    }

    else{
       
       
        q = (int) x;
        Ratio quotient(q,1);

        if((x-q)<precision){
            nb_iter=1;
        }
        return ((quotient + convert_float_to_ratio(x-q, nb_iter -1,precision))*signe);
    }

    
}

template<typename R>
Ratio<R> Ratio<R>::best_convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const {
    double result1 = convert_float_to_ratio(x,4, precision).convert_to_float();
    double result2 = convert_float_to_ratio(x,max_nb_iter, precision).convert_to_float();

    if(compare_closest(x, result1, result2) == result1){
        return convert_float_to_ratio(x,4, precision);
    }

    return convert_float_to_ratio(x,max_nb_iter, precision);

}

//gerer le cas division par 0
template<typename R>
double Ratio<R>::convert_to_float() const {
   return (double) m_num/m_denom;
}

template<typename R>
int Ratio<R>::digits_nb(double x) const{
    int decimalPlaces = 0;
    x = std::abs(x);
    x = x - std::round(x);
    //x = x - (int) x;

    while (
        std::abs(x) - std::numeric_limits<float>::epsilon() > std::numeric_limits<float>::epsilon() && 
        decimalPlaces <= std::numeric_limits<float>::digits10)
    {
       
        x = x * 10;
        ++decimalPlaces;
        x = x - std::round(x);
    }

    return decimalPlaces;
}

template class Ratio<int>;
template class Ratio<long int>;
