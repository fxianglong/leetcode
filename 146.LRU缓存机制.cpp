#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto ht_it = _ht.find(key);
		if (ht_it == _ht.end())
			return -1;
		else{
			list<pair<int, int>>::iterator It_it = ht_it->second;
			pair<int, int> kv = *(It_it);
			lru_lt.erase(It_it);
			lru_lt.push_front(kv);
			_ht[key] = lru_lt.begin();
			return kv.second;
		}
	}

	void put(int key, int value) {
		auto ht_it = _ht.find(key);
		if (ht_it == _ht.end()){
			if (lru_lt.size() == _capacity){
				_ht.erase(lru_lt.back().first);
				lru_lt.pop_back();
			}
			lru_lt.push_front(make_pair(key, value));
			_ht[key] = lru_lt.begin();
		}
		else
		{
			lru_lt.erase(ht_it->second);
			lru_lt.push_front(make_pair(key, value));
			ht_it->second = lru_lt.begin();
		}
	}
private:
	unordered_map<int, list<pair<int,int>>::iterator> _ht;
	int _capacity;
	list<pair<int,int>> lru_lt;
};