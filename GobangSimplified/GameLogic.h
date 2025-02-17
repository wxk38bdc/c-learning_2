#pragma once
#include <iostream>
#include "Seat.h"
#include "Box.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
// 全局变量
box BOX[19][19];      // 棋盘
int win = -1;         // 谁赢了（0：白棋，1：黑棋，2：平局）
int whoplay = 0;      // 轮到谁下棋了
int playercolor = 0;  // 玩家颜色
int dx[4]{ 1,0,1,1 }; // - | \ / 四个方向
int dy[4]{ 0,1,1,-1 };
int Score[3][5] = //评分表
{
	{ 0, 80, 250, 500, 500 }, // 防守0子
	{ 0, 0,  80,  250, 500 }, // 防守1子
	{ 0, 0,  0,   80,  500 }  // 防守2子
};
int MAXxs[361];   //最优x坐标
int MAXys[361];   //最优y坐标
int mylength = 0; //最优解数
// 全局变量：游戏模式
int gameMode = 1; // 默认为人机对战模式


// 选择模式函数
void chooseMode() {


	char ch;
	while (true) {
		cleardevice(); // 清空图形窗口
		setbkcolor(RGB(230, 230, 250)); // 设置背景颜色为浅紫色
		setfillcolor(RGB(245, 245, 220)); // 设置填充颜色为米色
		solidrectangle(0, 0, 700, 700); // 绘制整个窗口背景

		// 添加顶部标题
		settextstyle(40, 0, _T("Consolas"));
		settextcolor(RGB(0, 100, 200)); // 蓝色字体
		outtextxy(200, 100, _T("欢迎来到五子棋游戏!"));

		// 绘制模式选择框
		setlinecolor(RGB(100, 149, 237)); // 设置边框颜色为天蓝色
		setlinestyle(PS_SOLID, 3); // 设置实线边框
		rectangle(150, 180, 550, 450); // 绘制选择框

		// 添加选择模式文字
		settextstyle(30, 0, _T("Consolas"));
		settextcolor(BLACK);
		outtextxy(200, 200, _T("请选择游戏模式:"));
		outtextxy(200, 250, _T("1. 玩家 vs AI"));
		outtextxy(200, 300, _T("2. 玩家 vs 玩家"));
		outtextxy(200, 350, _T("3. AI vs AI"));

		// 添加说明
		settextcolor(RGB(0, 128, 0)); // 设置绿色字体
		outtextxy(200, 400, _T("请输入模式编号 (1, 2, 3):"));

		std::cout << "Select Game Mode:\n";
		std::cout << "1. Player vs AI (Human vs Computer)\n";
		std::cout << "2. Player vs Player (Human vs Human)\n";
		std::cout << "3. AI vs AI (Computer vs Computer)\n";
		std::cout << "Enter 1, 2, or 3: ";
		std::cin >> ch; // 从命令行读取用户输入
		if (ch == '1') {
			gameMode = 1; // 人机对战
			outtextxy(200, 500, _T("已选择: 玩家 vs AI"));
			break;
		}
		else if (ch == '2') {
			gameMode = 2; // 双人对战
			outtextxy(200, 500, _T("已选择: 玩家 vs 玩家"));
			break;
		}
		else if (ch == '3') {
			gameMode = 3; // AI 对战
			outtextxy(200, 500, _T("已选择: AI vs AI"));
			break;
		}
		else {
			settextcolor(RGB(255, 0, 0)); // 设置红色字体
			outtextxy(200, 500, _T("无效输入，请重新输入 (1, 2, 3):"));
		}
	}

	// 添加图案作为装饰
	setfillcolor(RGB(255, 192, 203)); // 设置填充颜色为粉色
	fillcircle(350, 600, 30); // 绘制底部装饰圆

	Sleep(1500); // 等待 1.5 秒让用户看到选择结果
	cleardevice(); // 清空屏幕进入下一阶段
}
// 绘制棋盘
void draw()
{
	int number = 0; // 坐标输出的位置
	// 坐标（数值）
	TCHAR strnum[19][3] = { _T("1"),_T("2") ,_T("3") ,_T("4"),_T("5") ,_T("6") ,_T("7"),_T("8"),_T("9"),_T("10"), _T("11"),_T("12") ,_T("13") ,_T("14"),_T("15") ,_T("16") ,_T("17"),_T("18"),_T("19") };
	// 坐标（字母）
	TCHAR strabc[19][3] = { _T("a"),_T("b") ,_T("c") ,_T("d"),_T("e") ,_T("f") ,_T("g"),_T("h"),_T("i"),_T("j"), _T("k"),_T("l") ,_T("m") ,_T("n"),_T("o") ,_T("p") ,_T("q"),_T("r"),_T("s") };
	LOGFONT nowstyle;
	gettextstyle(&nowstyle);
	settextstyle(0, 0, NULL);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			BOX[i][j].draw(); // 绘制
			if (BOX[i][j].isnew == true)
			{
				BOX[i][j].isnew = false; // 把上一个下棋位置的黑框清除
			}
		}
	}
	// 画坐标
	for (int i = 0; i < 19; i++)
	{
		outtextxy(75 + number, 35, strnum[i]);
		outtextxy(53, 55 + number, strabc[i]);
		number += 30;
	}
	settextstyle(&nowstyle);
}

