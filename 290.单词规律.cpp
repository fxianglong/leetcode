class Solution {
public:
    //按照s来分割字符串strs
    vector<string> split(string strs,char s){
        vector<string> res;
        string ss;
        for(int i=0;i<strs.size();++i){
            if(strs[i]==s){
                if(ss.size())
                    res.push_back(ss);
                ss="";
            }
            else ss+=strs[i];
        }
        if(ss.size()) res.push_back(ss);
        return res;
    }
    bool wordPattern(string pattern, string s) {
        //char->string哈希表
        unordered_map<char,string> hash_map;
        //string->char哈希表
        unordered_map<string,char> hash_map_1;
        vector<string> words=split(s,' ');
        int tag=0;
        //字符串长度和单词数不同返回false
        if(pattern.size()!=words.size()) return false;
        //char->string 哈希检查
        for(char& pat:pattern){
            if(hash_map.count(pat)==0)
                hash_map[pat]=words[tag];
            else if(hash_map[pat]!=words[tag])
                return false;
            tag++;
        }
        tag=0;
        //string->char 哈希检查
        for(string& word:words){
            if(hash_map_1.count(word)==0)
                hash_map_1[word]=pattern[tag];
            else if(hash_map_1[word]!=pattern[tag])
                return false;
            tag++;
        }
        //通过双向检查
        return true;
    }
};