#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <format>

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	MyClass(std::string str) : m_str{ std::move(str) } {}
	virtual ~MyClass() = default;

	// Move assignment operator
	MyClass& operator=(MyClass&& rhs) noexcept {
		if (this == &rhs) { return *this; }
		m_str = std::move(rhs.m_str);
		std::cout << std::format("Move operator= (m_str={})", m_str) << std::endl;
		return *this;
	}

	void setString(std::string str) { m_str = move(str); }
	const std::string& getString() const { return m_str; }

private:
	std::string m_str;
};

int main()
{
	std::vector<MyClass> vecSrc{ MyClass { "a" }, MyClass{ "b" }, MyClass{ "c" } };
	std::vector<MyClass> vecDst(vecSrc.size());
	move(begin(vecSrc), end(vecSrc), begin(vecDst));
	for (const auto& c : vecDst) { std::cout << c.getString() << " "; }

	return 0;
}