// 对局初始化
void init()
{
	win = -1;// 谁赢了
	for (int i = 0, k = 0; i < 570; i += 30)
	{
		for (int j = 0, g = 0; j < 570; j += 30)
		{
			int modle = 0;  // 棋盘样式
			BOX[k][g].value = -1;
			BOX[k][g].color = RGB(255, 205, 150);// 棋盘底色
			// x、y 坐标
			BOX[k][g].x = 65 + j;
			BOX[k][g].y = 50 + i;
			// 棋盘样式的判断
			if (k == 0 && g == 0)
			{
				modle = 8;
			}
			else if (k == 0 && g == 18)
			{
				modle = 7;
			}
			else if (k == 18 && g == 18)
			{
				modle = 6;
			}
			else if (k == 18 && g == 0)
			{
				modle = 5;
			}
			else if (k == 0)
			{
				modle = 3;
			}
			else if (k == 18)
			{
				modle = 4;
			}
			else if (g == 0)
			{
				modle = 1;
			}
			else if (g == 18)
			{
				modle = 2;
			}
			else  if ((k == 3 && g == 3) || (k == 3 && g == 15) || (k == 15 && g == 3) || (k == 15 && g == 15) || (k == 3 && g == 9) || (k == 9 && g == 3) || (k == 15 && g == 9) || (k == 9 && g == 15) || (k == 9 && g == 9))
			{
				modle = 9;
			}
			else
			{
				modle = 0;
			}
			BOX[k][g].modle = modle;
			g++;
		}
		k++;
	}
}

// 判断周围是否有棋子
bool hasAdjacent(int i, int j) {
	for (int k = 0; k < 4; k++) {
		for (int step = -1; step <= 1; step += 2) { // 向前向后检测
			int nowi = i + step * dx[k];
			int nowj = j + step * dy[k];
			if (nowi >= 0 && nowj >= 0 && nowi <= 18 && nowj <= 18 &&
				BOX[nowi][nowj].value != -1) {
				return true;
			}
		}
	}
	return false;
}

// 评估当前位置
int evaluatePosition(int i, int j, int color) {
	int score = 0;
	for (int k = 0; k < 4; k++) {
		int length = 0, enemy = 0;
		// 向正方向扩展
		int nowi = i, nowj = j;
		while (nowi >= 0 && nowj >= 0 && nowi <= 18 && nowj <= 18 &&
			BOX[nowi][nowj].value == color) {
			length++;
			nowi += dx[k];
			nowj += dy[k];
		}
		if (nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18 || BOX[nowi][nowj].value == !color) {
			enemy++;
		}

		// 向反方向扩展
		nowi = i, nowj = j;
		while (nowi >= 0 && nowj >= 0 && nowi <= 18 && nowj <= 18 &&
			BOX[nowi][nowj].value == color) {
			length++;
			nowi -= dx[k];
			nowj -= dy[k];
		}
		if (nowi < 0 || nowj < 0 || nowi > 18 || nowj > 18 || BOX[nowi][nowj].value == !color) {
			enemy++;
		}

		length -= 2; // 去掉中心点
		if (length > 4) {
			length = 4;
		}
		score += Score[enemy][length];
	}
	return score;
}


