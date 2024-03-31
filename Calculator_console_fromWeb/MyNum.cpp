#define _CRT_SECURE_NO_WARNINGS
#include "MyNum.h"
#include <iostream>
#include <cstdio>

#define ZERO_LIMIT 1e-6		//小于这个数字的浮点数 就判定为0
#define TAYLOR_LIMIT 50		//数学函数里面使用泰勒展开的数据最大值 因为数据过大泰勒展开将会耗时过久


extern const MyNum ZERO({ 0 }, 0, 0);
extern const MyNum ERROR({}, 0, -2);
extern const MyNum ONE(1);
//const MyNum PI(MyNum::getPI());
extern MyNum PI("3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446");
//运用getPI函数将会超时... 因此直接读入pi会更好
extern MyNum PIDOUBLE("6.2831853071795864769252867665590057683943387987502116419498891846156328125724179972560696506842341359642961730265646132941876892");


//工具函数

int getmin(int a, int b) { return a < b ? a : b; }
int getmax(int a, int b) { return a > b ? a : b; }
int inttodeque(std::deque<int>& digits, int i) {
	if (i == 0) {
		digits.push_back(0);
		return 0;
	}
	int retpower = 0;
	i = i > 0 ? i : -i;
	while (i) {
		digits.push_front(i % 10);
		i /= 10;
		retpower++;
	}
	return retpower;
}
int cmp_digits(std::deque<int>& a, std::deque<int>& b) {
	for (int i = 0; i < getmin(a.size(), b.size()); i++) {
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}
	if (a.size() > b.size()) return 1;
	if (a.size() < b.size()) return -1;
	return 0;
}
int minus_digits(std::deque<int>& a, std::deque<int>& b) {
	//前提确保了a>b
	for (int i = 0; i < b.size(); i++) {
		if (i == a.size())
			a.push_back(0);
		a[i] -= b[i];
	}
	for (int i = a.size() - 1; i >= 1; i--) {
		while (a[i] < 0) {
			a[i - 1]--;
			a[i] += 10;
		}
	}
	int ret = 0;	//返回借位
	while (a[0] < 0) {
		ret++;
		a[0] += 10;
	}
	return ret;
}
string digittostring(std::deque<int>& digits) {
	string ans;
	for (int i = 0; i < digits.size(); i++) {
		ans.push_back(char(digits[i]));
	}
	return ans;
}

