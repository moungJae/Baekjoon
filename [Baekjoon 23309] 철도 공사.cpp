#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

typedef struct Node {
	int x;
	Node* next;
	Node* prev;
} node;

int N, M;
Node* head = NULL;
Node n[1000001];

void input() {
	int x;
	Node* before = NULL;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (before == NULL) {
			n[x].x = x;
			n[x].prev = &n[x];
			n[x].next = &n[x];
			head = &n[x];
			before = &n[x];
		}
		else {
			n[x].x = x;
			n[x].prev = before;
			n[x].next = head;
			before->next = &n[x];
			head->prev = &n[x];
			before = &n[x];
		}
	}
}

void solution() {
	string op;
	int i, j;
	Node* cur, *before, *next;
	
	while (M--) {
		cin >> op;
		if (op == "BN") {
			cin >> i >> j;
			cur = &n[i];
			next = cur->next;
			n[j].x = j;
			n[j].prev = cur;
			n[j].next = next;
			cur->next = &n[j];
			next->prev = &n[j];

			cout << next->x << endl;
		}
		else if (op == "BP") {
			cin >> i >> j;
			cur = &n[i];
			before = cur->prev;
			n[j].x = j;
			n[j].prev = before;
			n[j].next = cur;
			before->next = &n[j];
			cur->prev = &n[j];

			cout << before->x << endl;
		}
		else if (op == "CN") {
			cin >> i;
			before = &n[i];
			cur = before->next;
			next = cur->next;

			before->next = next;
			next->prev = before;

			cout << cur->x << endl;
		}
		else if (op == "CP") {
			cin >> i;
			next = &n[i];
			cur = next->prev;
			before = cur->prev;
			before->next = next;
			next->prev = before;

			cout << cur->x << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}