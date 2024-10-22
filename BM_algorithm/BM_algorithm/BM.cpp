#include"BM.h"

void getRight(string pat, vector<int>& right)
{
	right.resize(256, -1);
	for (int i = 0; i < (int)pat.size(); i++)
		right[pat[i]] = i;
}

int Search(string txt, string pat, vector<int>& right)
{
	int M = txt.size();//主串的长度
	int N = pat.size();//模式串的长度
	int skip;//记录模式串相对于主串的位移
	for (int i = 0; i <= M - N; i += skip)
	{
		skip = 0;
		for (int j = N - 1; j >= 0; j--)
		{
			if (pat[j] != txt[i + j])
			{
				skip = j - right[txt[i + j]];
				if (skip < 1)
					skip = 1;
				break;
			}
		}
		if (skip == 0)
			return i;
	}
	return -1;
}

void testBM()
{
	string txt = "ABACADABRAC";
	string pat = "ABRA";
	vector<int> right;
	getRight(pat, right);
	int pos = Search(txt, pat, right);
	cout << pos << endl;
}