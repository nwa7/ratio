#include <iostream>
#include "ratio.hpp"
#include "math.h"
#include <iomanip> 
#include <random>
#include <chrono>
#include <string>

double relative_error(const double& estimated, const double& expected){
    return std::abs( (estimated - expected ) / expected );
}


double test_precision(const double& estimated, const double& expected, const unsigned int nbRuns){
    long double sum = 0;
    for(unsigned int i=0; i<nbRuns; ++i){
    sum+= std::abs( (estimated - expected ) / expected );
    }

    return 100 * sum / nbRuns;
}


void print_data(const std::string methodName, const double precision, const double time){

    std::cout << methodName 
              << " : [mean error: " << std::fixed  << std::internal << std::setw(7) << std::setprecision(4) << std::setfill('0') << precision << " % ]"
              << "\t [time: "  << std::fixed << std::setprecision(4) << time << " s]" << std::endl;
}


int main(){
    
    // random setup
    const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    // distribution
    const int max_range_double = 1000;
    std::uniform_real_distribution<double> distrib(-max_range_double,max_range_double);
    std::uniform_real_distribution<double> distrib2(0, max_range_double);
    std::uniform_real_distribution<double> distrib3(0, 1.5707);
    // computation options
    const unsigned int nbRuns = 100000;

    // empty version
    generator.seed(seed);
    auto start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        const volatile double value = distrib(generator);
    }
    auto elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_empty = elapsed;


    //Variables used for tests
    const double x = distrib(generator);
    const double x2 = distrib2(generator);
    const double x3 = distrib3(generator);

    Ratio<long int> r(x);
    Ratio<long int> r2(x2);
    Ratio<long int> r3(x3);

    // convert
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <int> convert(distrib(generator));
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_convert = elapsed;


    // sqrt newton
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <long int> value = r2.ratio_sqrt();
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_sqrt = elapsed;


    // pow recursive
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <long int> value = r.ratio_pow(3);
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_pow = elapsed;


    // exp horner
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <long int> value = r.ratio_exp();
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_exp = elapsed;

    // cos taylor
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <long int> value = r.ratio_cos();
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_cos = elapsed;


    // sin taylor
    generator.seed(seed);
    start = std::chrono::system_clock::now();
    for(unsigned int i=0; i<nbRuns; ++i){
        Ratio <long int> value = r.ratio_sin();
    }
    elapsed = std::chrono::system_clock::now() - start;
    std::chrono::duration<double> elapsed_sin = elapsed;



    ///////////////////////////////////////////////////////////////////////////
    ///PRECISION TEST
    double precision_convert = test_precision(r.convert_to_float(), x, 1000);

    double precision_sqrt = test_precision((r.ratio_pow(2)).convert_to_float(), std::pow(x,2), 1000);

    double precision_pow = test_precision((r2.ratio_sqrt()).convert_to_float(), std::sqrt(x2), 1000);

    double precision_exp = test_precision((r3.ratio_exp()).convert_to_float(), std::exp(x3), 100);

    double precision_cos= test_precision((r3.ratio_cos()).convert_to_float(), std::cos(x3), 1000);
    double precision_sin= test_precision((r3.ratio_sin()).convert_to_float(), std::sin(x3), 1000);


    ///////////////////////////////////////////////////////////////////////////
    ///PRINT DATA


    print_data("convert     ", precision_convert,  (elapsed_convert  - elapsed_empty).count());

    print_data("sqrt        ", precision_sqrt,  (elapsed_sqrt  - elapsed_empty).count());

    print_data("pow         ", precision_pow,  (elapsed_pow  - elapsed_empty).count());

    print_data("exp         ", precision_exp,  (elapsed_exp  - elapsed_empty).count());

    print_data("cos         ", precision_cos,  (elapsed_cos  - elapsed_empty).count());

    print_data("sin         ", precision_sin,  (elapsed_sin  - elapsed_empty).count());

    return 0;
}