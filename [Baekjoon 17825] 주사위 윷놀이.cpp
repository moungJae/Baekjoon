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

int order[11];
int visited[3][41];
int general_path[41];
int special_path[41];
int special_num[41];
int ans;
const int START = 0, END = 100;
const int GENERAL = 1, SPECIAL = 2;

typedef struct Dice {
	int user[4];
	int path[4];
	int turn;
} Dice;

void input() {
	for (int i = 1; i <= 10; i++)
		cin >> order[i];
}

void set_path() {
	for (int i = 0; i < 40; i += 2) {
		general_path[i] = i + 2;
	}
	special_path[10] = 13, special_path[13] = 15;
	special_path[15] = 17, special_path[17] = 21;
	special_num[10] = 10, special_num[13] = 13;
	special_num[15] = 16, special_num[17] = 19;

	special_path[30] = 29, special_path[29] = 27;
	special_path[27] = 25, special_path[25] = 21;
	special_num[30] = 30, special_num[29] = 28;
	special_num[27] = 27, special_num[25] = 26;
	special_num[21] = 25;

	special_path[20] = 19, special_path[19] = 23, special_path[23] = 21;
	special_path[21] = 31, special_path[31] = 35, special_path[35] = 40;
	special_num[20] = 20, special_num[19] = 22, special_num[23] = 24;
	special_num[31] = 30, special_num[35] = 35, special_num[40] = 40;

	general_path[40] = special_path[40] = END;
}

void move_dice(Dice& dice, int i, int move_cnt) {
	if (dice.path[i] == SPECIAL) {
		while (move_cnt--) {
			dice.user[i] = special_path[dice.user[i]];
			if (dice.user[i] == END)
				break;
		}
	}
	else {
		while (move_cnt--) {
			dice.user[i] = general_path[dice.user[i]];
			if (dice.user[i] == END)
				break;
		}
	}
}

int get_visited(Dice dice, int i) {
	if (dice.user[i] == END)
		return 0;
	if (dice.user[i] == 10 || dice.user[i] == 20
		|| dice.user[i] == 30 || dice.user[i] == 40) {
		return visited[GENERAL][dice.user[i]] + visited[SPECIAL][dice.user[i]];
	}
	return visited[dice.path[i]][dice.user[i]];
}

void dfs(int idx, int sum, Dice dice) {
	if (idx > 10) {
		ans = max(ans, sum);
		return;
	}

	Dice next_dice;

	if (dice.turn == -1) {
		for (int i = 0; i < 4; i++) {
			next_dice = dice;
			next_dice.turn = i;
			move_dice(next_dice, i, order[idx]);
			if (next_dice.user[i] == 10)
				next_dice.path[i] = SPECIAL;
			visited[next_dice.path[i]][next_dice.user[i]]++;
			if (visited[next_dice.path[i]][next_dice.user[i]] == 1)
				dfs(idx + 1, sum + next_dice.user[i], next_dice);
			else
				dfs(idx + 1, sum, next_dice);
			visited[next_dice.path[i]][next_dice.user[i]]--;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (i != dice.turn && get_visited(dice, i) > 1)
				return;
		}
		for (int i = 0; i < 4; i++) {
			if (dice.user[i] == END)
				continue;
			next_dice = dice;
			next_dice.turn = i;
			move_dice(next_dice, i, order[idx]);

			if (next_dice.path[i] == GENERAL && (next_dice.user[i] == 10
				|| next_dice.user[i] == 20 || next_dice.user[i] == 30))
				next_dice.path[i] = SPECIAL;

			visited[dice.path[i]][dice.user[i]]--;
			visited[next_dice.path[i]][next_dice.user[i]]++;

			if (get_visited(next_dice, i) == 1 && next_dice.user[i] != END) {
				int next_sum = sum;

				if (next_dice.path[i] == SPECIAL)
					next_sum += special_num[next_dice.user[i]];
				else
					next_sum += next_dice.user[i];

				dfs(idx + 1, next_sum, next_dice);
			}
			else
				dfs(idx + 1, sum , next_dice);
			
			visited[next_dice.path[i]][next_dice.user[i]]--;
			visited[dice.path[i]][dice.user[i]]++;
		}
	}
}

void solution(){
	Dice dice;

	set_path();
	for (int i = 0; i < 4; i++) {
		dice.user[i] = START;
		dice.path[i] = GENERAL;
	}
	dice.turn = -1;
	dfs(1, 0, dice);

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}