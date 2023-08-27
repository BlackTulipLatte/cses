#include <iostream>
#include <string>
#include <algorithm>
#include <set>

void generatePermutations(std::string str, int start, std::set<std::string>& result) {
    if (start == str.length() - 1) {
        result.insert(str);
        return;
    }

    for (int i = start; i < str.length(); ++i) {
        std::swap(str[start], str[i]);
        generatePermutations(str, start + 1, result);
        std::swap(str[start], str[i]);
    }
}

int main() {
    std::string input;
    std::cin >> input;

    std::set<std::string> result;
    generatePermutations(input, 0, result);

    std::cout << result.size() << "\n";
    for (const std::string& str : result) {
        std::cout << str << "\n";
    }

    return 0;
}