seat findBestSeatOldVersion(int color, int c) {
	if (c == 0) {
		// 如果是第一层
		// 清空数组
		mylength = 0;
	}

	int MAXnumber = -1e9; // 最佳分数
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (BOX[i][j].value == -1) { // 遍历每一个空位置
				if (!hasAdjacent(i, j)) {
					// 如果周围没有棋子，就不用递归了
					continue;
				}

				// 自己落子
				BOX[i][j].value = color;
				int thescore = evaluatePosition(i, j, color); // 计算己方评分
				BOX[i][j].value = !color;
				thescore += evaluatePosition(i, j, !color); // 计算对手评分
				BOX[i][j].value = -1; // 恢复为空

				if (thescore >= 500) {
					// 如果此位置可以直接胜利
					return { i, j, thescore };
				}

				// 如果递归深度未到上限，继续递归
				if (c < 3) {
					BOX[i][j].value = color;
					int nowScore = thescore - findBestSeatOldVersion(!color, c + 1).number; // 递归求解
					BOX[i][j].value = -1;

					if (nowScore > MAXnumber) {
						MAXnumber = nowScore; // 更新最大分数
						if (c == 0) {
							mylength = 0; // 第一层清空数组
						}
					}
					if (c == 0 && nowScore >= MAXnumber) {
						// 第一层记录所有最高分位置
						MAXxs[mylength] = i;
						MAXys[mylength] = j;
						mylength++;
					}
				}
				else {
					// 如果是最后一层
					if (thescore > MAXnumber) {
						MAXnumber = thescore; // 更新最大分数
					}
				}
			}
		}
	}

	if (c == 0 && mylength > 0) {
		// 如果是第一层，随机化落子位置
		int mynum = rand() % mylength;
		return { MAXxs[mynum], MAXys[mynum], MAXnumber };
	}

	// 返回当前最佳分数
	return { 0, 0, MAXnumber };
}

// 寻找最佳位置
// 用 minimax 结合 alpha-beta剪枝算法实现
seat findBestSeat(int color, int c, int alpha = -1e9, int beta = 1e9) {
	if (c == 0) {
		// 如果是第一层
		// 清空数组
		mylength = 0;
	}

	int MAXnumber = -1e9; // 当前最大分数
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (BOX[i][j].value == -1) { // 遍历每一个空位置
				if (!hasAdjacent(i, j)) {
					// 如果周围没有棋子，就不用递归了
					continue;
				}

				// 自己落子
				BOX[i][j].value = color;
				int thescore = evaluatePosition(i, j, color); // 计算己方评分
				BOX[i][j].value = !color;
				thescore += evaluatePosition(i, j, !color); // 计算对手评分
				BOX[i][j].value = -1; // 恢复为空

				if (thescore >= 500) {
					// 如果此位置可以直接胜利
					return { i, j, thescore };
				}

				// 如果递归深度未到上限，继续递归
				if (c < 3) {
					BOX[i][j].value = color;
					int nowScore = thescore - findBestSeat(!color, c + 1, -beta, -alpha).number; // 递归求解
					BOX[i][j].value = -1;

					if (nowScore > MAXnumber) {
						MAXnumber = nowScore; // 更新最大分数
						if (c == 0) {
							mylength = 0; // 第一层清空数组
						}
					}
					if (c == 0 && nowScore >= MAXnumber) {
						// 第一层记录所有最高分位置
						MAXxs[mylength] = i;
						MAXys[mylength] = j;
						mylength++;
					}

					// Alpha-Beta 剪枝
					alpha = max(alpha, nowScore);
					if (alpha >= beta) {
						BOX[i][j].value = -1; // 恢复棋盘
						return { i, j, alpha };
					}
				}
				else {
					// 如果是最后一层
					if (thescore > MAXnumber) {
						MAXnumber = thescore; // 更新最大分数
					}
				}
			}
		}
	}

	if (c == 0 && mylength > 0) {
		// 如果是第一层，随机化落子位置
		int mynum = rand() % mylength;
		return { MAXxs[mynum], MAXys[mynum], MAXnumber };
	}

	// 返回当前最佳分数
	return { 0, 0, MAXnumber };
}

