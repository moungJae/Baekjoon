#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <string>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int N;
int max_res;
string S;
bool order[11];

void input() {
	cin >> N;
	cin >> S;
}

int make_num(int left, char op, int right) {
	if (op == '+')
		return left + right;
	else if (op == '-')
		return left - right;
	else if (op == '*')
		return left * right;
}

string modification() {
	string sentence = "";
	int left, mid, right;
	int op_cnt = S.size() / 2;

	for (int i = 0; i < op_cnt; i++) {
		left = 2 * i;
		mid = 2 * i + 1;
		right = 2 * i + 2;
		if (order[i]) {
			sentence += to_string(make_num(
				stoi(&S[left]), 
				S[mid], 
				stoi(&S[right])
			));
		}
		else {
			if (!(i && order[i - 1]))
				sentence += S[left];
			sentence += S[mid];
			if (i == op_cnt - 1)
				sentence += S[right];
		}
	}
	
	return sentence;
}

int get_result(string sentence) {
	deque<int> number_queue;
	deque<char> operator_queue;
	int idx;
	bool op_flag = true;

	idx = 0;
	while (sentence[idx]) {
		if ((sentence[idx] >= '0' && sentence[idx] <= '9') || op_flag) {
			number_queue.push_back(stoi(&sentence[idx]));
			if (op_flag && !(sentence[idx] >= '0' && sentence[idx] <= '9'))
				idx++;
			while (sentence[idx] >= '0' && sentence[idx] <= '9')
				idx++;
			op_flag = false;
		}
		else {
			operator_queue.push_back(sentence[idx]);
			idx++;
			op_flag = true;
		}
	}

	while (!operator_queue.empty()) {
		int num1 = number_queue.front();
		number_queue.pop_front();
		int num2 = number_queue.front();
		number_queue.pop_front();
		char op = operator_queue.front();
		operator_queue.pop_front();

		number_queue.push_front(make_num(num1, op, num2));
	}

	return number_queue.front();
}

void dfs(int idx) {
	if (idx == (S.size() / 2)) {
		string sentence = modification();
		max_res = max(max_res, get_result(sentence));
		return;
	}

	if (idx == 0) {
		order[idx] = true;
		dfs(idx + 1);
		order[idx] = false;
		dfs(idx + 1);
	}
	else {
		if (order[idx - 1]) {
			order[idx] = false;
			dfs(idx + 1);
		}
		else {
			order[idx] = true;
			dfs(idx + 1);
			order[idx] = false;
			dfs(idx + 1);
		}
	}
}

void solution() {
	if (N == 1) {
		cout << S;
		return;
	}
	max_res = (1 << 31);
	dfs(0);
	cout << max_res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}