//构造函数
MyNum::MyNum(int i) {
	*this = MyNum((long long)i);
}
MyNum::MyNum(long long i) {
	if (i == 0ll) {
		*this = ZERO;
		return;
	}
	int power = 0;
	std::deque<int> digits;
	int sign = 1;
	if (i < 0) sign = -1;
	i *= sign;
	while (i) {
		digits.push_front(i % 10);
		i /= 10;
		power++;
	}
	while (digits.back() == 0)
		digits.pop_back();
	this->digits = digits;
	this->power = power;
	this->sign = sign;
}
MyNum::MyNum(double d) {
	if (d < ZERO_LIMIT && d>-ZERO_LIMIT) {
		*this = ZERO;
		return;
	}
	this->sign = (d > 0) ? 1 : -1;
	d *= sign;
	int retpower = 0;
	if (int(d) != 0)
		retpower = inttodeque(this->digits, int(d));
	bool ifFindDemicalPoint = retpower >= 0;	//是否找到小数点
	d -= int(d);	//只保留小数部分
	while (d > ZERO_LIMIT || d < -ZERO_LIMIT) {
		d *= 10;
		int integer = int(d);
		d -= integer;
		if (ifFindDemicalPoint)
			this->digits.push_back(integer);
		else {
			if (integer == 0)
				retpower--;
			else
				ifFindDemicalPoint = true;
		}
	}
	this->power = retpower;
	while (this->digits.back() == 0)
		this->digits.pop_back();
	this->setPrecision();
	/*char str[1000];
	sprintf(str, "%lf", d);
	*this = MyNum(std::string(str));*/		//sprintf转换成字符串只有6位小数的精度
}
MyNum::MyNum(std::string str) {
	if (str.size() && (str[0] < '0' || str[0]>'9')) {
		if (!((str[0] == '-' || str[0] == '+') && str.size() > 1 && str[1] >= '0' && str[1] <= '9')) {
			this->sign = 2;
			if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'A' && str[0] <= 'Z')
				power = 4;
			else {
				if (str[0] == '(') power = -2;
				if (str[0] == '=' || str[0] == '<' || str[0] == '>') power = 0;
				if (str[0] == '+' || str[0] == '-') power = 1;
				if (str[0] == '*' || str[0] == '/') power = 2;
				if (str[0] == '^') power = 3;
				if (str[0] == '%') power = 5;
				if (str[0] == ',')	power = -1;
			}
			for (int i = 0; i < str.size(); i++) {
				this->digits.push_back(int(str[i]));
			}
			return;
		}
	}
	this->sign = 1;
	int i = 0;
	while (str[i] == ' ') i++;
	if (str[i] == '-') {
		this->sign = -1; i++;
	}
	if (str[i] == '+') i++;

	int retpower = 0;
	bool startdigits = false;	//开始有效数字
	int powerchange = 1;		//1表示每往后一格power++  -1就是小数情况
	int ifdecimal = false;
	bool ifmeetpoint = false;	//有无遇见小数点
	while (i < str.size()) {
		if (startdigits && str[i] >= '0' && str[i] <= '9') {
			this->digits.push_back(str[i] - '0');
			if (!ifmeetpoint)
				retpower++;
		}
		else {
			if (str[i] >= '1' && str[i] <= '9') {
				startdigits = true;
				this->digits.push_back(str[i] - '0');
				if (!ifmeetpoint)
					retpower++;
				if (ifdecimal) {
					this->power = retpower;
				}
			}
			if (str[i] == '0' && ifdecimal) {
				retpower--;
			}
			if (str[i] == '.') {
				ifmeetpoint = true;
				if (!startdigits) {	//小数
					ifdecimal = true;
				}
				else {
					this->power = retpower;
				}
			}
		}
		i++;
	}
	while (!this->digits.empty() && this->digits.back() == 0)
		this->digits.pop_back();
	if (digits.empty()) {
		*this = ZERO;
	}
	this->power = retpower;
	this->setPrecision();
}


//数学函数
MyNum MyNum::getPI() {
	MyNum ret;
	MyNum add(1);
	for (int i = 1; add.sign != 0; i += 2) {
		add = ONE / MyNum(i);
		if ((i / 2) % 2)
			ret -= add;
		else
			ret += add;
	}
	return ret * MyNum(4);
}
//单目数学函数
MyNum MyNum::My_sqrt() const {
	//return *this^MyNum(0.5);
	return MyNum(sqrt(this->to_double()));
}
MyNum MyNum::My_sin() const {
	if (this->sign == 0) return ZERO;

	MyNum cal(*this);
	while (cal < -PIDOUBLE)
		cal += PIDOUBLE;
	while (cal > PIDOUBLE)
		cal -= PIDOUBLE;	//PI优化
	MyNum ret;
	MyNum add(-1);
	for (int i = 1; add.sign != 0; i++) {
		add = add * cal / MyNum(i);
		if (i % 2) {
			add.sign *= -1;
			ret += add;
		}
	}
	return ret;
}
MyNum MyNum::My_cos() const {
	if (this->sign == 0) return MyNum(1);

	MyNum cal(*this);
	while (cal < -PIDOUBLE)
		cal += PIDOUBLE;
	while (cal > PIDOUBLE)
		cal -= PIDOUBLE;	//PI优化
	MyNum ret(1);
	MyNum add(1);
	for (int i = 1; add.sign != 0; i++) {
		add = add * cal / MyNum(i);
		if (i % 2 == 0) {
			add.sign *= -1;
			ret += add;
		}
	}
	return ret;
}
MyNum MyNum::My_tan() const {
	return this->My_sin() / this->My_cos();
}
MyNum MyNum::My_exp() const {
	if (this->sign == 0) return ONE;
	if (*this > MyNum(TAYLOR_LIMIT))
		return MyNum(exp(this->to_double()));
	MyNum ret;
	MyNum add(1);
	for (int i = 1; add.sign != 0; i++) {
		ret += add;
		add *= (*this) / MyNum(i);
	}
	return ret;
}
MyNum MyNum::My_fabs() const {
	return MyNum(this->digits, this->power, (this->sign < 0) ? -sign : sign);		//不能直接是1  考虑到0
}
MyNum MyNum::My_neg() const {
	return -(*this);
}
MyNum MyNum::My_log() const {
	if (this->sign <= 0) {
		return this->addError(4);
	}
	return MyNum(log(this->to_double()));
}
//多目数学函数
MyNum My_gcd_recursion(MyNum& a, MyNum& b) {	//递归辗转相除
	while (a > b) {
		a -= b;
	}
	if (a == b)
		return a;
	else
		return My_gcd_recursion(b, a);
}
MyNum My_gcd(const MyNum& a, const MyNum& b) {
	if (a.sign != b.sign) return ERROR;
	MyNum aa(a.digits, a.power, 1), bb(b.digits, b.power, 1);
	MyNum ret(My_gcd_recursion(aa, bb));
	ret.sign = a.sign;
	return ret;
}
MyNum My_lcm(const MyNum& a, const MyNum& b) {
	return a * b / My_gcd(a, b);
}

