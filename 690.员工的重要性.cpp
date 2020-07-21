/*
// Definition for Employee.
class Employee {
public:
int id;
int importance;
vector<int> subordinates;
};
*/
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//class Solution {
//	int dfs(unordered_map<int, Employee*> &Emap, int &sum, int id){
//		sum += Emap[id]->importance;
//		for (auto i : Emap[id]->subordinates){
//			dfs(Emap, sum, i);
//		}
//		return sum;
//	}
//public:
//	int getImportance(vector<Employee*> employees, int id) {
//		if (employees.empty())
//			return 0;
//		unordered_map<int, Employee*> Emap;
//		for (auto it : employees){
//			Emap[it->id] = it;
//		}
//		int sum = 0;
//		dfs(Emap, sum, id);
//		return sum;
//	}
//};