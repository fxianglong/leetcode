//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main(){
//	string str;
//	getline(cin, str);
//	vector<string> res;
//	for (int i = 0; i < str.size(); i++){
//		if (i == 0){
//			str[i] -= 32;
//			int j = 1;
//			while ((i + j)<str.size() && str[i + j] != 'n')
//				j++;
//			/*string s = str.substr(i, j);
//			res.push_back(s);*/
//			str.insert(i + j, "\n");
//			i += j;
//		}
//		if (str[i] == 'n'){
//			int j = 1;
//			while ((i+j)<str.size() && str[i + j] != 'n')
//				j++;
//			string s = str.substr(i, j);
//			/*s[0] = 'N';*/
//			/*res.push_back(s);*/
//			str[i] = 'N';
//			str.insert(i + j, "\n");
//			i = i+j-1;
//		}
//	}
//	//for (auto e : res){
//	//	cout << e << endl;
//	//}
//	cout << str << endl;
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//	int n, m;
//	cin >> n >> m;
//	vector<vector<int>> ans(n,vector<int>(m+1,0));
//	for (int i = 0; i < n; i++){
//		ans[i][0] = 0;
//		for (int j = 1; j <= m; j++){
//			cin >> ans[i][j];
//		}
//	}
//	int max = 0;
//	vector<int> res(m);
//	for (int i = 0; i <= m; i++){
//		int max = ans[0][i];
//		for (int j = 1; j < n; j++){
//			if (max < ans[j][i]){
//				max = ans[j][i];
//			}
//		}
//		res[i] = max;
//	}
//	max = 0;
//	for (int i = 0, j = m; i <= m&&j >= 0; i++, j--){
//		if (max<res[i] + res[j])
//		max = res[i] + res[j];
//	}
//	cout << max << endl;
//	return 0;
//}