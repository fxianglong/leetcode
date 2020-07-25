#include<iostream>
using namespace std;
#include<string>

string LeftRotateString(string str, int n) {
	string newstr = str + str;
	for (int i = 0; i<str.size(); i++){
		str[i] = newstr[i + n];
	}
	return str;
}
int main(){
	string s = "abcdefg";
	int n = 2;
	cout<<LeftRotateString(s, n)<<endl;
	system("pause");
	return 0;
}