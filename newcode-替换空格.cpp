#include"newcodetest_head.h"
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		char* start = str;
		while (*start != '\0'){
			if (*start == ' ')
				count++;
			start++;
		}
		char* new_end = str + length + count * 2;
		char* old_end = str + length;
		while (old_end >= str&&new_end >= str){
			if (*old_end != ' '){
				*new_end = *old_end;
				new_end--;
				old_end--;
			}
			else{
				*new_end = '0';
				new_end--;
				*new_end = '2';
				new_end--;
				*new_end = '%';
				new_end--;
				old_end--;
			}
		}
	}
};