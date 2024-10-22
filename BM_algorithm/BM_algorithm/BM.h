#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


//void getRight(string pat, vector<int>& right);

//int Search(string txt, string pat, vector<int>& right);

//void testBM();


vector<int> build_bad_table(const string& pattern);//构建坏字符表
vector<int> build_good_table(const string& pattern);//构建好后缀表
bool isPrefix(const string& pattern, int pos);//判断是否是后缀
int suffixLength(const string& pattern, int pos);//计算后缀长度
int boyer_moore(const string& text, const string& pattern);//Boyer-Moore算法
void test1();