#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		a[v1 - 1].push_back(v2 - 1);
		a[v2 - 1].push_back(v1 - 1);
	}

	int s;
	cin >> s;

	vector<int> shamans(s);
	for (int i = 0; i < s; ++i)
	{
		int x;
		cin >> x;
		shamans[i] = x - 1;
	}

	vector<int> ver_to_compoent(n);
	vector<bool> visited(n);
	queue<int> cur_vers;
	int component = 0;

	for (int start_v = 0; start_v < n; ++start_v)
	{
		if (visited[start_v])
			continue;

		cur_vers.push(start_v);
		visited[start_v] = true;

		while (cur_vers.size() > 0)
		{
			int v = cur_vers.front();
			ver_to_compoent[v] = component;
			for (int i : a[v])
			{
				if (visited[i] == false)
				{
					cur_vers.push(i);
					visited[i] = true;
				}
			}
			cur_vers.pop();
		}

		component++;
	}

	for (int i : ver_to_compoent)
	{
		cout << i << " ";
	}
	cout << "\n";

	if (shamans.size() == 0)
	{
		cout << "YES\n";
		return 0;
	}

	int compoment1 = ver_to_compoent[shamans[0]];
	for (int i = 1; i < s; ++i)
	{
		if (ver_to_compoent[shamans[i]] != compoment1)
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}