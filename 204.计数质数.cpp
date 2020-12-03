class Solution {
public:
    int countPrimes(int n) {
    int count = 0;
    const int size = sizeof(int) * 8;
    vector<int> signs(n / size + 1,0);
    for (int i = 2; i < n; i++){
        if ((signs[i / size] & (1 << (i & (size - 1)))) == 0){
            count++;
            for (int j = i + i; j < n; j += i){
            	signs[j / size] |= 1 << (j & (size - 1));
            }
        }
    }
    return count;
    }
};