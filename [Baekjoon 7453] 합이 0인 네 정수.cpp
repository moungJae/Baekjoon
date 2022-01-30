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

int N;
ll A[4001], B[4001], C[4001], D[4001];
vector<ll> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
}

void solution() {
	ll count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v.push_back(A[i] + B[j]);
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ll x = -(C[i] + D[j]);
			count += upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);
		}
	}
	
	cout << count;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}