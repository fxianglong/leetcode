#include<iostream>
using namespace std;
#include<vector>


int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,
		int sr, int sc, int oldColor, int newColor)
	{
		//处理当前逻辑，修改颜色，并且标记已经修改过了
		image[sr][sc] = newColor;
		book[sr][sc] = 1;
		//遍历每一种可能，四个方向
		for (int k = 0; k < 4; ++k){
		int newSr = sr + nextPosition[k][0];
		int newSc = sc + nextPosition[k][1];
		//判断新位置是否越界
		if (newSr >= row || newSr < 0
			|| newSc >= col || newSc < 0)
			continue;
		//如果颜色符合要求，并且之前也没有渲染过，则继续渲染
		if (image[newSr][newSc] == oldColor && book[newSr][newSc] == 0)
		{
			dfs(image, row, col, book, newSr, newSc, oldColor, newColor);
		}
	}
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	if (image.empty())
		return image;
	int row = image.size();
	int col = image[0].size();
	//建立标记
	vector<vector<int>> book;
	book.resize(row);
	for (int i = 0; i < row; ++i)
	{
		book[i].resize(col, 0);
	}
	//获取旧的颜色
	int oldColor = image[sr][sc];
	dfs(image, row, col, book, sr, sc, oldColor, newColor);
	return image;
}

int main(){
	vector<vector<int>> image(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		cin >> image[i][j];
	floodFill(image, 1, 1, 2);
	return 0;
}
