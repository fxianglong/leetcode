#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	auto ans=vector < vector <int> >(s1.size()+1, vector<int>(s2.size()+1, false));
    	if(s1.size()+s2.size()!=s3.size())
        		return false;
	ans[0][0] = true;
	for (int i = 0; i <= s1.size();i++)
	for (int j = 0; j <= s2.size(); j++){
		int p = i + j - 1;
		if (i > 0){
			ans[i][j] |= (ans[i - 1][j] && s1[i - 1] == s3[p]);
		}
		if (j > 0){
			ans[i][j] |= (ans[i][j - 1] && s2[j - 1] == s3[p]);
		}
	}
	return ans[s1.size()][s2.size()];
}

int main(){
	string s1 ="aabcc" , s2 ="dbbca" , s3 ="aadbbcbcac" ;
	cout<<isInterleave(s1, s2, s3)<<endl;
	system("pause");
	return 0;
}