#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define clr(x,val)           memset((x),(val),sizeof(x))
int dx[] = { 0, 0,1,-1, -1,-1,1, 1 };
int dy[] = { 1,-1,0, 0 ,-1, 1,1,-1 };
struct Key
{
	int X, Y, sta;
};
int N, M, to_x, to_y, x, y, state,tem, len[101][101][17];
char ch;
vector<string>ve;
queue<Key>qe;
map<char, int>key, door;
int getBit(int num, int idx)
{
	return (num >> idx) & 1;
}
int setBit1(int num, int idx)
{
	return  num | (1 << idx);
}
bool vaild(int i, int j)
{
	if (i < N && j < M && i >= 0 && j >= 0 && ve[i][j] != '#')
		return true;
	return false;
}
bool cheak(int i, int j, int d)
{
	if ((ve[i][j] != 'X' && isupper(ve[i][j]) && !(getBit(d,door[ch]))) || (len[i][j][d] != -1))
		return false;
	return true;
}
void BFS()
{
	while (!qe.empty())
	{
		x = qe.front().X;
		y = qe.front().Y;
		state = qe.front().sta;
		qe.pop();
		if (ve[x][y] == 'X')
		{
			cout << "Escape possible in " << len[x][y][state] << " steps.\n";
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			to_x = x + dx[i];
			to_y = y + dy[i];
			if (vaild(to_x, to_y))
			{
				tem = state;
				ch = ve[to_x][to_y];
				if (islower(ch))
					tem = setBit1(tem, key[ch]);
				if (cheak(to_x, to_y, tem))
					qe.push({ to_x,to_y,tem }), len[to_x][to_y][tem] = len[x][y][state] + 1;
			}
		}
	}
	cout << "The poor student is trapped!\n";
}
void solve()
{
	key['g'] = 0;  door['G'] = 0;
	key['b'] = 1;  door['B'] = 1;
	key['y'] = 2;  door['Y'] = 2;
	key['r'] = 3;  door['R'] = 3;
	while (cin >> N >> M)
	{
		if (!N && !M)
			break;
		ve = vector<string>(N);
		clr(len, -1);
		for (auto& it : ve)
			cin >> it;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (ve[i][j] == '*')
					qe.push({ i,j,0 }), len[i][j][0] = 0;
		BFS();
		while (!qe.empty())
			qe.pop();
	}
}
int main()
{
	solve();
}
