#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <fstream>
#include <chrono>
using namespace std;
#include"KMP.h"
#include"BM.h"

// 读取文件内容并将每行存入vector
std::vector<std::string> readFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

void testPerformance() {
    std::vector<std::string> lines = readFile("C:\\Users\\WangXikang\\OneDrive\\Desktop\\test_02.txt");

    std::string mainString = lines[0]; // 主串

    // 短模式串
    std::vector<std::string> shortPatterns(lines.begin() + 1, lines.begin() + 10001);

    // 中模式串
    std::vector<std::string> mediumPatterns(lines.begin() + 10001, lines.begin() + 20001);

    // 长模式串
    std::vector<std::string> longPatterns(lines.begin() + 20001, lines.begin() + 30001);

    // KMP和BM算法的时间测试
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : shortPatterns) {
        KMPSearch(mainString, pattern);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "KMP on short patterns took: " << elapsed.count() << " seconds.\n";

    start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : shortPatterns) {
        BMSearch(mainString, pattern);
    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on short patterns took: " << elapsed.count() << " seconds.\n";

    // 中模式串测试
    start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : mediumPatterns) {
        KMPSearch(mainString, pattern);
    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "KMP on medium patterns took: " << elapsed.count() << " seconds.\n";

    start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : mediumPatterns) {
        BMSearch(mainString, pattern);
    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on medium patterns took: " << elapsed.count() << " seconds.\n";

    // 长模式串测试
    start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : longPatterns) {
        KMPSearch(mainString, pattern);
    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "KMP on long patterns took: " << elapsed.count() << " seconds.\n";

    start = std::chrono::high_resolution_clock::now();

    for (const auto& pattern : longPatterns) {
        BMSearch(mainString, pattern);
    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on long patterns took: " << elapsed.count() << " seconds.\n";
}
int main()
{
	//testKMP();
	//testBM();
	testPerformance();
	return 0;
}