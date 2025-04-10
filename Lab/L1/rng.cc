#include "rng.hh"

#include <iostream>

/**
 * @brief Inicializa un generador de números aleatorios declarado previamente
 */
void rng_init(RNG& rng) {
	rng.generator = std::mt19937(rng.device());
}

/**
 * @brief Genera un entero al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
int rng_generate(RNG& rng, int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(rng.generator);
}

/**
 * @brief Genera un real al azar 'x' que cumple: x >= min && x <= max, 
 * uniformemente entre ambos límites
 * 
 * @param rng El generador de números al azar
 * @param min Valor mínimo que puede tomar `x`
 * @param max Valor máximo que puede tomar `x`
 */
double rng_generate(RNG& rng, double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(rng.generator);
}

int main() {
	RNG rng;
	rng_init(rng);

	std::vector<int> histograma(10, 0);
	for (int i = 0; i < 1000000; i++) {
		int x = rng_generate(rng, 0, 9);
		histograma[x]++;
	}

	for (int i = 0; i < histograma.size(); i++) {
		std::cout << i << ": " << histograma[i] << std::endl;
	}

    std::cout << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << rng_generate(rng, 0.0, 1.0) << std::endl;
    }
}