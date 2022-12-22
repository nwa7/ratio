#pragma once 



// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section introduction_sec What is it for?
/// This library was done for our Maths / Prog final project of IMAC 2
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

    public:

    Ratio(const int num = 1, const unsigned int denom =1);
    Ratio(const Ratio &r);
    ~Ratio()= default;

    void displayRatio() const;
    void reduce();
    int getNum();
    int getDenom();

    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator*(const Ratio &r) const;
    Ratio operator/(const Ratio &r) const;
    Ratio operator-() const;

    Ratio ratio_sqrt() const ;
    Ratio ratio_abs() const;
    int ratio_intpart() const;
    Ratio inverse() const;
    
    bool operator==(const Ratio &r) const;
    bool operator!=(const Ratio &r) const;
    bool operator>(const Ratio &r) const;
    bool operator<(const Ratio &r) const;
    bool operator>=(const Ratio &r) const;
    bool operator<=(const Ratio &r) const;

    Ratio convert_float_to_ratio(double x, const unsigned int nb_iter);
};