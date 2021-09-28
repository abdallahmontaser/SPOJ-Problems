#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dx[] = { 0, 0,1,-1, -1,-1,1, 1 };
int dy[] = { 1,-1,0, 0 ,-1, 1,1,-1 };
int N, M, to_x, to_y;
vector<string>ve(N);
vector<vi>len;
bool vaild(int i, int j)
{
	if (i >= 0 && j >= 0 && i < N && j < M && len[i][j] == -1)
		return true;
	return false;
}
void solve()
{
	cin >> N >> M;
	ve = vector<string>(N);
	len = vector<vi>(N, vi(M, -1));
	pair<int, int>tem;
	queue<pair<int, int>>qe;
	for (int i = 0; i < N; i++)
	{
		cin >> ve[i];
		for (int j = 0; j < M; j++)
		{
			if (ve[i][j] == '1')
				len[i][j] = 0, qe.push({ i,j });
		}
	}
	while (!qe.empty())
	{
		tem = qe.front(), qe.pop();
		for (int i = 0; i < 4; i++)
		{
			to_x = tem.first + dx[i];
			to_y = tem.second + dy[i];
			if (vaild(to_x, to_y))
				len[to_x][to_y] = len[tem.first][tem.second] + 1, qe.push({ to_x,to_y });
		}
	}
	for (auto& it : len)
	{
		for (auto & it2:it)
			cout << it2 << " ";
		cout << "\n";
	}
}
int main()
{
	int T; cin >> T;
	while (T--)
		solve();
}
