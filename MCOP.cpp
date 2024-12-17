#include <iostream>
#include <random>

double monteCarloOptionPrice(double S, double K, double r, double T, double sigma, int numSimulations, bool isCall) {
    std::mt19937_64 rng(std::random_device{}());
    std::normal_distribution<double> normal(0.0, 1.0);

    double payoffSum = 0.0;
    for (int i = 0; i < numSimulations; i++) {
        double ST = S * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * normal(rng));
        payoffSum += isCall ? std::max(ST - K, 0.0) : std::max(K - ST, 0.0);
    }

    return exp(-r * T) * (payoffSum / numSimulations);
}