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