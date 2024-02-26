#define _CRT_SECURE_NO_WARNINGS
#include"myvector.h"
#include<vector>

//#include<iostream>
//#include<algorithm>
//#include<climits>
//using namespace std;
//int main()
//{
//    long long n;
//    cin >> n;
//    long long* a = new long long[n];
//    long long* b = new long long[n];
//    long long i = 0, j = 0;
//    for (i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
//    for (i = 0; i < n; i++)
//    {
//        cin >> b[i];
//    }
//    sort(a, a + n);
//    sort(b, b + n);
//    long long ret = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (a[i] == -1)continue;
//        for (j = 0; j < n; j++)
//        {
//            if (b[j] == INT_MAX)continue;
//            if (2 * a[i] > b[j])
//            {
//                a[i] = -1;
//                b[j] = INT_MAX;
//                ret++;
//                break;
//            }
//        }
//    }
//    cout << ret;
//    delete[]a;
//    delete[]b;
//    return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int* a = new int[n];
//    int* b = new int[n];
//
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> b[i];
//    }
//
//    sort(a, a + n);
//    sort(b, b + n);
//
//    int ret = 0;
//    int i = 0, j = n - 1; // i starts from the beginning of a, j starts from the end of b
//    while (i < n && j >= 0) {
//        if (2 * a[i] <= b[j]) {
//            // b[j] is too large to form a triangle with a[i], decrement j
//            j--;
//        }
//        else {
//            // Found a valid pair, increment ret and move both pointers
//            ret++;
//            i++;
//            j--;
//        }
//    }
//
//    cout << ret << endl;
//
//    delete[] a;
//    delete[] b;
//    return 0;
//}

//#include<iostream>
//#include<cmath>
//#include<cstdlib>
//using namespace std;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		double k, m;
//		double x = 1;
//		cin >> k >> m;
//		double cur = 0;
//		while (1)
//		{
//			if (sqrt(x) + floor(log(x) / log(k) )> m)
//			{
//				cout << x << endl;
//				break;
//			}
//			else
//			{
//				x += 1.0;
//			}
//		}
//	}
//	return 0;
//}

int main()
{
	MyVector::test_vector04();
	return 0;
}

