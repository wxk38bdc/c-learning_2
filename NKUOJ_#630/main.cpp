/*
题目描述
有一组卡牌，上面写着1~13或者A~M，你随机抽分到了其中若干张卡牌，其中两张数字相同或者字母相同的卡牌可以配对。你需要将分到的卡牌配对，然后弃置这些成对的牌，最终将剩余的卡牌按照数字的升序或字母表的顺序输出。

请编写实现类似功能的模板类，要求:模块接受的数据类型为int类型和char类型，用以存储为数字1~13或者字符A~M，玩家分到的手牌上限是20张，玩家初始状态为不超过20的随机数量的卡牌，在弃置所有配对牌(match方法)之后，将剩余手牌按从小到大输出展示(show方法)。

Class myCards
T cards[MaxSize];
Int count;
MyCards(T*a，int size){//构造函数，传入初始手牌数组
……
Match();;//弃置配对牌操作
//展示手牌操作Show();
输入:
输入三行，第一行为一个数字1或者0，1表示接下来输入的卡牌为数字1到13;0表示字母A到M，第二行为给用户分发的初始手牌数量为1到20，第三行为给用户分发的手牌。

输出:
输出为两行，第一行为弃置配对牌之后的剩余手牌数量，第二行为弃置配对牌之后的手牌输出，用空格分隔，行尾无空格。当剩余手牌数量为0时，第二行输出WIN。

样例输入1：
1
4
3 13 3 13
样例输出1：
0
WIN
样例输入2：
1
4
3 1 3 13
样例输出2：
2
1 13
注意：必须实现类模板，否则计0分
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<class T>
class myCards
{
private:
	vector<T>cards;
public:
	myCards(T* a, int size)
	{
		for (int i = 0; i < size; i++)cards.push_back(a[i]);
	}
	void Match()
	{
		sort(cards.begin(), cards.end());
		auto it = cards.begin();
		while (it != cards.end())
		{
			if (it + 1 != cards.end() && *it == *(it + 1))
			{
				it = cards.erase(it);
				it = cards.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
	void Show()
	{
		cout << cards.size() << endl;
		if (cards.size() == 0)
		{
			cout << "WIN" << endl;
		}
		else
		{
			for (auto& e : cards)
			{
				cout << e << " ";
			}
			cout << endl;
		}

	}
};

int main()
{
	int type;//1:数字,0:字母
	cin >> type;
	int cardNum;
	cin >> cardNum;
	if (type == 1)
	{
		int card[cardNum];
		for (int i = 0; i < cardNum; i++)
		{
			cin >> card[i];
		}
		myCards<int> mC(card, cardNum);
		mC.Match();
		mC.Show();
	}
	else
	{
		char card[cardNum];
		for (int i = 0; i < cardNum; i++)
		{
			cin >> card[i];
		}
		myCards<char> mC(card, cardNum);
		mC.Match();
		mC.Show();
	}
	return 0;
}
