#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int idx;

void set_Tree(int A[], int Tree[], int x, int N) {
	if (x < N) {
		set_Tree(A, Tree, 2 * x + 1, N);
		Tree[x] = A[idx++];
		set_Tree(A, Tree, 2 * x + 2, N);
	}
}

void show_Tree(int Tree[], int x, int gap, int N) {
	if (x < N) {
		for (int i = x; i < x + gap; i++) {
			printf("%d ", Tree[i]);
		}
		printf("\n");
		show_Tree(Tree, 2 * x + 1, 2 * gap, N);
	}
}

void solution() {
	int K, N;
	int A[1025], Tree[1025];

	scanf("%d", &K);
	N = pow(2, K) - 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	set_Tree(A, Tree, 0, N);
	show_Tree(Tree, 0, 1, N);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	solution();

	return 0;
}