// 判断输赢
void isWIN()
{
	bool isfull = true; // 棋盘是否满了
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (BOX[i][j].value != -1)
			{
				// 遍历每个可能的位置
				int nowcolor = BOX[i][j].value; // 现在遍历到的颜色
				int length[4] = { 0,0,0,0 };    // 四个方向的长度
				for (int k = 0; k < 4; k++)
				{
					// 原理同寻找最佳位置
					int nowi = i;
					int nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && BOX[nowi][nowj].value == nowcolor)
					{
						length[k]++;
						nowj += dx[k];
						nowi += dy[k];
					}
					nowi = i;
					nowj = j;
					while (nowi <= 18 && nowj <= 18 && nowi >= 0 && nowj >= 0 && BOX[nowi][nowj].value == 1 - nowcolor)
					{
						length[k]++;
						nowj -= dx[k];
						nowi -= dy[k];
					}
				}
				for (int k = 0; k < 4; k++)
				{
					if (length[k] >= 5) {
						// 如果满五子
						if (nowcolor == playercolor)
						{
							win = playercolor; // 玩家胜
						}
						if (nowcolor == 1 - playercolor)
						{
							win = 1 - playercolor; // 电脑胜
						}
					}
				}
			}
			else
			{
				//如果为空
				isfull = false;//棋盘没满
			}
		}
	}
	if (isfull)
	{
		// 如果棋盘满了
		win = 2; // 平局
	}
}

// 游戏主函数
void game() {
	bool isinit = false;
	// 上一个鼠标停的坐标
	int oldi = 0;
	int oldj = 0;

	// 随机化玩家颜色（仅人机对战和双机对战模式）
	srand(time(NULL));
	if (gameMode == 1 || gameMode == 3) { // 人机对战或双机对战模式
		playercolor = rand() % 2; // 随机决定玩家颜色（0 白，1 黑）
	}
	else { // 双人对战模式
		playercolor = 0; // 玩家1执黑，玩家2执白
	}

	// 绘制背景
	setfillcolor(RGB(255, 205, 150));
	solidrectangle(40, 25, 645, 630);

	// 设置字体样式
	settextstyle(30, 15, 0, 0, 0, 1000, false, false, false);
	settextcolor(BLACK);

	// 输出模式标示语
	if (gameMode == 1) { // 人机对战模式
		if (playercolor == 0) {
			isinit = true;
			outtextxy(150, 650, _T("玩家执白子后行 电脑执黑子先行"));
			whoplay = 1; // 电脑先行
		}
		else {
			isinit = true;
			outtextxy(150, 650, _T("玩家执黑子先行 电脑执白子后行"));
			whoplay = 0; // 玩家先行
		}
	}
	else if (gameMode == 2) { // 双人对战模式
		outtextxy(150, 650, _T("玩家1执黑子 玩家2执白子"));
		whoplay = 0; // 玩家1先行
	}
	else if (gameMode == 3) { // 双机对战模式
		isinit = true;
		outtextxy(150, 650, _T("AI1执黑子 AI2执白子"));
		whoplay = playercolor; // 随机先手
	}

	draw(); // 绘制棋盘

	while (1) {
	NEXTPLAYER:
		if (gameMode == 2 || (gameMode == 1 && whoplay == 0)) {
			// 玩家下棋（双人对战 或 人机对战中的玩家回合）
			MOUSEMSG mouse = GetMouseMsg(); // 获取鼠标信息
			for (int i = 0; i < 19; i++) {
				for (int j = 0; j < 19; j++) {
					if (mouse.x > BOX[i][j].x && mouse.x < BOX[i][j].x + 30 // 判断x坐标
						&& mouse.y > BOX[i][j].y && mouse.y < BOX[i][j].y + 30 // 判断y坐标
						&& BOX[i][j].value == -1) { // 判断是否是空位置
						// 如果停在某一个空位置上面
						if (mouse.mkLButton) { // 如果按下了
							BOX[i][j].value = playercolor; // 下棋
							BOX[i][j].isnew = true;        // 新位置更新
							oldi = -1;
							oldj = -1;

							// 切换玩家
							if (gameMode == 2) { // 双人对战模式
								playercolor = 1 - playercolor; // 切换执子颜色
							}

							whoplay = (gameMode == 2) ? 0 : 1; // 双人对战保持0，单人对战切换AI
							goto DRAW;
						}

						// 更新选择框
						BOX[oldi][oldj].isnew = false;
						BOX[oldi][oldj].draw();
						BOX[i][j].isnew = true;
						BOX[i][j].draw();
						oldi = i;
						oldj = j;
					}
				}
			}
		}
		else {
			// AI 下棋（人机对战或双机对战模式）
			if (gameMode == 1 && whoplay == 1) {
				// 人机对战中 AI 回合
				if (isinit) {
					// 开局情况，电脑执子颜色为 `1 - playercolor`
					isinit = false;
					int drawi = 9;
					int drawj = 9;
					while (BOX[drawi][drawj].value != -1) {
						drawi--;
						drawj++;
					}
					BOX[drawi][drawj].value = 1 - playercolor; // 确保 AI 的第一步落子颜色正确
					BOX[drawi][drawj].isnew = true;
				}
				else {
					seat best = findBestSeat(1 - playercolor, 0, -1e9, 1e9); // 寻找最佳位置
					BOX[best.i][best.j].value = 1 - playercolor; // 下在最佳位置
					BOX[best.i][best.j].isnew = true;
				}
			}
			else if (gameMode == 3) {
				// 双机对战模式
				if (isinit) {
					// 开局情况，电脑执子颜色为 `1 - playercolor`
					isinit = false;
					int drawi = 9;
					int drawj = 9;
					while (BOX[drawi][drawj].value != -1) {
						drawi--;
						drawj++;
					}
					BOX[drawi][drawj].value = 1 - playercolor; // 确保 AI 的第一步落子颜色正确
					BOX[drawi][drawj].isnew = true;
				}
				else {
					seat best = findBestSeat(playercolor, 0, -1e9, 1e9); // 寻找最佳位置
					BOX[best.i][best.j].value = playercolor; // AI 下在最佳位置
					BOX[best.i][best.j].isnew = true;
					playercolor = 1 - playercolor; // 切换 AI
				}
			}

			whoplay = (gameMode == 3) ? 1 : 0; // 双机对战保持循环，单人对战切换到玩家
			goto DRAW;
		}
	}
DRAW: // 绘制
	isWIN(); // 检测输赢
	draw();
	oldi = 0;
	oldj = 0;
	if (win == -1) {
		// 如果没有人胜利
		Sleep(500);
		goto NEXTPLAYER; // 前往下一个玩家
	}
	// 胜利处理
	settextcolor(RGB(0, 255, 0));
	Sleep(1000);
	if (win == 0) {
		outtextxy(320, 320, _T("白胜"));
	}
	if (win == 1) {
		outtextxy(320, 320, _T("黑胜"));
	}
	if (win == 2) {
		outtextxy(320, 320, _T("平局"));
	}
	// 给反应时间
	Sleep(3000);
	return;
}


