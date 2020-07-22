#include"newcodetest_head.h"
void reOrderArray(vector<int> &array) {
	int start = 0;
	int end = array.size() - 1;
	while (start<end){
		while (array[start] % 2)
			start++;
		while (array[end] % 2 == 0)
			end--;
		if (start<end)
		{
			swap(array[start], array[end]);
			start++;
			end--;
		}
	}
}


int main(){
	vector<int> res = { 1, 2, 3, 4, 5, 6, 7, 8 };
	reOrderArray(res);
	for (auto i : res){
		cout << i << " ";
	}
	system("pause");
	return 0;
}