#include<iostream>
#include<string>
using namespace std;
void Reverse(string &str, int start, int end){
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
} 
string ReverseSentence(string str) {
	if (str.size() == 0){
		return str;
	} 
	int i = 0;
	int j = i;
	int len = str.size();
	while (i < len){
		while (i < len && !isspace(str[i])) i++;
		Reverse(str, j, i - 1);
		while (i < len && isspace(str[i])) i++; 
			j = i;
	} 
	Reverse(str, j, i - 1);
	Reverse(str, 0, i - 1); 
	return str;
}


int main(){
	string s = "student. a am I";
	cout<<ReverseSentence(s)<<endl;
	system("pause");
	return 0;
}