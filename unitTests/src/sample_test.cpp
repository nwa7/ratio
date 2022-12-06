#include <random>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <gtest/gtest.h>

#include "ratio.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	Ratio r;
	ASSERT_EQ (r.getDenom(), 1);
}


TEST (RatioConstructor, copyConstructor) { 


    const int maxNb= 1000; 
    std::mt19937_64 myGenerator(0);
    std::uniform_int_distribution<int> uniformDistributionValue(-maxNb,maxNb);
    auto gen = std::bind(uniformDistributionValue, myGenerator);

    for(int run=0; run<100; ++run){
        Ratio r1(gen(),gen());
        Ratio r2(r1);
        r1.displayRatio();
        ASSERT_EQ (r1.getNum(), r2.getNum());
        ASSERT_EQ (r1.getDenom(), r2.getDenom());
    }

}

