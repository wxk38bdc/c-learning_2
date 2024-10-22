#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void getRight(string pat, vector<int>& right);

int Search(string txt, string pat, vector<int>& right);

void testBM();