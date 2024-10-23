#ifndef KMP_H
#define KMP_H

// 计算部分匹配表 (LPS数组)
void computeLPSArray(const std::string& pat, std::vector<int>& lps) {
    int M = pat.length();
    int len = 0;  // 当前最长相同前后缀的长度
    lps[0] = 0;   // lps[0] 永远是 0
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP搜索算法
std::vector<int> KMPSearch(const std::string& txt, const std::string& pat) {
    int N = txt.length();
    int M = pat.length();

    // 用于存储匹配结果的起始索引
    std::vector<int> result;
    if (M == 0 || N == 0) return result;  // 防止空串的情况

    // 计算部分匹配表
    std::vector<int> lps(M);
    computeLPSArray(pat, lps);

    int i = 0;  // txt 的索引
    int j = 0;  // pat 的索引
    while (i < N) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == M) {
            // 找到模式串，记录下匹配的起始索引
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return result;
}

// 新增函数：计算KMP算法中的字符比较次数
std::pair<std::vector<int>, int> KMPSearchWithCount(const std::string& txt, const std::string& pat) {
    size_t N = txt.length();
    size_t M = pat.length();
    int compareCount = 0;  // 记录字符比较次数

    // 检查边界，防止空串的情况
    if (M == 0 || N == 0) return { std::vector<int>(), compareCount };

    std::vector<int> lps(M);
    computeLPSArray(pat, lps);

    std::vector<int> result;
    size_t i = 0;  // txt 的索引
    size_t j = 0;  // pat 的索引
    while (i < N) {
        compareCount++;  // 每次字符比较时增加计数
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == M) {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return { result, compareCount };  // 返回匹配结果和字符比较次数
}



// 测试函数
void testKMP() {
    std::string txt = "ABABDABACDABABCABAB";
    std::string pat = "ABABCABAB";

    std::vector<int> matches = KMPSearch(txt, pat);

    std::cout << "Text: " << txt << std::endl;
    std::cout << "Pattern: " << pat << std::endl;

    if (matches.empty()) {
        std::cout << "Pattern not found." << std::endl;
    }
    else {
        std::cout << "Pattern found at index: ";
        for (int index : matches) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
}


void testKMPWithCount() {
    std::string txt = "ABABDABACDABABCABAB";
    std::string pat = "ABABCABAB";

    // 调用 KMPSearchWithCount 函数，接收匹配结果和比较次数
    std::pair<std::vector<int>, int> result = KMPSearchWithCount(txt, pat);
    std::vector<int> matches = result.first;
    int compareCount = result.second;

    std::cout << "Text: " << txt << std::endl;
    std::cout << "Pattern: " << pat << std::endl;

    // 输出匹配结果
    if (matches.empty()) {
        std::cout << "Pattern not found." << std::endl;
    }
    else {
        std::cout << "Pattern found at index: ";
        for (int index : matches) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }

    // 输出字符比较次数
    std::cout << "Total character comparisons in KMP: " << compareCount << std::endl;
}


#endif // KMP_H
