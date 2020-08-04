#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		sort(satisfaction.begin(), satisfaction.end(), greater<int>());
		int sum = 0, tmp = 0;
		for (auto it : satisfaction){
			if (tmp + it>0){
				tmp += it;
				sum += tmp;
			}
			else{
				break;
			}
		}
		return sum;
	}
};