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
#include <list>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, d, k, c;
int bob[3000001];
int mark[3001];

void input() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
		cin >> bob[i];
}

void solution() {
	int left = 0, right = 0;
	int cnt = 0, result = 0;

	do {
		if (right - left != k) {
			if (!mark[bob[right % N]]) 
				cnt++;
			mark[bob[right % N]]++;
			right++;
		}
		else {
			if (mark[bob[left]] == 1)
				cnt--;
			mark[bob[left]]--;
			left++;
			if (!mark[bob[right % N]])
				cnt++;
			mark[bob[right % N]]++;
			right++;
		}
		if (right - left == k) {
			result = max(result, !mark[c] ? cnt + 1 : cnt);
		}
	} while (left < N);
	
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}