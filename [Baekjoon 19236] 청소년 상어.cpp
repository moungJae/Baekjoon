#include <iostream>

using namespace std;

bool is_in(int x, int y);
int dx[9] = { 0, -1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0, 0,-1,-1,-1,0,1,1,1 };

class Fish {
public:
	bool live;
	int x, y, direction;
	Fish() {}
	Fish(int x, int y, int direction, bool live) {
		this->x = x;
		this->y = y;
		this->direction = direction;
		this->live = live;
	}

	bool check_go(int shark_x, int shark_y) {
		int fish_x = x, fish_y = y;
		int fish_direction = direction;

		fish_x += dx[fish_direction];
		fish_y += dy[fish_direction];
		return (is_in(fish_x, fish_y) && !(fish_x == shark_x && fish_y == shark_y));
	}

	void rotate() {
		direction += 1;
		if (direction == 9)
			direction = 1;
	}

	void go() {
		x += dx[direction];
		y += dy[direction];
	}
};

int info[4][4];
Fish fish[17];

const int BLANK = 0, SHARK = 100;

void input()
{
	int number, direction;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> number >> direction;
			info[i][j] = number;
			fish[number].x = i, fish[number].y = j;
			fish[number].direction = direction, fish[number].live = true;
		}
	}
}

int max(int x, int y)
{
	return (x > y ? x : y);
}

bool is_in(int x, int y) 
{
	return (x >= 0 && x <= 3 && y >= 0 && y <= 3);
}

void shark_eat_fish(int die_fish, int shark_x, int shark_y)
{
	fish[die_fish].live = false;
	info[shark_x][shark_y] = SHARK;
}

void fish_rollback(int live_fish, int fish_x, int fish_y)
{
	fish[live_fish].live = true;
	info[fish_x][fish_y] = live_fish;
}

void copy(int dst1[][4], int src1[][4], Fish dst2[], Fish src2[])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			dst1[i][j] = src1[i][j];
	for (int i = 1; i <= 16; i++)
		dst2[i] = src2[i];
}

int dfs(int shark_x, int shark_y, int shark_direction)
{
	int ret = 0;
	int before_x, before_y, die_fish, next_fish;
	int tmp_info[4][4];
	Fish tmp_fish[17];

	for (int i = 1; i <= 16; i++) {
		if (fish[i].live) {
			before_x = fish[i].x, before_y = fish[i].y;
			while (!fish[i].check_go(shark_x, shark_y)) {
				fish[i].rotate();
			}
			fish[i].go();
			next_fish = info[fish[i].x][fish[i].y];
			swap(info[before_x][before_y], info[fish[i].x][fish[i].y]);
			fish[next_fish].x = before_x, fish[next_fish].y = before_y;
		}
	}

	info[shark_x][shark_y] = BLANK;
	while (is_in((shark_x = shark_x + dx[shark_direction]),
		(shark_y = shark_y + dy[shark_direction]))) {
		if (info[shark_x][shark_y]) {
			copy(tmp_info, info, tmp_fish, fish);
			die_fish = info[shark_x][shark_y];
			shark_eat_fish(die_fish, shark_x, shark_y);
			ret = max(ret, die_fish + dfs(shark_x, shark_y, fish[die_fish].direction));
			copy(info, tmp_info, fish, tmp_fish);
		}
	}

	return ret;
}

void solution()
{
	int die_fish = info[0][0];

	shark_eat_fish(die_fish, 0, 0);
	cout << die_fish + dfs(fish[die_fish].x, fish[die_fish].y, fish[die_fish].direction);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	input();
	solution();

	return 0;
}
