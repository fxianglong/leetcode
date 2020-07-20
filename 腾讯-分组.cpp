
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int f[N][3][3], a[N], n, m, x;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &x), a[x]++;
	}
	memset(f, -1, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 0; i < m + 2; i++){
		for (int t1 = 0; t1 <= 2; t1++){
			for (int t2 = 0; t2 <= 2; t2++){
				if (~f[i][t1][t2]){
					for (int t3 = 0; t3 <= 2; t3++){
						if (t1 + t2 + t3>a[i + 1])
							continue;
						f[i + 1][t2][t3] = max(
							f[i + 1][t2][t3],
							f[i][t1][t2] + t3 + (a[i + 1] - t1 - t2 - t3) / 3);
					}
				}
			}
		}
	}
	printf("%d\n", f[m + 2][0][0]);
	system("pause");
	return 0;
}