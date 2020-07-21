#include<iostream>
using namespace std;
#include<vector>


int nextPosition[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
class Solution {
public:
	void dfs(vector<vector<int>>& image, int row, int col, vector<vector<int>>& book,
		int sr, int sc, int oldColor, int newColor)
	{
		//����ǰ�߼����޸���ɫ�����ұ���Ѿ��޸Ĺ���
		image[sr][sc] = newColor;
		book[sr][sc] = 1;
		//����ÿһ�ֿ��ܣ��ĸ�����
		for (int k = 0; k < 4; ++k){
		int newSr = sr + nextPosition[k][0];
		int newSc = sc + nextPosition[k][1];
		//�ж���λ���Ƿ�Խ��
		if (newSr >= row || newSr < 0
			|| newSc >= col || newSc < 0)
			continue;
		//�����ɫ����Ҫ�󣬲���֮ǰҲû����Ⱦ�����������Ⱦ
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
	//�������
	vector<vector<int>> book;
	book.resize(row);
	for (int i = 0; i < row; ++i)
	{
		book[i].resize(col, 0);
	}
	//��ȡ�ɵ���ɫ
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
