// 2022 - N1

#include <iostream>
#include <string>

using namespace std;

const int LETTERS_NUM = 26;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;

	int letters1[LETTERS_NUM];
	for (int i = 0; i < LETTERS_NUM; ++i)
	{
		letters1[i] = 0;
	}
	for (char c : s1)
	{
		letters1[c - 'a']++;
	}

	int letters2[LETTERS_NUM];
	for (int i = 0; i < LETTERS_NUM; ++i)
	{
		letters2[i] = 0;
	}
	for (char c : s2)
	{
		letters2[c - 'a']++;
	}

	int dif = 0;
	int dif_id = 0;
	for (int i = 0; i < LETTERS_NUM; ++i)
	{
		if (letters1[i] != letters2[i])
		{
			const int delta = letters1[i] - letters2[i];
			if (abs(delta) != 1)
			{
				cout << "NO\n";
				return 0;
			}
			dif++;
			dif_id = i;
		}
	}

	if (dif == 0)
	{
		cout << "YES\n";
		cout << "0";
	}
	else if (dif > 1)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		if (s1.length() > s2.length())
		{
			cout << "-\n";
		}
		else
		{
			cout << "+\n";
		}
		cout << char('a' + dif_id) << "\n";
	}

	return 0;
}