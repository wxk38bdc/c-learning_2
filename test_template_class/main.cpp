#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// ∂®“Â¿‡ƒ£∞Â
template<class T>
class SortArray
{
private:
    vector<T> arr;
public:
    SortArray(int n)
    {
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void sortArray()
    {
        sort(arr.begin(), arr.end());
    }
    void printArray()
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // ’˚–Õ≈≈–Ú
    int n1;
    cin >> n1;
    SortArray<int> intArray(n1);
    intArray.sortArray();
    intArray.printArray();

    // ◊÷∑˚≈≈–Ú
    int n2;
    cin >> n2;
    SortArray<char> charArray(n2);
    charArray.sortArray();
    charArray.printArray();

    // ◊÷∑˚¥Æ≈≈–Ú
    int n3;
    cin >> n3;
    SortArray<string> stringArray(n3);
    stringArray.sortArray();
    stringArray.printArray();

    return 0;
}
