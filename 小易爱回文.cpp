//#include<iostream>
//using namespace std;
//#include<string>
//#include<algorithm>
//bool IsReverseStr(string s, int start, int end){
//	while (s[start] == s[end]&&start<=end){
//		start++; end--;
//	}
//	if (start >= end)
//		return true;
//	return false;
//}
//int main(){
//	string str;
//	cin >> str;
//	int r = str.size() - 1;
//	int l = 0;
//	int lst = 0;
//	while (l < r){
//		if (IsReverseStr(str, l, r)){
//			lst = l;
//			break;
//		}
//		else
//		{
//			l++;
//		}
//	}
//	string pos = "";
//	if (l >= r)
//	{
//		pos = str;
//		pos.pop_back();
//		reverse(pos.begin(), pos.end());
//	}
//	else
//	{
//		pos = str.substr(0, lst);
//		reverse(pos.begin(), pos.end());
//	}
//	str += pos;
//	cout << str << endl;
//	system("pause");
//	return 0;
//}