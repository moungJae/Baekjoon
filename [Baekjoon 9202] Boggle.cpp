#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

typedef struct Trie {
	Trie* child[26];
	bool finish;
} Trie;

typedef struct Boggle {
	map<string, bool> m;
	string word;
	int score;
	int cnt;
} Boggle;

Trie* root;
Trie dummy[377777];
Boggle boggle;
char Map[4][4];
bool visited[4][4];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int d_cnt;

Trie* get_trie() {
	Trie* ret = &dummy[d_cnt++];

	for (int i = 0; i < 26; i++) {
		ret->child[i] = NULL;
	}
	ret->finish = false;
	return ret;
}

void set_trie(string word) {
	Trie* trie = root;
	
	for (int i = 0; i < word.size(); i++) {
		char c = word[i];
		
		if (!trie->child[c - 'A'])
			trie->child[c - 'A'] = get_trie();
		trie = trie->child[c - 'A'];
		if (i == word.size() - 1)
			trie->finish = true;
	}
}

void init() {
	root = get_trie();
	boggle.cnt = 0;
	boggle.score = 0;
	boggle.word = "";
	boggle.m = map<string, bool>();
}

bool is_in(int x, int y) {
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int get_score(string word) {
	if (word.size() == 1 || word.size() == 2)
		return 0;
	if (word.size() == 3 || word.size() == 4)
		return 1;
	if (word.size() == 5)
		return 2;
	if (word.size() == 6)
		return 3;
	if (word.size() == 7)
		return 5;
	return 11;
}

void dfs(Trie* t, int x, int y, string word) {
	if (t->finish) {
		if (!boggle.m[word]) {
			boggle.m[word] = true;
			boggle.cnt++;
			boggle.score += get_score(word);
			if (word.size() > boggle.word.size()) {
				boggle.word = word;
			}
			else if (word.size() == boggle.word.size()) {
				if (word < boggle.word)
					boggle.word = word;
			}
		}
	}
    
	for (int i = 0; i < 8; i++) {
		int n_x = x + dx[i];
		int n_y = y + dy[i];

		if (is_in(n_x, n_y) && !visited[n_x][n_y] && t->child[Map[n_x][n_y] - 'A']) {
			visited[n_x][n_y] = true;
			dfs(t->child[Map[n_x][n_y] - 'A'], n_x, n_y, word + Map[n_x][n_y]);
			visited[n_x][n_y] = false;
		}
	}
}

void set_boggle() {
	boggle.cnt = 0;
	boggle.score = 0;
	boggle.word = "";
	boggle.m.clear();
}

void go_boggle() {
	set_boggle();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (root->child[Map[i][j] - 'A']) {
				string word(1, Map[i][j]);
				visited[i][j] = true;
				dfs(root->child[Map[i][j] - 'A'], i, j, word);
				visited[i][j] = false;
			}
		}
	}
	
	cout << boggle.score << " " << boggle.word << " " << boggle.cnt << endl;
}

void solution() {
	int w, b;
	string word;

	init();

	cin >> w;
	for (int i = 0; i < w; i++) {
		cin >> word;
		set_trie(word);
	}

	cin >> b;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> word;
			for (int k = 0; k < 4; k++) {
				Map[j][k] = word[k];
			}
		}
		go_boggle();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solution();

	return 0;
}