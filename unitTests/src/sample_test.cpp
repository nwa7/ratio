#include <random>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <gtest/gtest.h>

#include "ratio.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	Ratio<int> r;
	ASSERT_EQ (r.getDenom(), 1);
}


TEST (RatioConstructor, copyConstructor) { 


    const int maxNb= 1000; 
    std::mt19937_64 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

    for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),gen());
        Ratio<int> r2(r1);
        ASSERT_EQ (r1.getNum(), r2.getNum());
        ASSERT_EQ (r1.getDenom(), r2.getDenom());
    }

}

/////////////////////////////////////////////////////
// Arithmetic operators


TEST (RatioArithmetic, addition) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2(gen(),(uint)gen());
        Ratio<int> r3 = r1 + r2;
        ASSERT_EQ((r1.getNum()*r2.getDenom()+r2.getNum()*r1.getDenom())*r3.getDenom(), r3.getNum()*r1.getDenom()*r2.getDenom());
	}
}


TEST (RatioArithmetic, soustraction) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2(gen(),(uint)gen());
        Ratio<int> r3 = r1 - r2;
        ASSERT_EQ((r1.getNum()*r2.getDenom()-r2.getNum()*r1.getDenom())*r3.getDenom(), r3.getNum()*r1.getDenom()*r2.getDenom());
	}
}


TEST (RatioArithmetic, multiplication) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2(gen(),(uint)gen());
        Ratio<int> r3 = r1 * r2;
        ASSERT_EQ((r1.getNum()*r2.getNum())*r3.getDenom(), r3.getNum()*r1.getDenom()*r2.getDenom());
	}
}

TEST (RatioArithmetic, division) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2(gen(),(uint)gen());
        Ratio<int> r3 = r1 / r2;
        ASSERT_EQ((r1.getNum()*r2.getDenom())*r3.getDenom(), r3.getNum()*r1.getDenom()*r2.getNum());
	}
}

TEST (RatioArithmetic, unaryMinus) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2 = -r1;
        ASSERT_EQ( r1.getNum(), -r2.getNum());
        ASSERT_EQ( r1.getDenom(), r2.getDenom());
	}
}

TEST (RatioArithmetic, inverse ) { 
    const int maxNb= 1000; 
	std::mt19937 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
        Ratio<int> r1(gen(),(uint)gen());
        Ratio<int> r2 = r1.inverse();
        r1.displayRatio();
        r2.displayRatio();
        ASSERT_EQ( r2.getNum()*r1.getNum(), r2.getDenom()*r1.getDenom());
    }
}
/////////////////////////////////////////////////////
// sqrt

TEST (Ratiosqrt, basic) { 

    Ratio <int> r(4,1);
    double r_sqrt = (r.ratio_sqrt()).convert_to_float();
    double r_stdsqrt = std::sqrt(4);
    ASSERT_NEAR (r_stdsqrt, r_sqrt , 0.0000001);    

}


TEST (Ratiosqrt, float_nb) { 

    Ratio <int> r(6.245);
    double r_sqrt = (r.ratio_sqrt()).convert_to_float();
    double r_stdsqrt = std::sqrt(6.245);
    ASSERT_NEAR (r_stdsqrt, r_sqrt , 0.002);    

}


TEST (Ratiosqrt, precision) { 


    const int maxNb= 10000; 
    std::mt19937_64 myGenerator(0);
    std::uniform_real_distribution<float> uniformDistributionValue(0,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);
    
    for(int run=0; run<10000; ++run){
        const double x = gen();
        Ratio<long int> r(x);
        double std_sqrt = std::sqrt(x);
        double ratio_sqrt = (r.ratio_sqrt()).convert_to_float();
        ASSERT_NEAR (std_sqrt, ratio_sqrt, 0.2);       
    }

}



/////////////////////////////////////////////////////
// power

TEST (Ratiopower, basic) { 

    Ratio <int> r(2,1);
    double r_pow = (r.ratio_pow(4)).convert_to_float();
    double r_stdpow = std::pow(2,4);
    ASSERT_NEAR (r_stdpow, r_pow , 0.0000001);  
}  



