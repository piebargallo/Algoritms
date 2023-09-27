#include <random>
#include <iostream>

int main()
{
	std::vector values{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	std::random_device seeder;
	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };
	std::default_random_engine engine{ static_cast<std::default_random_engine::result_type>(seed) };

	for (int i{ 0 }; i < 2; ++i) {
		shuffle(begin(values), end(values), engine);

		for (const auto& value : values) { std::cout << value << " "; }
		std::cout << std::endl;
	}
}