// 游戏是否继续的选择函数
bool askToContinue() {

	cleardevice(); // 清空图形窗口
	setbkcolor(RGB(230, 230, 250)); // 设置背景颜色为浅紫色
	setfillcolor(RGB(245, 245, 220)); // 设置填充颜色为米色
	solidrectangle(0, 0, 700, 700); // 绘制整个窗口背景

	// 添加顶部标题
	settextstyle(40, 0, _T("Consolas"));
	settextcolor(RGB(0, 100, 200)); // 蓝色字体
	outtextxy(200, 100, _T("游戏结束！"));

	setlinecolor(RGB(100, 149, 237)); // 设置边框颜色为天蓝色
	setlinestyle(PS_SOLID, 3); // 设置实线边框
	rectangle(150, 180, 550, 450); // 绘制选择框

	settextstyle(30, 0, _T("Consolas"));
	settextcolor(BLACK);
	outtextxy(200, 200, _T("是否继续游戏？"));
	outtextxy(200, 250, _T("继续（输入Y或y）"));
	outtextxy(200, 300, _T("结束（输入N或n) "));


	std::cout << "Do you want to play again? (Y/y for yes,N/n for no): ";  // 在控制台输出提示信息
	char ch;
	std::cin >> ch;

	// 等待用户输入 'Y' 或 'N'
	while (toupper(ch) != 'Y' && toupper(ch) != 'N') {
		std::cout << "Error.Please input 'Y/y' or 'N/n': ";
		std::cin >> ch;
	}

	// 根据用户输入判断是否继续游戏
	if (toupper(ch) == 'Y')
	{	
		outtextxy(300, 500, _T("游戏继续"));
	}
	else if (toupper(ch) == 'N') {
		outtextxy(300, 500, _T("游戏结束"));
	}

	// 添加图案作为装饰
	setfillcolor(RGB(255, 192, 203)); // 设置填充颜色为粉色
	fillcircle(350, 600, 30); // 绘制底部装饰圆

	Sleep(1500); // 等待 1.5 秒让用户看到选择结果
	return toupper(ch) == 'Y';
}