#include<string>
#include<iostream>
using namespace std;
int main(){
	string str;
	while (cin >> str){
		int right = str.size();
		int left = 0;
		while (right > left){
			swap(str[left], str[right]);
			left++;
			right--;
		}
		cout << str << endl;
	}
	return 0;
}