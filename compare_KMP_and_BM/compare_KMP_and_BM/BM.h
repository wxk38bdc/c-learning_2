#ifndef BM_H
#define BM_H

// 计算好后缀规则的移动距离
int GoodSuffix(int j, const std::string& pat) {
    int terminal = pat.length() - 1;
    int index = -1;
    j--;
    while (j >= 0) {
        if (pat[j] == pat[terminal]) {
            index = j;
            break;
        }
        else {
            j--;
        }
    }
    return terminal - index;
}

// 计算坏字符规则的移动距离
int BadChar(int j, char temp, const std::string& pat) {
    int index = -1;
    for (int i = j - 1; i >= 0; --i) {
        if (pat[i] == temp) {
            index = i;
            break;
        }
    }
    return (index == -1) ? j + 1 : j - index;
}

// Boyer-Moore搜索算法
int BMSearch(const std::string& txt, const std::string& pat) {
    int i = 0, j = 0;
    int txtLen = txt.length();
    int patLen = pat.length();
    int badvalue = 0, distance = 0;

    if (txtLen < patLen) {
        return -1;
    }

    // 初始化，从模式串的最后一位开始匹配
    i = patLen - 1;
    j = patLen - 1;

    while (i < txtLen) {
        if (txt[i] == pat[j]) {  // 字符匹配成功
            if (j == 0) {  // 完全匹配成功
                return i;
            }
            i--;
            j--;
        }
        else {  // 匹配失败
            if (j == patLen - 1) {  // 最后一位失败，使用坏字符规则
                badvalue = BadChar(j, txt[i], pat);
                i = i + patLen - 1 - j + badvalue;
                j = patLen - 1;  // 重置j
            }
            else {  // 中间字符匹配失败，比较坏字符和好后缀规则
                badvalue = BadChar(j, txt[i], pat);
                if (badvalue == -1) {
                    badvalue = pat.length();
                }
                distance = std::max(badvalue, GoodSuffix(j, pat));
                i = i + patLen - 1 - j + distance;  // 更新i的位置
                j = patLen - 1;  // 重置j
            }
        }
    }

    return -1;  // 没有匹配
}

int BMSearchWithCount(const std::string& txt, const std::string& pat, int& compareCount) {
    size_t txtLen = txt.length();
    size_t patLen = pat.length();
    compareCount = 0;  // 初始化字符比较次数

    // 检查边界，防止空串的情况
    if (patLen == 0 || txtLen == 0) return -1;

    int badvalue = 0, distance = 0;
    size_t i = patLen - 1;
    size_t j = patLen - 1;

    while (i < txtLen) {
        compareCount++;  // 每次字符比较时增加计数
        if (txt[i] == pat[j]) {
            if (j == 0) {
                return i;  // 匹配成功
            }
            i--;
            j--;
        }
        else {
            if (j == patLen - 1) {
                badvalue = BadChar(j, txt[i], pat);
                i = i + patLen - 1 - j + badvalue;
                j = patLen - 1;
            }
            else {
                badvalue = BadChar(j, txt[i], pat);
                if (badvalue == -1) {
                    badvalue = static_cast<int>(patLen);
                }
                distance = std::max(badvalue, GoodSuffix(j, pat));
                i = i + patLen - 1 - j + distance;
                j = patLen - 1;
            }
        }
    }

    return -1;  // 没有匹配
}


// 测试函数
void testBM() {
    std::string txt = "THERE IS A SIMPLE EXAMPLE";
    std::string pat = "EXAMPLE";

    std::cout << "Text: " << txt << std::endl;
    std::cout << "Pattern: " << pat << std::endl;

    int result = BMSearch(txt, pat);

    if (result != -1) {
        std::cout << "Pattern found at index: " << result << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }
}
// 新增测试函数
void testBMWithCount() {
    std::string txt = "THERE IS A SIMPLE EXAMPLE";
    std::string pat = "EXAMPLE";

    // 定义字符比较次数变量
    int compareCount = 0;

    // 调用 BMSearchWithCount 函数，接收匹配结果和字符比较次数
    int result = BMSearchWithCount(txt, pat, compareCount);

    std::cout << "Text: " << txt << std::endl;
    std::cout << "Pattern: " << pat << std::endl;

    // 输出匹配结果
    if (result != -1) {
        std::cout << "Pattern found at index: " << result << std::endl;
    }
    else {
        std::cout << "Pattern not found." << std::endl;
    }

    // 输出字符比较次数
    std::cout << "Total character comparisons in BM: " << compareCount << std::endl;
}

#endif // BM_H