//转换函数
double MyNum::to_double() const {
	double ret = 0;
	const std::deque<int>& digits = this->digits;
	for (int i = digits.size() - 1; i >= 0; i--) {	//化为类科学计数法 0.xxx
		ret += digits[i];
		ret /= 10;
	}
	if (this->power > 0)
		for (int i = 0; i < this->power; i++)
			ret *= 10;
	else {
		for (int i = 0; i < -this->power; i++) {
			ret /= 10;
		}
	}
	return ret;
}
int MyNum::to_int() const {
	if (power <= 0) return 0;
	int ret = 0;
	for (int i = 0; i < power; i++) {
		ret *= 10;
		if (i < this->digits.size())
			ret += this->digits[i];
	}
	return ret * this->sign;
}
long long MyNum::to_longlong() const {
	if (power <= 0) return 0ll;
	long long ret = 0;
	for (int i = 0; i < power; i++) {
		ret *= 10;
		ret += long long(this->digits[i]);
	}
	return ret * this->sign;
}
std::string MyNum::to_string() const {
	if (sign == -2) return "ERROR";
	if (sign == 0) return "0";

	string ans;
	if (sign == -1) ans.push_back('-');
	int power = this->power;
	const std::deque<int>& digits = this->digits;
	if (power <= 0) {
		ans += "0.";
		while (power < 0) {
			ans.push_back('0');
		}
		for (int i = 0; i < digits.size(); i++) {
			ans.push_back('0' + digits[i]);
		}
	}
	else {
		int i;
		for (i = 0; i < power; i++) {
			if (i >= digits.size())
				ans.push_back('0');
			else
				ans.push_back('0' + digits[i]);
		}
		if (i < digits.size()) {
			ans.push_back('.');
			for (; i < digits.size(); i++) {
				ans.push_back(digits[i]);
			}
		}
	}
	return ans;
}
MyNum MyNum::decimalpart() const {
	if (this->power <= 0) return *this;
	MyNum ret(*this);
	while (ret.power) {
		ret.power--;
		if (!ret.digits.empty())
			ret.digits.pop_front();
	}
	if (ret.digits.empty())
		return ZERO;
	return ret;
}

MyNum MyNum::addError(int i)const {
	MyNum ret(ERROR);
	ret.digits.clear();
	if (this->sign == -2)
		ret = *this;
	for (int temp = ret.digits.size(); temp <= i; temp++) {
		ret.digits.push_back(0);
	}
	ret.digits[i] = 1;
	return ret;
}

