#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

void backtracking(vector<int>& nums, vector<vector<int>>& result, vector<int>& subseq, int startIndex) {
	if (subseq.size() > 1) {
		result.push_back(subseq);
		// ע�����ﲻҪ��return����ΪҪȡ���еĿ���
	}
	unordered_set<int> uset; // ʹ��set����β��Ԫ�ؽ���ȥ��
	for (int i = startIndex; i < nums.size(); i++) {
		if ((subseq.empty() || nums[i] >= subseq.back())
			&& uset.find(nums[i]) == uset.end()) {
			subseq.push_back(nums[i]);
			backtracking(nums, result, subseq, i + 1);
			subseq.pop_back();
			uset.insert(nums[i]);//�ڻ��ݵ�ʱ�򣬼�¼���Ԫ���ù��ˣ����治��������
		}
	}
}
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> subseq;
		backtracking(nums, result, subseq, 0);
		return result;
	}