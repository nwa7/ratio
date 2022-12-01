#pragma once 

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

    Ratio operator+(const Ratio &r) const;
    Ratio operator-(const Ratio &r) const;
    Ratio operator*(const Ratio &r) const;
    Ratio operator/(const Ratio &r) const;
    Ratio operator-() const;

    Ratio inverse() const;
    
    bool operator==(const Ratio &r) const;
    bool operator!=(const Ratio &r) const;
    bool operator>(const Ratio &r) const;
    bool operator<(const Ratio &r) const;
    bool operator>=(const Ratio &r) const;
    bool operator<=(const Ratio &r) const;

};