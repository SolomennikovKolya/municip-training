#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef struct
{
	int x, y;
} coord;

coord start, end;

int dfs(vector<vector<bool>> a, coord cur_pos, int cur_dir, int n, int m, set<coord> visited)
{
	if (cur_pos.x == start.x && cur_pos.y == start.y)
		return 0;

	visited.insert(cur_pos);
	coord next_coord{cur_pos.x + 1, cur_pos.y};

	if (cur_x < m && a[cur_y][cur_x + 1] == false && visited.find(next_coord) != visited.end())
	{
		if (cur_dir == 0)
			return dfs(a, cur_x + 1, cur_y, 3, n, m) + 2;
		else if (cur_dir == 1)
			return dfs(a, cur_x + 1, cur_y, 3, n, m) + 3;
		else if (cur_dir == 2)
			return dfs(a, cur_x + 1, cur_y, 3, n, m) + 2;
		else if (cur_dir == 3)
			return dfs(a, cur_x + 1, cur_y, 3, n, m) + 1;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> a(n, vector<bool>(m, false));
	for (int y = 0; y < n; ++y)
	{
		string line;
		getline(cin, line);

		for (int x = 0; x < m; ++x)
		{
			char c = line[x];
			if (c == '#')
			{
				a[y][x] = true;
			}
			else if (c == '.')
			{
				a[y][x] = false;
			}
			else if (c == 'S')
			{
				a[y][x] = false;
				start.x = x;
				start.y = y;
			}
			else if (c == 'T')
			{
				a[y][x] = false;
				end.x = x;
				end.y = y;
			}
		}
	}

	// int time = dfs()

	return 0;
}