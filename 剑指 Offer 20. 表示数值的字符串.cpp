class Solution {
public:
	bool isNumber(string s) {
		int n = s.size();
		// ȥ����β�ո�
		int bg = 0, ed = n - 1;
		while (bg<n && s[bg] == ' ') bg++;
		while (ed >= 0 && s[ed] == ' ') ed--;
		if (ed<bg) return false;

		string ss = s.substr(bg, ed - bg + 1);
		int i = 0;
		n = ed - bg + 1;
		// ��������
		if (ss[i] == '+' || ss[i] == '-') i++;

		bool ef = false, df = false, nf = false;
		while (i<n){
			if (ss[i] - '0' >= 0 && ss[i] - '0' <= 9){
				nf = true;
			}
			else if (ss[i] == '.'){
				if (ef) return false;    // ������e�ĺ���
				if (!df){                // ���ֶ��
					df = true;
				}
				else{
					return false;
				}
			}
			else if (ss[i] == 'e' || ss[i] == 'E'){
				if (!ef){                // ���ֶ��
					if (!nf)             // �ж�eǰ�Ƿ��������
						return false;
					else
						ef = true;
				}
				else{
					return false;
				}
				nf = false;              // ����֮���ж�e���Ƿ��������
				if (i + 1<n && (ss[i + 1] == '+' || ss[i + 1] == '-')) // ��������
					i++;
			}
			else{                     //�����ַ�
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