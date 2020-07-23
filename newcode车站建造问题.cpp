//#include<stdio.h>
//#include<stdlib.h>
//bool isprime(int x){
//	for (int i = 2; i*i<=x; i++){
//		if (x%i)
//			continue;
//		return false;
//	}
//	return true;
//}
//int work(int n, int* a, int aLen) {
//	int count = n;
//	for (int i = 1; i<n; i++){
//		int dist = a[i] - a[i - 1];
//		if (dist != 1 && !isprime(dist)) {
//			if (dist % 2 == 0 || isprime(dist - 2))
//				count += 1;
//			else
//				count += 2;
//		}
//	}
//	return count;
//}
//
//int main(){
//	int a[7] = { 0, 3, 10, 15, 16, 24, 28 };
//	printf("%d", work(7, a, 7));
//	system("pause");
//	return 0;
//}
//
