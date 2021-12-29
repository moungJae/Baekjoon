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

using namespace std;

const int RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3;
vector<pair<int, int>> v;
bool Map[101][101];

pair<int, int> get_direct_vector(pair<int, int> center, pair<int, int> cur) {
	pair<int, int> ret;
	ret.first = cur.first - center.first;
	ret.second = cur.second - center.second;
	return ret;
}

pair<int, int> rotate_90(pair<int, int> direct_vector) {
	pair<int, int> ret;
	ret.first = -direct_vector.second;
	ret.second = direct_vector.first;
	return ret;
}

pair<int, int> get_point(pair<int, int> center, pair<int, int> direct_vector) {
	pair<int, int> ret;
	ret.first = center.first + direct_vector.first;
	ret.second = center.second + direct_vector.second;
	return ret;
}

void make_generation(int x,int y, int d, int g) {
	int v_size;
	pair<int, int> center;

	// 0세대 드래곤 커브를 형성
	switch (d) {
	case UP: v.push_back({ x, y - 1 }); break;
	case DOWN: v.push_back({ x, y + 1 }); break;
	case RIGHT: v.push_back({ x + 1, y }); break;
	case LEFT: v.push_back({ x - 1, y });
	}

	// g세대 드래곤 커브를 형성
	while (g) {
		v_size = v.size();
		center.first = v[v_size - 1].first, center.second = v[v_size - 1].second;
		pair<int, int> direct_vector, new_point;
		for (int i = v_size - 2; i >= 0; i--) {
			direct_vector = get_direct_vector(center, v[i]);
			direct_vector = rotate_90(direct_vector);
			new_point = get_point(center, direct_vector);
			v.push_back(new_point);
		}
		g--;
	}

	// g세대 드래곤 커브의 모든 점들을 100x100 격자 위에 표시
	for (int i = 0; i < v.size(); i++) {
		Map[v[i].first][v[i].second] = true;
	}
}

void input() {
	int x, y, d, g;
	cin >> x >> y >> d >> g;
	
	v.clear();
	v.push_back({ x, y });
	Map[x][y] = true;
	
	make_generation(x, y, d, g);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, cnt;
	
	cin >> n;
	while (n--) input();

	cnt = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (Map[i][j] && Map[i][j + 1] && Map[i + 1][j] && Map[i + 1][j + 1])
				cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}