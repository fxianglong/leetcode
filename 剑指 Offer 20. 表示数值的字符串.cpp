class Solution {
public:
	bool isNumber(string s) {
		int n = s.size();
		// 去除收尾空格
		int bg = 0, ed = n - 1;
		while (bg<n && s[bg] == ' ') bg++;
		while (ed >= 0 && s[ed] == ' ') ed--;
		if (ed<bg) return false;

		string ss = s.substr(bg, ed - bg + 1);
		int i = 0;
		n = ed - bg + 1;
		// 跳过符号
		if (ss[i] == '+' || ss[i] == '-') i++;

		bool ef = false, df = false, nf = false;
		while (i<n){
			if (ss[i] - '0' >= 0 && ss[i] - '0' <= 9){
				nf = true;
			}
			else if (ss[i] == '.'){
				if (ef) return false;    // 出现在e的后面
				if (!df){                // 出现多次
					df = true;
				}
				else{
					return false;
				}
			}
			else if (ss[i] == 'e' || ss[i] == 'E'){
				if (!ef){                // 出现多次
					if (!nf)             // 判断e前是否存在数字
						return false;
					else
						ef = true;
				}
				else{
					return false;
				}
				nf = false;              // 用于之后判断e后是否存在数字
				if (i + 1<n && (ss[i + 1] == '+' || ss[i + 1] == '-')) // 跳过符号
					i++;
			}
			else{                     //其他字符
				return false;
			}

			i++;
		}

		if (nf)
			return true;
		else
			return false;
	}
};