//运算符重载
bool MyNum::operator<(const MyNum& other)const {
	if (this->sign < other.sign) return true;
	if (this->sign > other.sign) return false;
	//下面同号情况
	if (this->power < other.power) return sign == 1;	//绝对值小 判断是否正数
	if (this->power > other.power) return sign == -1;	//绝对值小 判断是否正数
	//同号 指数相同 比较有效数字
	int i;
	for (i = 0; i < getmin(this->digits.size(), other.digits.size()); i++) {
		if (this->digits[i] < other.digits[i]) return sign == 1;
		if (this->digits[i] > other.digits[i]) return sign == -1;
	}
	//有效数字重叠  判断哪个短
	if (this->digits.size() < other.digits.size()) return sign == 1;
	if (this->digits.size() > other.digits.size()) return sign == -1;
	return false;
}
bool MyNum::operator>(const MyNum& other)const {
	if (this->sign > other.sign) return true;
	if (this->sign < other.sign) return false;
	//下面同号情况
	if (this->power > other.power) return sign == 1;	//绝对值大 判断是否正数
	if (this->power < other.power) return sign == -1;
	//同号 指数相同 比较有效数字
	int i;
	for (i = 0; i < getmin(this->digits.size(), other.digits.size()); i++) {
		if (this->digits[i] > other.digits[i]) return sign == 1;
		if (this->digits[i] < other.digits[i]) return sign == -1;
	}
	//有效数字重叠  判断哪个长
	if (this->digits.size() > other.digits.size()) return sign == 1;
	if (this->digits.size() < other.digits.size()) return sign == -1;
	return false;
}
bool MyNum::operator==(const MyNum& other)const {
	return (this->digits == other.digits && this->sign == other.sign && this->power == other.power);
}
bool MyNum::operator!=(const MyNum& other)const {
	return !(this->operator==(other));
}
bool MyNum::operator<=(const MyNum& other)const {
	return (*this) < other || (*this) == other;
}
bool MyNum::operator>=(const MyNum& other)const {
	return (*this) > other || (*this) == other;
}
MyNum MyNum::operator+(const MyNum& other)const {
	//ERROR
	if ((*this).sign == -2 || other.sign == -2) {
		if ((*this).sign == -2 && other.sign == -2) {
			MyNum reterror(ERROR);
			for (int i = 0; i < this->digits.size(); i++) {
				if (this->digits[i]) {
					reterror = reterror.addError(i);
				}
			}
			for (int i = 0; i < other.digits.size(); i++) {
				if (other.digits[i]) {
					reterror = reterror.addError(i);
				}
			}
			return reterror;
		}
		if ((*this).sign == -2) return *this;
		if (other.sign == -2) return other;
	}
	//异号
	if (this->sign * other.sign == -1) {
		if (this->sign < 0) return other - (-(*this));
		else return (*this) - (-other);
	}

	//0
	if (this->sign == 0) return other;
	if (other.sign == 0) return *this;

	//同号
	//找到较大的那个数 用它加上较小的数 比较省事
	MyNum const* bigger, * smaller;
	if (this->My_fabs() >= other.My_fabs())
	{
		bigger = this; smaller = &other;
	}
	else
	{
		bigger = &other; smaller = this;
	}
	int retpower = bigger->power;
	int retsign = bigger->sign;
	//对齐小数点后逐位相加
	int diff = bigger->power - smaller->power;		//小数点偏差
	std::deque<int> retdigits = bigger->digits;
	int length = 0;
	while (length < diff) {
		while (length >= retdigits.size())
			retdigits.push_back(0);
		length++;
	}
	for (int temp = 0; temp < smaller->digits.size(); temp++) {
		while (length >= retdigits.size())
			retdigits.push_back(0);
		retdigits[length++] += smaller->digits[temp];
	}
	//从后往前逐位校准
	for (int temp = length - 1; temp >= 1; temp--) {
		retdigits[temp - 1] += retdigits[temp] / 10;
		retdigits[temp] %= 10;
	}
	if (retdigits[0] >= 10) {
		retdigits.push_front(retdigits[0] / 10);
		retdigits[1] %= 10;
		retpower++;
	}
	//末尾去0
	while (!retdigits.empty() && retdigits.back() == 0)
		retdigits.pop_back();
	if (retdigits.empty()) return ZERO;

	MyNum ans(retdigits, retpower, retsign);
	ans.setPrecision();
	return ans;
}
MyNum MyNum::operator-()const {
	return MyNum(this->digits, this->power, -(this->sign));
}
MyNum MyNum::operator-(const MyNum& other)const {
	//ERROR
	if ((*this).sign == -2 || other.sign == -2) return *this + other;

	//异号
	if (this->sign * other.sign == -1) {
		if (this->sign < 0) return -(other + (-(*this)));
		else return (*this) + (-other);
	}

	//0
	if (this->sign == 0) return -other;
	if (other.sign == 0) return -(*this);

	//同号
	if ((*this) == other) return ZERO;
	int retsign;
	//找到绝对值较大的那个数 用它减去较小的数 比较省事
	MyNum const* bigger, * smaller;
	if (this->My_fabs() > other.My_fabs())
	{
		bigger = this; smaller = &other; retsign = bigger->sign;
	}
	else
	{
		bigger = &other; smaller = this; retsign = -bigger->sign;
	}
	int retpower = bigger->power;
	//对齐小数点逐位相减
	int diff = bigger->power - smaller->power;		//小数点偏差
	std::deque<int> retdigits = bigger->digits;
	int length = 0;
	while (length < diff) {
		while (length >= retdigits.size())
			retdigits.push_back(0);
		length++;
	}
	for (int temp = 0; temp < smaller->digits.size(); temp++) {
		while (length >= retdigits.size())
			retdigits.push_back(0);
		retdigits[length++] -= smaller->digits[temp];
	}

	//从后往前逐位校准
	for (int temp = length - 1; temp >= 1; temp--) {
		while (retdigits[temp] < 0) {
			retdigits[temp - 1]--;
			retdigits[temp] += 10;
		}
	}
	//去头0 去尾0
	while (!retdigits.empty() && retdigits.front() == 0) {
		retdigits.pop_front();
		retpower--;
	}
	while (!retdigits.empty() && retdigits.back() == 0)
		retdigits.pop_back();
	if (retdigits.empty()) return ZERO;

	MyNum ans(retdigits, retpower, retsign);
	ans.setPrecision();
	return ans;
}
MyNum MyNum::operator*(const MyNum& other)const {
	//ERROR
	if ((*this).sign == -2 || other.sign == -2) return *this + other;

	//0
	if (this->sign == 0) return ZERO;
	if (other.sign == 0) return ZERO;

	int retsign = this->sign * other.sign;
	int retpower = this->power + other.power;
	std::deque<int> retdigits;
	for (int i = 0; i < this->digits.size(); i++) {
		if (this->digits[i] == 0) continue;
		int temp = i;
		for (int j = 0; j < other.digits.size(); j++) {
			while (temp >= retdigits.size())
				retdigits.push_back(0);
			retdigits[temp++] += this->digits[i] * other.digits[j];
		}
	}
	for (int temp = retdigits.size() - 1; temp >= 1; temp--) {
		retdigits[temp - 1] += retdigits[temp] / 10;
		retdigits[temp] %= 10;
	}
	retpower--;
	while (retdigits.front() >= 10) {
		retdigits.push_front(retdigits[0] / 10);
		retdigits[1] %= 10;
		retpower++;
	}
	MyNum ans(retdigits, retpower, retsign);
	ans.setPrecision();
	return ans;
}
MyNum MyNum::operator/(const MyNum& other)const {
	//ERROR
	if ((*this).sign == -2 || other.sign == -2) return *this + other;

	//除0
	if (other.sign == 0) {
		return ERROR.addError(0);
	}
	if (this->sign == 0) {
		return ZERO;
	}

	if (other == MyNum(1)) return *this;
	if (other == MyNum(-1)) return -*this;
	int retsign = this->sign * other.sign;
	int retpower = this->power - other.power;
	std::deque<int> a = this->digits;
	std::deque<int> b = other.digits;

	std::deque<int> ans;
	for (int temp = 0; temp <= PRECISION + retsign; temp++) {
		int next = 0;
		while (cmp_digits(a, b) > 0) {
			minus_digits(a, b);
			next++;
		}
		if (cmp_digits(a, b) == 0) {
			next++;
			ans.push_back(next);
			break;
		}
		ans.push_back(next);
		b.push_front(0);
	}

	while (!ans.empty() && ans.front() == 0) {
		ans.pop_front();
		retpower--;
	}
	while (!ans.empty() && ans.back() == 0) {
		ans.pop_back();
	}
	retpower++;
	MyNum ret(ans, retpower, retsign);
	ret.setPrecision();
	return ret;
}
MyNum MyNum::operator^(const MyNum& other) const {
	//ERROR
	if ((*this).sign == -2 || other.sign == -2) return *this + other;

	MyNum b(other);
	if (b.sign == 0) return (this->sign == 0) ? ERROR.addError(1) : ZERO;
	if (this->sign == 0) return (b.sign > 0) ? ZERO : ERROR.addError(0);
	//仅排除了底数为零的情况 不保证幂指数的整数部分和小数部分不为0
	if (b.sign > 0)
		return power_int(other.to_int()) * (power_decimal(other.decimalpart()));	//整数部分快速幂 小数部分泰勒展开
	else
		return MyNum(1) / (power_int(-other.to_int()) * (power_decimal(-other.decimalpart())));
}
MyNum MyNum::power_int(int k)const {
	if (k == 0) return MyNum(1);
	if (k < 0) return MyNum(1) / ((*this) ^ (-k));
	if (*this == MyNum(1)) return MyNum(1);

	//快速幂部分
	MyNum ans(1);
	MyNum bottom(*this);
	while (k) {
		if (k & 1) {
			ans *= bottom;
		}
		bottom *= bottom;
		k >>= 1;
	}
	ans.setPrecision();
	return ans;
}
MyNum MyNum::power_decimal(const MyNum& decimal) const {
	//ERROR
	if ((*this).sign == -2) return *this;

	if (decimal.sign == 0) return MyNum(1);
	if (this->sign < 0)	//底数负数 不可进行小数幂
		return ERROR.addError(2);

	MyNum mult = this->My_log() * decimal;	//泰勒展开每一项要乘的东西
	MyNum add(1);
	MyNum ret;
	for (int i = 1; add.sign != 0; i++) {
		ret += add;
		add = add * mult / MyNum(i);
	}
	return ret;
}
MyNum& MyNum::operator+=(const MyNum& other) {
	*this = *this + other;
	return *this;
}
MyNum& MyNum::operator-=(const MyNum& other) {
	*this = *this - other;
	return *this;
}
MyNum& MyNum::operator*=(const MyNum& other) {
	*this = *this * other;
	return *this;
}
MyNum& MyNum::operator/=(const MyNum& other) {
	*this = *this / other;
	return *this;
}



