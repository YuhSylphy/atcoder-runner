// demangle /////////////////////////////////////////////////////////////
#include <cxxabi.h>
#include <iostream>
#include <memory>
std::ostream& operator<<(std::ostream& os, std::type_info const& type) {
	int status;
	std::unique_ptr<char> ptr(abi::__cxa_demangle(type.name(), 0, 0, &status));
	if (ptr) {
		os << abi::__cxa_demangle(type.name(), 0, 0, &status);
	} else {
		switch (status) {
		case -1: os << "memory allocation failure";
		case -2: os << "invalid mangled name";
		case -3: os << "invalid arguments";
		default: os << "Shouldn't reach here";
		}
	}
	return os;
}
// demangle /////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>

int main() {
	std::cout << typeid(0ULL) << std::endl;
	std::cout << typeid(std::unordered_map<unsigned long long, std::vector<unsigned long long>>()) << std::endl;

	return 0;
}
