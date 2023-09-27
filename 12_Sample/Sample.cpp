#include <cstddef>
#include <ctime>
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>

int main()
{
	std::vector values{ 1,2,3,4,5,6,7,8,9,10 };
	const size_t numberOfSamples{ 5 };
	std::vector<int> samples(numberOfSamples);

	std::random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	std::default_random_engine engine{ static_cast<std::default_random_engine::result_type>(seed) };

	for (int i{ 0 }; i < 2; ++i) {
		sample(cbegin(values), cend(values), begin(samples), numberOfSamples, engine);

		for (const auto& sample : samples) { std::cout << sample << " "; }
		std::cout << std::endl;
	}

	return 0;
}
