//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//struct Point {
//	int x;
//	int y;
//};
//
//
//vector<int> G[100003];
//bool vis[100003];
//bool DFS(int s, int pre){
//	for (int i = 0; i<G[s].size(); i++){
//		if (G[s][i] == pre)
//			continue;
//		if (G[s][i] == 1)
//			return true;
//		if (!vis[G[s][i]]){
//			vis[G[s][i]] = true;
//			if (DFS(G[s][i], s))
//				return true;
//		}
//	}
//	return false;
//}
//string solve(vector<int>& param, vector<Point>& edge) {
//	for (int i = 0; i<edge.size(); i++){
//		G[edge[i].x].push_back(edge[i].y);
//		G[edge[i].y].push_back(edge[i].x);
//	}
//	if (DFS(1, 1))
//		return "Yes";
//	else
//		return "No";
//}
//
//int main(){
//	vector<int> param = { 4, 4 };
//	vector<Point> edge = { (1, 2), (2, 3), (3, 4), (4, 1) };
//}