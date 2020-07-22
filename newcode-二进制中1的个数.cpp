#include"newcodetest_head.h"

//class Solution {
//public:
//	int  NumberOf1(int n) {
//		int count = 0;
//		while (n){
//			n &= (n - 1);
//			count++;
//		}
//		return count;
//	}
//};


//³¬Ê±
class Solution {
public:
static int  NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			if (n & 1 == 1)
				count++;

			n = n >> 1;
		}
		return count;
	}
};
