#include "Method.h"

extern const MyNum ZERO;
extern const MyNum ERROR;
extern const MyNum ONE;

//操作函数
void Method::input(std::string str) {		//输入 将字符串中计算部分提取出来
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ')
			calstr.push_back(str[i]);
	}
}

void Method::opstackpushback(std::deque<MyNum>& opstack, MyNum op) {
	while (!opstack.empty() && opstack.back().power >= op.power) {
		rpn.push_back(opstack.back());
		opstack.pop_back();
	}
	opstack.push_back(op);
}

bool judgeop(char c) {		//判断是否为函数型op
	if ((c < 'a' || c>'z') && (c < 'A' || c>'Z')) return false;
	else return true;
	return false;
}

void Method::changetorpn() {
	this->rpn.clear();
	std::deque<MyNum>& retrpn = this->rpn;
	std::deque<MyNum> opstack;	//符号栈(用deque模拟栈)

	string nowdigits;
	string op;
	for (int i = 0; i < calstr.size(); i++) {
		if (calstr[i] == ' ') continue;
		if (calstr[i] == ',') {
			if (!nowdigits.empty()) {
				retrpn.push_back(MyNum(nowdigits));
				nowdigits.clear();
			}
			while (!opstack.empty() && opstack.back() != MyNum("(")) {
				retrpn.push_back(opstack.back());
				opstack.pop_back();
			}
			//opstack.pop_back();
			continue;
		}
		if (calstr[i] == '-') {
			if (!(!nowdigits.empty() || i > 0 && calstr[i - 1] == ')')) {	//'-'是负号不是减号
				if (!op.empty()) {
					opstackpushback(opstack, MyNum(op));
					op.clear();
				}
				opstackpushback(opstack, MyNum("neg"));
				continue;
			}
		}
		if (calstr[i] >= '0' && calstr[i] <= '9' || calstr[i] == '.') {
			nowdigits.push_back(calstr[i]);
			if (!op.empty()) {
				opstackpushback(opstack, MyNum(op));
				op.clear();
			}
			continue;
		}
		if (!nowdigits.empty()) {
			retrpn.push_back(MyNum(nowdigits));
			nowdigits.clear();
		}
		if (calstr[i] == '(') {
			if (!op.empty()) {
				opstackpushback(opstack, MyNum(op));
				op.clear();
			}
			opstack.push_back(MyNum("("));
			continue;
		}
		if (calstr[i] == ')') {
			if (!nowdigits.empty()) {
				retrpn.push_back(MyNum(nowdigits));
				nowdigits.clear();
			}
			while (!opstack.empty() && opstack.back() != MyNum("(")) {
				retrpn.push_back(opstack.back());
				opstack.pop_back();
			}
			if (opstack.empty()) {	//多出来个右括号
				ans = ERROR.addError(3);
				return;
			}
			opstack.pop_back();
			if (!opstack.empty() && opstack.back().power == 4) {		//函数类计算后面是紧紧跟随括号的 所以括号被弹出后 函数也必须紧跟着弹出
				retrpn.push_back(opstack.back());
				opstack.pop_back();
			}
			continue;
		}
		//以下情况皆为calstr[i]为计算符号
		if (i < calstr.size() && !judgeop(calstr[i])) {		//符号型计算
			if (!op.empty() && judgeop(op[0])) {	//op中装着函数型计算
				opstackpushback(opstack, MyNum(op));
				op.clear();
			}
			else if (!op.empty()) {		//原先有符号 但是无法凑在一起
				string tempop(op); tempop.push_back(calstr[i]);
				if (tempop != "<=" && tempop != ">=" && tempop != "==" && tempop != "!=") {
					opstackpushback(opstack, MyNum(op));
					op.clear();
				}
			}
			op.push_back(calstr[i]);
			continue;
		}
		if (i < calstr.size() && judgeop(calstr[i])) {		//函数型计算
			if (!op.empty() && !judgeop(op[0])) {	//op中装着符号型计算
				opstackpushback(opstack, MyNum(op));
				op.clear();
			}
			op.push_back(calstr[i]);
			continue;
		}
	}

	if (!op.empty()) {
		opstackpushback(opstack, MyNum(op));
		op.clear();
	}
	if (!nowdigits.empty()) {
		retrpn.push_back(MyNum(nowdigits));
		nowdigits.clear();
	}
	while (!opstack.empty()) {
		if (opstack.back() == MyNum("(")) {
			ans = ERROR.addError(3);
			return;
		}
		retrpn.push_back(opstack.back());
		opstack.pop_back();
	}
}


