#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Trie {
public:
    Trie* childs[26];
    int child_cnt;
    bool isRoot, finish;

    Trie(bool isroot) {
        for (int i = 0; i < 26; i++) 
            childs[i] = NULL;
        finish = false;
        isRoot = isroot;
        child_cnt = 0;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            if (childs[i] != NULL) 
                delete childs[i];
    }

    void insert(const char* cur) {
        if (*cur == '\0') {
            finish = true;
            return;
        }

        if (childs[*cur - 'a'] == NULL) {
            childs[*cur - 'a'] = new Trie(false);
            child_cnt++;
        }

        childs[*cur - 'a']->insert(cur + 1);
    }

    void find(const char* cur, int &answer) {
        if (*cur == '\0') return;

        if (isRoot) answer++;
        else {
            if (child_cnt > 1) answer++;
            else if (finish) answer++;
        }

        childs[*cur - 'a']->find(cur + 1, answer);
    }
};

int n;
vector<string> dict;

void init() {
    string input;

    dict.clear();
    for (int i = 0; i < n; i++) {
        cin >> input;
        dict.push_back(input);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while (cin >> n) {
        init();
        Trie root = Trie(true);
        for (int i = 0; i < dict.size(); i++) 
            root.insert(dict[i].c_str());

        int total = 0, answer;
        for (int i = 0; i < dict.size(); i++) {
            answer = 0;
            root.find(dict[i].c_str(), answer);
            total += answer;
        }

        double res = (double)total / (double)n;
        printf("%.2f\n", res);
    }

    return 0;
}
