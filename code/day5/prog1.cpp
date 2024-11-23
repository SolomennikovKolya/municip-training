#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

int m, n, h, k;

bool chech(multiset<pair<int, int>> &b)
{
	if (b.size() < n)
		return false;

	auto first_iter = b.begin();
	auto last_iter = b.begin();
	while (true)
	{
		last_iter++;
		if (last_iter == b.end())
		{
			last_iter--;
			break;
		}
		if (last_iter->first - first_iter->first > k)
		{
			last_iter--;
			break;
		}
	}

	if (distance(last_iter, first_iter) + 1 >= n)
		return true;

	for (int i = 1; i < b.size(); ++i)
	{
		first_iter++;
		while (true)
		{
			last_iter++;
			if (last_iter == b.end())
			{
				last_iter--;
				break;
			}
			if (last_iter->first - first_iter->first > k)
			{
				last_iter--;
				break;
			}
		}
		if (distance(last_iter, first_iter) + 1 >= n)
			return true;
	}

	return false;
}

int main()
{
	cin >> m >> n >> h >> k;
	vector<pair<int, int>> a; // (высота; кол-во иголок)

	for (int i = 0; i < m; i++)
	{
		int height, num;
		cin >> height >> num;
		a.push_back(make_pair(height, num));
	}
	sort(a.begin(), a.end());

	multiset<pair<int, int>> b; // (кол-во иголок; высота)
	b.insert(make_pair(a[0].second, a[0].first));

	int secondH = 0;
	for (int i = 0; i < m; ++i)
	{
		if (a[i].first - a[0].first > h)
			break;
		else
		{
			secondH++;
			b.insert(make_pair(a[secondH].second, a[secondH].first));
		}
	}

	if (chech(b))
	{
		cout << "YES\n";
		return 0;
	}

	for (int firstH = 1; firstH < m; ++firstH)
	{
		b.erase(b.begin());

		for (int i = firstH; i < m; ++i)
		{
			if (a[i].first - a[firstH].first > h)
				break;
			else
			{
				secondH++;
				b.insert(make_pair(a[i].second, a[i].first));
			}
		}

		if (chech(b))
		{
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

/*
10 5 30 2100
241 23413
300 32415
239 23200
191 32399
272 32688
288 31002
150 26590
237 26234
299 32900
286 33081
*/