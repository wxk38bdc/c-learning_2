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
    std::vector<std::string> lines = readFile("C:\\Users\\WangXikang\\OneDrive\\Desktop\\test_01.txt");

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

void testPerformanceWithCount() {
    // 读取测试文件
    std::vector<std::string> lines = readFile("C:\\Users\\WangXikang\\OneDrive\\Desktop\\test_01.txt");

    std::string mainString = lines[0];  // 主串

    // 短模式串
    std::vector<std::string> shortPatterns(lines.begin() + 1, lines.begin() + 10001);

    // 中模式串
    std::vector<std::string> mediumPatterns(lines.begin() + 10001, lines.begin() + 20001);

    // 长模式串
    std::vector<std::string> longPatterns(lines.begin() + 20001, lines.begin() + 30001);

    // 统计运行时间和字符比较次数

    // --- 短模式串测试 ---
    long long totalKMPCompareCount = 0;
    long long totalBMCompareCount = 0;

    // 测试 KMP
    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : shortPatterns) {
        std::pair<std::vector<int>, int> result = KMPSearchWithCount(mainString, pattern);
        totalKMPCompareCount += result.second;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "KMP on short patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total KMP comparisons on short patterns: " << totalKMPCompareCount << std::endl;

    // 测试 BM
    start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : shortPatterns) {
        int compareCount = 0;
        BMSearchWithCount(mainString, pattern, compareCount);
        totalBMCompareCount += compareCount;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on short patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total BM comparisons on short patterns: " << totalBMCompareCount << std::endl;

    // --- 中模式串测试 ---
    totalKMPCompareCount = 0;
    totalBMCompareCount = 0;

    // 测试 KMP
    start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : mediumPatterns) {
        std::pair<std::vector<int>, int> result = KMPSearchWithCount(mainString, pattern);
        totalKMPCompareCount += result.second;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "KMP on medium patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total KMP comparisons on medium patterns: " << totalKMPCompareCount << std::endl;

    // 测试 BM
    start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : mediumPatterns) {
        int compareCount = 0;
        BMSearchWithCount(mainString, pattern, compareCount);
        totalBMCompareCount += compareCount;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on medium patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total BM comparisons on medium patterns: " << totalBMCompareCount << std::endl;

    // --- 长模式串测试 ---
    totalKMPCompareCount = 0;
    totalBMCompareCount = 0;

    // 测试 KMP
    start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : longPatterns) {
        std::pair<std::vector<int>, int> result = KMPSearchWithCount(mainString, pattern);
        totalKMPCompareCount += result.second;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "KMP on long patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total KMP comparisons on long patterns: " << totalKMPCompareCount << std::endl;

    // 测试 BM
    start = std::chrono::high_resolution_clock::now();
    for (const auto& pattern : longPatterns) {
        int compareCount = 0;
        BMSearchWithCount(mainString, pattern, compareCount);
        totalBMCompareCount += compareCount;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "BM on long patterns took: " << elapsed.count() << " seconds.\n";
    std::cout << "Total BM comparisons on long patterns: " << totalBMCompareCount << std::endl;
}
int main()
{
	//testPerformance();
	//testKMPWithCount();
	//testBMWithCount();
	testPerformanceWithCount();
	return 0;
}