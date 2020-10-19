#include<iostream>
#include<string>
using namespace std;
bool backspaceCompare(string S, string T) {
	string s = "";
	for (int i = 0; i<S.size(); i++){
		if (S[i] == '#'&&!s.empty())
			s.pop_back();
		else
		if (S[i]!='#')
			s.push_back(S[i]);
	}
	string t = "";
	for (int i = 0; i<T.size(); i++){
		if (T[i] == '#'&&!t.empty())
			t.pop_back();
		else
		if (T[i] != '#')
			t.push_back(T[i]);
	}
	if (s == t)
		return true;
	else
		return false;
}
int main(){
	cout << backspaceCompare("y#fo##f","y#f#o##f") << endl;
	system("pause");
	return 0;
}