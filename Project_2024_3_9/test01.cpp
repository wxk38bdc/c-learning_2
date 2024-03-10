#include<iostream>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        int maxFruits = 0;
//        unordered_map<int, int> count;  // 用于存储当前窗口中每种水果的数量
//        int left = 0;  // 窗口的左边界
//
//        for (int right = 0; right < fruits.size(); ++right) {
//            count[fruits[right]]++;  // 将当前水果加入窗口
//
//            // 当窗口中的水果类型超过两种时，缩小窗口
//            while (count.size() > 2) {
//                count[fruits[left]]--;  // 从窗口中移除最左边的水果
//                if (count[fruits[left]] == 0) {
//                    count.erase(fruits[left]);  // 如果某种水果的数量减到0，则从map中移除
//                }
//                left++;  // 缩小窗口
//            }
//
//            // 更新最大收集的水果数量
//            maxFruits = max(maxFruits, right - left + 1);
//        }
//
//        return maxFruits;
//    }
//};

//class Solution {
//public:
//    bool isSame(int* s1, int* s2) {
//        for (int i = 0; i < 26; i++) {
//            if (s1[i] != s2[i]) return false;
//        }
//        return true;
//    }
//
//    vector<int> findAnagrams(string s, string p) {
//        if (s.size() < p.size()) return {};
//        vector<int> ret;
//        int hash_p[26] = { 0 }, hash_s[26] = { 0 };
//
//        // 记录p中的字母计数
//        for (char e : p) {
//            hash_p[e - 'a']++;
//        }
//
//        // 初始化第一个窗口
//        for (int i = 0; i < p.size(); i++) {
//            hash_s[s[i] - 'a']++;
//        }
//        if (isSame(hash_p, hash_s)) {
//            ret.push_back(0);
//        }
//
//        // 滑动窗口，动态更新计数
//        for (int i = p.size(); i < s.size(); i++) {
//            hash_s[s[i] - 'a']++;  // 包含新字符
//            hash_s[s[i - p.size()] - 'a']--;  // 排除旧字符
//
//            if (isSame(hash_p, hash_s)) {
//                ret.push_back(i - p.size() + 1);
//            }
//        }
//
//        return ret;
//    }
//};