TEST (Ratiopower, float_nb) { 

    Ratio <int> r(-7.25);
    double r_pow = (r.ratio_pow(3)).convert_to_float();
    double r_stdpow = std::pow(-7.25,3);
    ASSERT_NEAR (r_stdpow, r_pow , 0.0000001);  
}  


TEST (Ratiopower, precision) { 


    const int maxNb= 15; 
    std::mt19937_64 myGenerator(0);
    std::uniform_real_distribution<float> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);
    
    for(int run=0; run<10000; ++run){
        const double x = gen();
        Ratio<long int> r(x);
        double std_pow = std::pow(x,2);
        double ratio_pow = (r.ratio_pow(2)).convert_to_float();
        ASSERT_NEAR (std_pow, ratio_pow, 5.);       
    }

}



/////////////////////////////////////////////////////
// exp
TEST (Ratioexp, basic) { 

    Ratio <int> r(20,2);
    double r_exp = (r.ratio_exp()).convert_to_float();
    double r_stdexp = std::exp(10);
    ASSERT_NEAR (r_stdexp, r_exp , 0.05);  
}  

TEST (Ratioexp, float_nb) { 

    Ratio <int> r(2.5);
    double r_exp = (r.ratio_exp()).convert_to_float();
    double r_stdexp = std::exp(2.5);
    ASSERT_NEAR (r_stdexp, r_exp , 0.001);  
}  

TEST (Ratioexp, precision) { 


    const int maxNb= 5; 
    std::mt19937_64 myGenerator(0);
    std::uniform_real_distribution<float> uniformDistributionValue(0,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);
    
    for(int run=0; run<10000; ++run){
        const double x = gen();
        Ratio<long int> r(x);
        double std_exp = std::exp(x);
        double ratio_exp = (r.ratio_exp()).convert_to_float();
        ASSERT_NEAR (std_exp, ratio_exp, 20.);       
    }

}


/////////////////////////////////////////////////////
// cos

TEST (Ratiocos, float_nb) { 

    Ratio <int> r(1.047);
    double r_exp = (r.ratio_cos()).convert_to_float();
    double r_stdexp = std::cos(1.0471);
    ASSERT_NEAR (r_stdexp, r_exp , 0.0001);  
}

TEST (Ratiocos, float_nb_neg) { 

    Ratio <int> r(-1.047);
    double r_exp = (r.ratio_cos()).convert_to_float();
    double r_stdexp = std::cos(-1.0471);
    ASSERT_NEAR (r_stdexp, r_exp , 0.0001);  
}


TEST (Ratiocos, precision) { 

    const double maxNb= 1.5707; //PI/2 
    std::mt19937_64 myGenerator(0);
    std::uniform_real_distribution<float> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);
    
    for(int run=0; run<10000; ++run){
        const double x = gen();
        Ratio<long int> r(x);
        double std_cos = std::cos(x);
        double ratio_cos = (r.ratio_cos()).convert_to_float();
        ASSERT_NEAR (std_cos, ratio_cos, 0.08);       
    }

}


/////////////////////////////////////////////////////
// sin

TEST (Ratiosin, float_nb) { 

    Ratio <int> r(-1.5708);
    double r_sin = (r.ratio_sin()).convert_to_float();
    double r_stdsin = std::sin(1.5708);
    ASSERT_NEAR (r_stdsin, r_sin , 0.000001);  
}

TEST (Ratiosin, float_nb_neg) { 

    Ratio <int> r(-1.5708);
    double r_sin = (r.ratio_sin()).convert_to_float();
    double r_stdsin = std::sin(1.5708);
    ASSERT_NEAR (r_stdsin, r_sin , 0.000001);  
}



TEST (Ratiosin, precision) { 

    const double maxNb= 1.5707; //PI/2 
    std::mt19937_64 myGenerator(0);
    std::uniform_real_distribution<float> uniformDistributionValue(0,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);
    
    for(int run=0; run<10000; ++run){
        const double x = gen();
        Ratio<long int> r(x);
        double std_sin = std::sin(x);
        double ratio_sin = (r.ratio_sin()).convert_to_float();
        ASSERT_NEAR (std_sin, ratio_sin, 0.2);       
    }

}