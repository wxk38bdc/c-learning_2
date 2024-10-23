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

#endif // KMP_H
