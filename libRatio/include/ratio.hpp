#pragma once 
#include <iostream>


// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html Sakura1.png
/// \tableofcontents
/// \section introduction_sec What is it for?
/// This library was done for our Maths / Prog final project of IMAC 2
/// Come and see our super tool Ratio ! 
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html



/// \class Ratio
/// \brief class defining a ratio, alternative way of defining a float number.

template <typename R>
class Ratio{
    private : 
    R m_num;
    R m_denom; /// -> doit être poz 

	/// \brief Ratio is composed of two members : a numerator in int and a denominator in uint


    public:

	/// \brief constructor from a numerator & a denominator, return 1 in Ratio if called empty 
	/// \param num : numerator
	/// \param denom : denominator
    Ratio(const R num = 1, const R denom = 1);


	/// \brief copy constructor
	/// \param r : Ratio
    Ratio(const Ratio<R> &r);


	/// \brief Ratio constructor from a float / int
	/// \param x real
	Ratio(const double &x);

	/// \brief default destructor
    ~Ratio()= default;

	/// \brief display num/denom
    void displayRatio() const;

	/// \brief return the Ratio in irreducible form
    void reduce();
    
	/// \brief getter numerator
    int getNum() const;

	/// \brief getter denominator
    int getDenom() const;

	/// \brief setter numerator
    void setNum(R num);

	/// \brief setter denominator
    void setDenom(R denom);

	/// \brief copy a Ratio on another Ratio
	Ratio& operator=(const Ratio &r);

	/// \brief sum of *this and r
    Ratio<R> operator+(const Ratio<R> &r) const;

	/// \brief substract r to *this 
    Ratio<R> operator-(const Ratio &r) const;

	/// \brief product *this and r
    Ratio<R> operator*(const Ratio &r) const;


	/// \brief product *this and a real
	template<typename T>
	Ratio<R> operator*(const T &n) const {
		Ratio<R> result; 
		if (m_num*n == (int)(m_num*n)){
			result.setNum(m_num*n);
			result.setDenom(m_denom);
		}
		else {
			Ratio converted = convert_float_to_ratio(n, 4 , 0.01);
			result.setNum(m_num * converted.getNum());
			result.setDenom(m_denom * converted.getDenom());
		}

		result.reduce();

		return result;
	}

	/// \brief division of *this by r
    Ratio<R> operator/(const Ratio &r) const;


	/// \brief shortcut operator doing this = this + r
	Ratio<R>& operator+=(const Ratio &r);

	/// \brief shortcut operator doing this = this - r
	Ratio<R>& operator-=(const Ratio &r);

	/// \brief shortcut operator doing this = this * r
	Ratio<R>& operator*=(const Ratio &r);

	/// \brief shortcut operator doing this = this / r
	Ratio<R>& operator/=(const Ratio &r);

	/// \brief unary minus
    Ratio<R> operator-() const;


	/// \brief square root of *this
    Ratio<R> ratio_sqrt() const ;

	/// \brief real implementation of square root using Newton aproach
    double real_ratio_sqrt(const double &n) const ;

	/// \brief square root of *this using std
    Ratio<R> ratio_sqrt2() const ;

	/// \brief power of *this
    Ratio<R> ratio_pow(const double &n) const ;

	/// \brief power of *this using std
    Ratio<R> ratio_pow2(const int &n) const ;

	/// \brief exponential of *this
	Ratio<R> ratio_exp() const;

	/// \brief real implementation of exponential using Horner
	template<typename T>
	T real_ratio_exp(const T &x) const;

	/// \brief exponential of *this using std
	Ratio<R> ratio_exp2() const;

	/// \brief sin of *this 
	Ratio<R> ratio_sin() const;

	/// \brief real implementation of sin using Taylor series
	template<typename T>
	T real_ratio_sin(const T &x) const;

	/// \brief sin of *this using std
	Ratio<R> ratio_sin2() const;

	/// \brief cos of *this
	Ratio<R> ratio_cos() const;

	/// \brief real implementation of cos using Taylor series
	template<typename T>
	T real_ratio_cos(const T &x) const;

	/// \brief cos of *this using std
	Ratio<R> ratio_cos2() const;

	/// \brief return *this with an absolute numerator
    Ratio<R> ratio_abs() const;

	/// \brief return euclide division of numerator divised by denominator
    int ratio_intpart() const;

	/// \brief return inverse of *this
    Ratio<R> inverse() const;
    
	/// \brief test if *this and r are equal
    bool operator==(const Ratio<R> &r) const;

	/// \brief test if *this and r are different
    bool operator!=(const Ratio<R> &r) const;

	/// \brief test if *this is strictly greater than r 
    bool operator>(const Ratio<R> &r) const;

	/// \brief test if r is striclty greater than *this
    bool operator<(const Ratio<R> &r) const;

	/// \brief test if *this is greater than r or equal to r
    bool operator>=(const Ratio<R> &r) const;

	/// \brief test if r is greater than *this or equal to *this
    bool operator<=(const Ratio<R> &r) const;

	/// \brief returns closest value to num
	double compare_closest(const R &num, const double &a, const double &b) const;

	/// \brief convert float to ratio
	/// \param max_nb_iter : number of iterations
	/// \param precision: epsilon error 
    Ratio<R> convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const ;

	/// \brief convert float to ratio, another method
	Ratio<R> best_convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const;

	/// \brief convert ratio to float
	double convert_to_float() const;

	/// \brief overload the operator << for Ratio
    /// \param stream : input stream
	template<typename T>
	friend std::ostream& operator<< (std::ostream& stream, const Ratio<T> &r);	
    	
};

	template<typename R>
	std::ostream& operator<< (std::ostream& stream, const Ratio<R> &r) {		
    	stream << r.m_num << "/" << r.m_denom;
		return stream;
	}
	

	/// \brief return product of real and ratio
	template<typename R, typename T>
	Ratio<R> operator*(const T &n, const Ratio<R> &r){
		return r*n;
	}