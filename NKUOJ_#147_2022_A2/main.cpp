/*
试题2（A卷）
题目描述：

请定义一个抽象基类File类，并派生出ChangeEncode_name类（更改文件编码和文件名）和ChangeEncode_size类（更改文件编码和文件大小），要求如下。

抽象基类File类：

有保护成员变量filename（字符串类型）和filesize（整数类型）。
纯虚函数UpdateFile()和纯虚函数show()，参数和返回类型根据要求定义。
派生类ChangeEncode_name类和ChangeEncode_size类：

新增成员变量fileEncoder（文件编码方式），常见的编码方式有四种（"ASCII"，"UNICODE"，"UTF8"和"ANSI"）。用0，1，2，3分别表示"ASCII"、"UNICODE"、"UTF8"和"ANSI"的标记，均为大写字母。
自行添加构造函数。
ChangeEncode_name类的UpdateFile()函数用来更改文件编码和文件名。ChangeEncode_size类的UpdateFile()函数用来更改文件编码和文件大小。
Show()来展示文件信息。ChangeEncode_name类展示的文件信息格式为：change_encodeAndname: 文件名 文件大小 文件编码方式，用空格隔开，冒号前后无空格，如：change_encodeAndname: Main.cpp 32 ASCII。ChangeEncode_size类展示的文件信息格式为：change_encodeAndsize: 文件名 文件大小 文件编码方式，用空格隔开，冒号前后无空格，如：change_encodeAndsize: Main.cpp 32 ASCII。
输入：

第一行为三个初始字段，文件名，文件大小，文件编码方式。 其中文件名为字符串（长度不超过256），文件大小为整数，文件编码方式为数字0（表示ASCII编码），1（表示UNICODE编码），2（表示UTF8编码）或3（表示ANSI编码）。
第二行首先输入一个字符，代表要进行的操作：
如果输入字符是N，代表要对文件进行编码转换和重名操作。接下来一行是更改后的文件名和编码；
如果输入字符为S（大写）代表要对文件进行编码转换和大小操作。接下来一行是更改后的大小和编码。
输出：

采用动态联编的方式，输出文件更新后的信息，如果输入的操作字符非N和S，则输出“No such operation！”
注意：

必须采用抽象基类，必须完成规定的要求，否则扣0分。
样例输入：
NKU_nice_every_day.txt 4321 0
N
Good_luck.txt 1
样例输出：
change_encodeAndname: Good_luck.txt 4321 UNICODE
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v = { "ASCII", "UNICODE", "UTF8", "ANSI" };

class File
{
protected:
	string filename;
	int filesize;
public:
	File(string name = string(), int size = 0) : filename(name), filesize(size) {}
	File(const File& f) {
		filename = f.filename;
		filesize = f.filesize;
	}
	virtual void UpdateFile(string newname, int newcode) = 0;
	virtual void UpdateFile(int newsize, int newcode) = 0;
	virtual void show() const = 0;
	virtual ~File() {}
};

class ChangeEncode_name : public File
{
protected:
	int fileEncoder;
public:
	ChangeEncode_name(string name = string(), int size = 0, int Encoder = 0) : File(name, size), fileEncoder(Encoder) {}
	ChangeEncode_name(const ChangeEncode_name& c) : File(c.filename, c.filesize), fileEncoder(c.fileEncoder) {}
	void UpdateFile(string newname, int newcode) override {
		filename = newname;
		fileEncoder = newcode;
	}
	void UpdateFile(int newsize, int newcode) override {
		// This function should not be used in ChangeEncode_name
	}
	void show() const override {
		cout << "change_encodeAndname: " << filename << " " << filesize << " " << v[fileEncoder] << endl;
	}
};

class ChangeEncode_size : public File
{
protected:
	int fileEncoder;
public:
	ChangeEncode_size(string name = string(), int size = 0, int Encoder = 0) : File(name, size), fileEncoder(Encoder) {}
	ChangeEncode_size(const ChangeEncode_size& c) : File(c.filename, c.filesize), fileEncoder(c.fileEncoder) {}
	void UpdateFile(int newsize, int newcode) override {
		filesize = newsize;
		fileEncoder = newcode;
	}
	void UpdateFile(string newname, int newcode) override {
		// This function should not be used in ChangeEncode_size
	}
	void show() const override {
		cout << "change_encodeAndsize: " << filename << " " << filesize << " " << v[fileEncoder] << endl;
	}
};

int main()
{
	string fn;
	cin >> fn;
	int fs;
	cin >> fs;
	int fe;
	cin >> fe;

	File* file = nullptr;
	char choice;
	cin >> choice;

	if (choice == 'N') {
		file = new ChangeEncode_name(fn, fs, fe);
		string nn;
		cin >> nn;
		int ne;
		cin >> ne;
		file->UpdateFile(nn, ne);
	}
	else if (choice == 'S') {
		file = new ChangeEncode_size(fn, fs, fe);
		int ns, ne;
		cin >> ns >> ne;
		file->UpdateFile(ns, ne);
	}
	else {
		cout << "No such operation!" << endl;
		return 0;
	}

	file->show();
	delete file;

	return 0;
}
