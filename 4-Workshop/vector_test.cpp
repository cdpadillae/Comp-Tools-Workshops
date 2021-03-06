#define CATCH_CONFIG_MAIN  //This tells Catch to provide a main() - only cpp files
#include "catch2/catch.hpp"
#include "vector_ops.hpp"
#include <iostream>

const int N = 20;
const int A = 15;
const double precs = 1e-3;

std::vector<double> null_vector(N);
std::vector<double> const_vector(N, A);
std::vector<double> half_vector(N), opposite_vector(N), firstN_vector(N) ;
  

TEST_CASE( "Mean of a vector is computed", "[mean]" ) {
    //Tests for vectors with no special pattern
    REQUIRE(std::fabs(mean(null_vector) - 0.0) <= precs);
    REQUIRE(std::fabs(mean(const_vector)- A)  <= precs);
    
    //Vector of the form {15,0,15,0,15,0}
    int ii = 0;
    for(auto& x: half_vector){
        x = ii%2*A;
        ++ii;
    }
    ii = 0;
    
    //Vector of the form {-1,1,-1,1}
    for(auto& x: opposite_vector){
        x = ii%2 == 0 ? -1: 1;
        ++ii;
    }
    ii = 1;
    
    //First N natural Numbers
    for(auto& x: firstN_vector){
        x = ii;
        ++ii;
    }
    ii = 1;
    double mean_N = (N+1)/2.0;
    
    //Tests for vectors defined above
    REQUIRE(std::fabs(mean(half_vector) - A/2.0) <= precs);
    REQUIRE(std::fabs(mean(opposite_vector) - 0.0) <= precs);
    REQUIRE(std::fabs(mean(firstN_vector) - mean_N) <= precs);
}
