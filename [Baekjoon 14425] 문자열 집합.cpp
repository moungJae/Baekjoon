#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

struct Trie* get_Trie();

struct Trie {
	Trie* next[26];
	bool check;
	void set_Trie(const char* sentence) {
		if (*sentence == '\0') 
			check = true;
		else {
			if (next[*sentence - 'a'] == NULL)
				next[*sentence - 'a'] = get_Trie();
			next[*sentence - 'a']->set_Trie(sentence + 1);
		}
	}
	bool is_Exist(const char* sentence) {
		if (*sentence == '\0')
			return check;
		if (next[*sentence - 'a'] == NULL)
			return false;
		return next[*sentence - 'a']->is_Exist(sentence + 1);
	}
	void clear() {
		check = false;
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};

Trie mem_pool[5000001];
int mem_size;

Trie* get_Trie() {
	Trie* ret;
	ret = &mem_pool[mem_size++];
	ret->clear();
	return ret;
}

int N, M;
Trie* root;

void solution() {
	int cnt;
	char S[502];
	
	scanf("%d %d", &N, &M);
	root = get_Trie();

	while (N--) {
		scanf("%s", S);
		root->set_Trie(S);
	}

	cnt = 0;
	while (M--) {
		scanf("%s", S);
		if (root->is_Exist(S))
			cnt++;
	}

	printf("%d", cnt);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solution();

	return 0;
}