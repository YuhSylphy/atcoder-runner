#include <iostream>
#include <vector>
#include <yaml-cpp/yaml.h>

/**
 * 入出力パターン(1回分)
 */
struct Case {
	/**
	 * 入力値
	 */
	std::string input;
	/**
	 * 想定される出力値
	 */
	std::string output;
};

struct Definition {
	/**
	 * 問題形式
	 *
	 * - nonreciprocal
	 * - interactive
	 */
	std::string type;
	/**
	 * 入出力パターンリスト
	 */
	std::vector<Case> cases;
};

int run(std::string const& targetPath, std::string const& definitionPath) {
	std::cout << "target: " << targetPath << std::endl;
	std::cout << "definition: " << definitionPath << std::endl;
	auto const yaml = YAML::LoadAllFromFile(definitionPath);
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "usage: runner targetPath definitionPath" << argc << std::endl;
		return -1;
	}
	return run(argv[1], argv[2]);
}
