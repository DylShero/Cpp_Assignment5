/**
 * @file assignment4c.cc
 * @brief  Main function for assignment4c. Assignment 5, 5614
 * 	Using RNG and valarrays to estimate mean and variance of a lognormal distribution
 * 	
 * @author Dylan Sheridan
 * @version 1.0
 * @date 2026-04-06
 */
#include <valarray>
#include <algorithm>
#include <random>
#include <functional>
#include <print>

int main(void)
{
    std::valarray<double> results(10000);
    //RNG engine
    std::ranlux48 engine {};
    std::lognormal_distribution<double> dist {0.0, 1.0};

    //Bind RNG engine to distribution
    auto rng = std::bind(dist, engine);

    std::generate(std::begin(results), std::end(results), rng);

    //Mean(first moment)
    double mean = results.sum() / results.size();

    results *= results;

    double secondMoment = results.sum() / results.size();

    double variance = secondMoment - (mean * mean);

    std::println("Mean = {}", mean);

    std::println("Variance = {}", variance);

    return 0;
}