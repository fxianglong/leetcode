#include<iostream>
using namespace std;
#include<vector>
class UnionFindSet{
public:
	UnionFindSet(int N){
		_a.resize(N, -1);
	}
	int FindRoot(int x){
		while (_a[x] > 0){
			x = _a[x];
		}
		return x;
	}
	void Union(int x1, int x2){
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2){
			_a[root1] += _a[root2];
			_a[root2] = root1;
		}
	}
	size_t SetSize(){
		size_t n = 0;
		for (auto e : _a){
			if (e<0)
				++n;
		}
		return n;
	}
private:
	vector<int> _a;
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		UnionFindSet ufs(M.size());
		for (size_t i = 0; i<M.size(); i++){
			for (size_t j = 0; j<M[0].size(); j++){
				if (i <= j)
					break;
				if (M[i][j] == 1)
					ufs.Union(i, j);
			}
		}
		return ufs.SetSize();
	}
};