MyNum Method::calculate() {		//计算
	if (ans.sign == -2)
		return ans;
	if (rpn.empty()) {
		ans = ZERO;
		return ZERO;
	}

	if (rpn.back().power == 0 && rpn.back().sign != 0) {	//逻辑判断式
		type = 1;
	}
	std::deque<MyNum> tempans;
	for (int i = 0; i < rpn.size(); i++) {
		if (rpn[i].sign != 2) {
			tempans.push_back(rpn[i]);
			continue;
		}
		//运算符
		if (rpn[i].power == 0) {
			MyNum b;
			if (tempans.empty()) {
				ans = ERROR.addError(3);
				return ans;
			}
			else {
				b = tempans.back(); tempans.pop_back();
			}
			MyNum a;
			if (tempans.empty()) {
				ans = ERROR.addError(3);
				return ans;
			}
			else {
				a = tempans.back(); tempans.pop_back();
			}
			if (rpn[i] == MyNum(">")) {
				tempans.push_back(MyNum(a > b));
			}
			if (rpn[i] == MyNum(">=")) {
				tempans.push_back(MyNum(a >= b));
			}
			if (rpn[i] == MyNum("<")) {
				tempans.push_back(MyNum(a < b));
			}
			if (rpn[i] == MyNum("<=")) {
				tempans.push_back(MyNum(a <= b));
			}
			if (rpn[i] == MyNum("==")) {
				tempans.push_back(MyNum(a == b));
			}
			if (rpn[i] == MyNum("!=")) {
				tempans.push_back(MyNum(a != b));
			}
		}
		if (rpn[i].power == 1) {
			if (rpn[i].digits[0] == '+') {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a + b);
			}
			if (rpn[i].digits[0] == '-') {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a - b);
			}
		}
		if (rpn[i].power == 2) {
			if (rpn[i].digits[0] == '*') {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a * b);
			}
			if (rpn[i].digits[0] == '/') {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a / b);
			}
		}
		if (rpn[i].power == 3) {
			if (rpn[i].digits[0] == '^') {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a ^ b);
			}
		}
		if (rpn[i].power == 4) {
			if (rpn[i] == MyNum("sqrt")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_sqrt());
			}
			if (rpn[i] == MyNum("log")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_log());
			}
			if (rpn[i] == MyNum("sin")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_sin());
			}
			if (rpn[i] == MyNum("cos")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_cos());
			}
			if (rpn[i] == MyNum("tan")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_tan());
			}
			if (rpn[i] == MyNum("exp")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_exp());
			}
			if (rpn[i] == MyNum("fabs")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_fabs());
			}
			if (rpn[i] == MyNum("gcd")) {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(My_gcd(a, b));
			}
			if (rpn[i] == MyNum("lcm")) {
				MyNum b;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					b = tempans.back(); tempans.pop_back();
				}
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(My_lcm(a, b));
			}
			if (rpn[i] == MyNum("neg")) {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a.My_neg());
			}
		}
		if (rpn[i].power == 5) {
			if (rpn[i].digits[0] == '%') {
				MyNum a;
				if (tempans.empty()) {
					ans = ERROR.addError(3);
					return ans;
				}
				else {
					a = tempans.back(); tempans.pop_back();
				}
				tempans.push_back(a / MyNum(100));
			}
		}
	}

	if (tempans.size() != 1)
		ans = ERROR;
	else ans = tempans[0];
	return ans;
}

//显示
void Method::showCalstr() {
	if (ans.sign == -2) {
		ERROR.show(); return;
	}
	std::cout << calstr;
}
void Method::showRPN() {
	if (ans.sign == -2) {
		ans.show(); return;
	}
	for (int i = 0; i < rpn.size(); i++) {
		if (rpn[i].digits[0] == ',') continue;
		rpn[i].show(); printf(" ");
	}
}

int getmin(int a, int b);
int getmax(int a, int b);

void Method::showAns(int showprecision) {
	if (ans.sign < -1 || ans.sign > 1) {		//非数字 直接show
		ans.show();
		return;
	}
	string tempans;
	if (ans.power < -showprecision) {		//过于小的小数 直接0
		ZERO.show();
		return;
	}
	if (ans.sign == -1)
		tempans.push_back('-');
	if (type == 0) {
		int decimalsize = ans.digits.size() - ans.power;
		if (decimalsize <= showprecision) {
			ans.show();
			return;
		}
		string bias("0.");
		for (int i = 0; i < showprecision - 1; i++) {
			bias.push_back('0');
		}
		bias.push_back('1');
		std::deque<int> newdigits;
		for (int i = 0; i < showprecision + ans.power; i++) {
			newdigits.push_back(ans.digits[i]);
		}
		MyNum newans(newdigits, ans.power, ans.sign);
		if (ans.digits[showprecision + ans.power] >= 5)
			newans += bias;
		newans.show();
		return;
	}
	else {
		if (ans == ZERO) printf("FALSE");
		else printf("TRUE");
	}
}

void Method::show(int showtype) {
	if (showtype == 0) {
		showAns();
		return;
	}
	printf("原式: "); showCalstr(); printf("\n");
	printf("后缀表达式: "); showRPN(); printf("\n");
	printf("ans= "); showAns(); printf("\n");
}