//显示
void MyNum::show() const {
	if (this->sign == -2) {
		printf("ERROR\n");
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i])
				std::cout << errorreason[i] << std::endl;
		}
		return;
	}
	if (sign == 2) {
		if (digits[0] == ',') return;
		for (int i = 0; i < digits.size(); i++)
			printf("%c", char(digits[i]));
		return;
	}
	int power = this->power;
	int sign = this->sign;
	std::deque<int> digits = this->digits;
	if (sign == -1) printf("-");
	if (sign == 0) { printf("0"); return; }

	if (power <= 0) {
		printf("0.");
		while (power < 0) {
			printf("0"); power++;
		}
		power--;
	}
	for (int i = 0; i < digits.size(); i++) {
		if (power-- == 0) {
			printf(".");
		}
		printf("%d", digits[i]);
	}
	while (power > 0) {
		printf("0");
		power--;
	}
}
void MyNum::setPrecision(int prec) {
	int decimalpart = this->digits.size() - this->power;	//小数部分长度
	if (decimalpart <= PRECISION)
		return;
	for (int i = 0; i < decimalpart - prec - 1; i++)
		if (!this->digits.empty())
			this->digits.pop_back();
	int diff = 0;	//四舍五入的偏差值
	if (!this->digits.empty()) {
		if (this->digits.back() >= 5) {
			diff = 1;	//进1
		}
		this->digits.pop_back();
	}
	if (this->digits.empty()) {
		*this = ZERO;
	}
	else {
		int i = this->digits.size() - 1;
		while (diff) {
			if (i == -1) break;
			this->digits[i] += diff;
			diff = this->digits[i] / 10;
			this->digits[i] %= 10;
			i--;
		}
		if (i == -1 && diff) {
			this->power++;
			this->digits.front() %= 10;
			this->digits.push_front(1);
		}
	}
}
