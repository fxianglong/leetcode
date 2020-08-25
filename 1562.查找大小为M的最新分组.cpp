//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int findLatestStep(vector<int>& arr, int m) {
//	int len = arr.size();
//	string s = "";
//	for (int i = 0; i<len; i++)
//		s += "0";
//	if (m>len)
//		return -1;
//	int col = -1;
//	for (int n = 0; n<arr.size(); n++){
//		s[arr[n]-1] = '1';
//		for (int i = 0; i<len; i++){
//			if (s[i] == '1'){
//				int j = 1;
//				while (i + j<len&&s[i + j] == '1'){
//					j++;
//				}
//				if (j == m)
//					col = n;
//				i += j;
//			}
//		}
//	}
//	return col;
//}
//
//int main(){
//	vector<int> ans = { 3, 5, 1, 2, 4 };
//	cout<<findLatestStep(ans, 1)<<endl;
//	system("pause");
//	return 0;
//}


#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	static int findLatestStep(vector<int>& arr, int m) {
		int n = arr.size();
		int ans = -1;
		vector<int> count(n + 2, 0);
		vector<int> left(n + 2, 0);
		vector<int> right(n + 2, 0);

		for (int i = 0; i < n; ++i){
			int x = arr[i];
			int l = left[x - 1] + 1 + right[x + 1];
			left[x + right[x + 1]] = l;
			right[x - left[x - 1]] = l;
			count[left[x - 1]]--;
			count[right[x + 1]]--;
			count[l]++;

			if (count[m] > 0){
				ans = i + 1;
			}
		}

		return ans;
	}
};
//int main(){
//	vector<int> ans = { 3, 1, 5, 4, 2 };
//	cout << Solution::findLatestStep(ans, 2) << endl;
//	system("pause");
//	return 0;
//}




//³¬Ê±´úÂë
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int findLatestStep(vector<int>& arr, int m) {
//	int len = arr.size();
//	if (m == len)
//		return m;
//	string str = "";
//	for (int i = 0; i < len; i++){
//		str += '1';
//	}
//	int col = -1;
//	for (int x = arr.size() - 1; x >= 0; x--){
//		str[arr[x]-1] = '0';
//		for (int i = 0; i < len; i++){
//			int j = 0;
//			while (i+j<len&&str[i + j] == '1'){
//				j++;
//			}
//			if (j == m){
//				return x;
//			}
//			i += j;
//		}
//	}
//	return -1;
//}
//
//int main(){
//	vector<int> ans = { 1 };
//	cout << findLatestStep(ans, 1) << endl;
//	system("pause");
//	return 0;
//}