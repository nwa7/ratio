#include "ratio.hpp"
#include <iostream>
#include <numeric>
#include <cmath>
#include <exception>
	

template<typename R>
void Ratio<R>::reduce(){

    if (m_num == 0){
        m_denom = 1;
    }    
    else {
        int pgcd = std::gcd(m_num, m_denom);
        m_num = m_num/pgcd;
        m_denom = m_denom/pgcd;     
    }
         
}

template<typename R>
Ratio<R>& Ratio<R>::operator=(const Ratio<R> &r) {

    if(&r == this) return *this;
    m_num = r.m_num;
    m_denom = r.m_denom;
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
Ratio<R> Ratio<R>::operator-() const {
    Ratio<R> result;
    result.m_num = -m_num;
    result.m_denom = m_denom;
    return result;
}

//Newton 
template<typename R>
double Ratio<R>::real_ratio_sqrt(const double &n) const {

   const double PRECISION = 0.00000001;
   double guess = 0., newGuess = 0.; 

   guess = n/2;
   newGuess = n/4; 

   while(std::fabs(guess - newGuess) > PRECISION){
       newGuess = guess;
       guess = (guess + n / guess)*0.5;
   }

   return guess;
}


template<typename R>
Ratio<R> Ratio<R>::ratio_sqrt() const {

    if(m_num < 0){

		throw std::invalid_argument("Cannot find square root of negative number");
    }
    

    double float_sqrt = real_ratio_sqrt(this->convert_to_float());
    return convert_float_to_ratio(float_sqrt, 4, 0.01);

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
    return convert_float_to_ratio(float_exp, 4, 0.01);

}


//taylor series
template<typename R>
template<typename T>
T Ratio<R>::real_ratio_sin(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<16; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i+1)*(2*i));
    }
    result*= x;
    return result;
}


template<typename R>
Ratio<R> Ratio<R>::ratio_sin() const{
    double float_sin = real_ratio_sin(this->convert_to_float());
    return convert_float_to_ratio(float_sin, 4, 0.01);
}


//taylor series
template<typename R>
template<typename T>
T Ratio<R>::real_ratio_cos(const T &x) const{
    T result(0);
    T ratio(1);
    for(unsigned int i=1; i<16; ++i){
        result += ratio;
        ratio*= -x*x / ((2*i-1)*(2*i));
    }
    return result;
}

template<typename R>
Ratio<R> Ratio<R>::ratio_cos() const{
    double float_cos = real_ratio_cos(this->convert_to_float());
    return convert_float_to_ratio(float_cos, 4, 0.01);
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
Ratio<R> Ratio<R>::inverse() const {

    if(m_num<0){
        Ratio<R> result(-m_denom, -m_num);
        return result;
    }

    Ratio<R> result(m_denom, m_num);
    return result;
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
double Ratio<R>::convert_to_float() const {
    if(m_denom ==0)
		throw std::invalid_argument("Impossible to divide by 0");
   return (double) m_num/m_denom;
}

template<typename R>
int Ratio<R>::digits_nb(double x) const{
    int count = 0;
    x = std::abs(x);
    x = x-std::round(x);

    while (
        std::abs(x) - std::numeric_limits<float>::epsilon() > std::numeric_limits<float>::epsilon() && 
        count <= std::numeric_limits<float>::digits10)
    {
       
        x = x * 10;
        count++;
        x = x - std::round(x);
    }

    return count;
}

template class Ratio<int>;
template class Ratio<long int>;
