//���ӣ�https://www.nowcoder.com/questionTerminal/6acc6504df67406c98a75f5575e4b94a
//��Դ��ţ����
//
//����СQ�ֿ�ʼ��������������СQ�ó���һ����NxM���ظ�Ļ���, �����ʼ״̬�ǿհ׵�, ��'X'��ʾ��
//СQ�������صĻ滭����, ÿ��СQ��ѡ��һ��б��, ���б�ߵķ�������'/', ��б��Ϊ1, СQ��ѡ������б���е�һ�θ���, ��Ϳ��Ϊ��ɫ, ��'B'��ʾ; ����Խ��ߵķ�������'\',��б��Ϊ-1,СQ��ѡ������б���е�һ�θ���,��Ϳ��Ϊ��ɫ,��'Y'��ʾ��
//���һ�����Ӽȱ���ɫͿ�����ֱ���ɫͿ����, ��ô������Ӿͻ�����ɫ, ��'G'��ʾ��
//СQ�Ѿ����뻭������Ʒ������, �����������һ����������Ҫ���ٴβ�������������

//�������� :
//ÿ���������һ������������
//ÿ�����������ĵ�һ�а�������������N��M(1 <= N, M <= 50), ��ʾ����ĳ���
//��������N�а���N������ΪM���ַ���, ���а����ַ�'B', 'Y', 'G', 'X', �ֱ��ʾ��ɫ, ��ɫ, ��ɫ, �հס�������ʾСQҪ��ɵ���Ʒ��

//�������:
//���һ��������, ��ʾСQ������Ҫ���ٴβ�����ɻ滭��

//����
//4 4
//YXXB
//XYGX
//XBYY
//BXXY
//���
//3
//˵��
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
int n = 0; // ��
int m = 0; // ��
char str[50][50];
void dfs_Y(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m
		&& (str[x][y] == 'Y' || str[x][y] == 'G')) {
		// ���Y
		if (str[x][y] == 'G')
			str[x][y] = 'B';
		else
			str[x][y] = 'X';
		dfs_Y(x - 1, y - 1); // �����Ϸ�����
		dfs_Y(x + 1, y + 1); // �����·�����
	}
	return;
}
void dfs_B(int x, int y) {
	if (x >= 0 && x < n && 0 <= y && y < m
		&& (str[x][y] == 'B' || str[x][y] == 'G')) {
		// ���B
		if (str[x][y] == 'G')
			str[x][y] = 'Y';
		else
			str[x][y] = 'X';
		dfs_B(x + 1, y - 1); // �����·�����
		dfs_B(x - 1, y + 1); // �����Ϸ�����
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
			if (str[i][j] == 'Y') { // ��б��
				dfs_Y(i, j);
				cnt++;
			}
			else if (str[i][j] == 'B') { // б��
				dfs_B(i, j);
				cnt++;
			}
			else if (str[i][j] == 'G') { // ����
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

