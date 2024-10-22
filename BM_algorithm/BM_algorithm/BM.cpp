#include"BM.h"

//void getRight(string pat, vector<int>& right)
//{
//	right.resize(256, -1);
//	for (int i = 0; i < (int)pat.size(); i++)
//		right[pat[i]] = i;
//}
//
//int Search(string txt, string pat, vector<int>& right)
//{
//	int M = txt.size();//主串的长度
//	int N = pat.size();//模式串的长度
//	int skip;//记录模式串相对于主串的位移
//	for (int i = 0; i <= M - N; i += skip)
//	{
//		skip = 0;
//		for (int j = N - 1; j >= 0; j--)
//		{
//			if (pat[j] != txt[i + j])
//			{
//				skip = j - right[txt[i + j]];
//				if (skip < 1)
//					skip = 1;
//				break;
//			}
//		}
//		if (skip == 0)
//			return i;
//	}
//	return -1;
//}
//
//void testBM()
//{
//	string txt = "ABACADABRAC";
//	string pat = "ABRA";
//	vector<int> right;
//	getRight(pat, right);
//	int pos = Search(txt, pat, right);
//	cout << pos << endl;
//}

vector<int> build_bad_table(const string& pattern)
{
	int table_size = 256;
	int pLen = pattern.size();
	vector<int> bad_table(table_size, pLen);//默认初始化全部为pLen，因为坏字符在模式串中不存在时，模式串向后移动pLen位
	for (int i = 0; i < pLen - 1; i++)
	{
		bad_table[pattern[i]] = pLen - 1 - i;//记录坏字符在模式串中的位置
	}
	return bad_table;
}

bool isPrefix(const string& pattern, int pos)
{
	int pLen = pattern.size();
	int suffixLen = pLen - pos;
	for (int i = 0; i < suffixLen; i++)
	{
		if (pattern[i] != pattern[pos + i])
			return false;
	}
	return true;
}

int suffixLength(const string& pattern, int pos)
{
	int pLen = pattern.size();
	int len = 0;
	while (pos >= 0 && pattern[pos] == pattern[pLen - 1])
	{
		len++;
		pos--;
		pLen--;
	}
	return len;
}

//vector<int> build_good_table(const string& pattern)
//{
//	int pLen = pattern.size();
//	vector<int> good_table(pLen);
//	int lastPrefixPos = pLen;
//	for (int i = pLen - 1; i >= 0; i--)
//	{
//		if (isPrefix(pattern, i + 1))
//		{
//			lastPrefixPos = i + 1;
//		}
//		good_table[pLen - 1 - i] = lastPrefixPos - i + pLen - 1;
//	}
//	for (int i = 0; i < pLen - 1; i++)
//	{
//		int suffix_len = suffixLength(pattern, i);
//		good_table[suffix_len] = pLen - 1 - i + suffix_len;
//	}
//	return good_table;
//}

vector<int> build_good_table(const string& pattern) {
	int pLen = pattern.size();
	vector<int> good_table(pLen);
	int lastPrefixPos = pLen;

	for (int i = pLen - 1; i >= 0; i--) {
		if (isPrefix(pattern, i + 1)) {
			lastPrefixPos = i + 1;
		}
		good_table[pLen - 1 - i] = lastPrefixPos - i + pLen - 1;
	}

	for (int i = 0; i < pLen - 1; i++) {
		int suffix_len = suffixLength(pattern, i);
		if (pattern[i - suffix_len] != pattern[pLen - 1 - suffix_len]) {
			good_table[pLen - 1 - suffix_len] = pLen - 1 - i + suffix_len;
		}
	}
	return good_table;
}


// Boyer-Moore 字符串匹配函数
int boyer_moore(const string& text, const string& pattern) {
	int tLen = text.size();
	int pLen = pattern.size();

	if (pLen == 0) return 0; // 空模式串处理

	// 构建坏字符和好后缀表
	vector<int> bad_table = build_bad_table(pattern);
	vector<int> good_table = build_good_table(pattern);

	int s = 0; // s 表示模式串相对于文本串的滑动位置
	while (s <= (tLen - pLen)) {
		int j = pLen - 1;

		// 从后向前检查是否匹配
		while (j >= 0 && pattern[j] == text[s + j])
			j--;

		// 如果匹配成功，返回匹配位置
		if (j < 0) {
			return s;
		}
		else {
			// 计算滑动的距离
			int bad_shift = bad_table[text[s + j]] - (pLen - 1 - j);
			int good_shift = good_table[j];
			s += max(bad_shift, good_shift);
		}
	}
	return -1; // 没有找到
}

// 测试函数
void test1() {
	string text = "HERE IS A SIMPLE EXAMPLE";
	string pattern = "EXAMPLE";

	int index = boyer_moore(text, pattern);
	if (index != -1) {
		cout << "Pattern found at index: " << index << endl;
	}
	else {
		cout << "Pattern not found in the text." << endl;
	}

	// 测试2：不存在的模式
	pattern = "NOTFOUND";
	index = boyer_moore(text, pattern);
	if (index != -1) {
		cout << "Pattern found at index: " << index << endl;
	}
	else {
		cout << "Pattern not found in the text." << endl;
	}
}