#pragma once 



// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
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

class Ratio{
    private : 
    int m_num;
    unsigned int m_denom;
    //double x;
	/// \brief Ratio is composed of two members : a numerator in int and a denominator in uint


    public:

	/// \brief constructor from a numerator & a denominator, return 1 in Ratio if called empty 
	/// \param num : numerator
	/// \param denom : denominator
    Ratio(const int num = 1, const unsigned int denom =1);


	/// \brief copy constructor
	/// \param r : Ratio
    Ratio(const Ratio &r);


	Ratio(const double &x);

	/// \brief default destructor
    ~Ratio()= default;

	/// \brief display num/denom
    void displayRatio() const;

	/// \brief return the Ratio in irreducible form
    void reduce();
    
	/// \brief getter numerator
    int getNum();

	/// \brief getter denominator
    int getDenom();

	/// \brief setter numerator
    void setNum(int num);

	/// \brief setter denominator
    void setDenom(unsigned int denom);

	/// \brief sum of *this and r
    Ratio operator+(const Ratio &r) const;

	/// \brief substract r to *this 
    Ratio operator-(const Ratio &r) const;

	/// \brief product *this and r
    Ratio operator*(const Ratio &r) const;

	/// \brief product *this and f
	/// \param x : float
    Ratio operator*(const float &x) const;

	/// \brief product *this and n
	Ratio operator*(const int &n) const;

	/// \brief division of *this by r
    Ratio operator/(const Ratio &r) const;

	/// \brief unary minus
    Ratio operator-() const;

	/// \brief square root of *this
    Ratio ratio_sqrt() const ;

	/// \brief power of *this
    Ratio ratio_pow(const int &p) const ;


	/// \brief power of *this
    Ratio ratio_pow2(const int &p) const ;

	/// \brief return *this with an absolute numerator
    Ratio ratio_abs() const;

	/// \brief return euclide division of numerator divised by denominator
    int ratio_intpart() const;

	/// \brief return inverse of *this
    Ratio inverse() const;
    
	/// \brief test if *this and r are equal
    bool operator==(const Ratio &r) const;

	/// \brief test if *this and r are different
    bool operator!=(const Ratio &r) const;

	/// \brief test if *this is strictly greater than r 
    bool operator>(const Ratio &r) const;

	/// \brief test if r is striclty greater than *this
    bool operator<(const Ratio &r) const;

	/// \brief test if *this is greater than r or equal to r
    bool operator>=(const Ratio &r) const;

	/// \brief test if r is greater than *this or equal to *this
    bool operator<=(const Ratio &r) const;

	/// \brief returns closest value to num
	double compare_closest(const double &num, const double &a, const double &b) const;

	/// \brief convert float to ratio
	/// \param max_nb_iter : number of iterations
	/// \param precision: epsilon error 
    Ratio convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const ;

	Ratio best_convert_float_to_ratio(double x, const unsigned int max_nb_iter, const double precision) const;

	double convert_to_float() const;
};