#include"date.h"

int main()
{
	Date d1(2020,1,1);
	//cin >> d1;
	cout << d1 << endl;
	Date d2(2023,12,28);
	d2.Print();
	cout << d1 - d2 << endl;
	return 0;
}