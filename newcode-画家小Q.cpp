//链接：https://www.nowcoder.com/questionTerminal/6acc6504df67406c98a75f5575e4b94a
//来源：牛客网
//
//画家小Q又开始他的艺术创作。小Q拿出了一块有NxM像素格的画板, 画板初始状态是空白的, 用'X'表示。
//小Q有他独特的绘画技巧, 每次小Q会选择一条斜线, 如果斜线的方向形如'/', 即斜率为1, 小Q会选择这条斜线中的一段格子, 都涂画为蓝色, 用'B'表示; 如果对角线的方向形如'\',即斜率为-1,小Q会选择这条斜线中的一段格子,都涂画为黄色,用'Y'表示。
//如果一个格子既被蓝色涂画过又被黄色涂画过, 那么这个格子就会变成绿色, 用'G'表示。
//小Q已经有想画出的作品的样子, 请你帮他计算一下他最少需要多少次操作完成这幅画。

//输入描述 :
//每个输入包含一个测试用例。
//每个测试用例的第一行包含两个正整数N和M(1 <= N, M <= 50), 表示画板的长宽。
//接下来的N行包含N个长度为M的字符串, 其中包含字符'B', 'Y', 'G', 'X', 分别表示蓝色, 黄色, 绿色, 空白。整个表示小Q要完成的作品。

//输出描述:
//输出一个正整数, 表示小Q最少需要多少次操作完成绘画。

//输入
//4 4
//YXXB
//XYGX
//XBYY
//BXXY
//输出
//3
//说明
//XXXX
//XXXX
//XXXX
//XXXX
//->
//YXXX
//XYXX
//XXYX
//XXXY
//->
//YXXB
//XYBX
//XBYX
//BXXY
//->
//YXXB
//XYGX
//XBYY
//BXXY



#include<iostream>
using namespace std;

using namespace std;
int n = 0; // 行
int m = 0; // 列
char str[50][50];
void dfs_Y(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m
		&& (str[x][y] == 'Y' || str[x][y] == 'G')) {
		// 清除Y
		if (str[x][y] == 'G')
			str[x][y] = 'B';
		else
			str[x][y] = 'X';
		dfs_Y(x - 1, y - 1); // 向左上方遍历
		dfs_Y(x + 1, y + 1); // 向右下方遍历
	}
	return;
}
void dfs_B(int x, int y) {
	if (x >= 0 && x < n && 0 <= y && y < m
		&& (str[x][y] == 'B' || str[x][y] == 'G')) {
		// 清除B
		if (str[x][y] == 'G')
			str[x][y] = 'Y';
		else
			str[x][y] = 'X';
		dfs_B(x + 1, y - 1); // 向左下方遍历
		dfs_B(x - 1, y + 1); // 向右上方遍历
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'Y') { // 反斜线
				dfs_Y(i, j);
				cnt++;
			}
			else if (str[i][j] == 'B') { // 斜线
				dfs_B(i, j);
				cnt++;
			}
			else if (str[i][j] == 'G') { // 交叉
				dfs_Y(i, j);
				str[i][j] = 'B';
				dfs_B(i, j);
				cnt += 2;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
} 

