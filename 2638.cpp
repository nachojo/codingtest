//치즈
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
queue<pair<int, int> > q;
int n, m, arr[MAX][MAX], temp[MAX][MAX];
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (temp[x][y] == 3)
    return false;
  return true;
}
void BFS()
{
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (canGo(nx, ny))
      {
        if (arr[nx][ny] == 1)
        {
          temp[nx][ny] = 2;
          continue;
        }
        temp[nx][ny] = 3;
        q.push(make_pair(nx, ny));
      }
    }
  }
}
bool Count(int x, int y)
{
  int cnt = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (temp[nx][ny] == 3)
      cnt++;
  }
  if (cnt >= 2)
    return true;
  else
    return false;
}
void Solve()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (temp[i][j] == 2 && Count(i, j))
      {
        temp[i][j] = 0;
        arr[i][j] = 0;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (temp[i][j] == 3)
        temp[i][j] = 0;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      temp[i][j] = 0;
  }

  int ans = 0;
  while (true)
  {
    bool flag = true;
    q.push(make_pair(0, 0));
    BFS();
    Solve();
    ans++;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        if (arr[i][j] != 0)
        {
          flag = false;
          break;
        }
      if (flag == false)
        break;
    }
    if (flag == true)
      break;
  }
  cout << ans;
}