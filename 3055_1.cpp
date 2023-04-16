//탈출
#include <iostream>
#include <queue>
#define MAX 55
using namespace std;
queue<pair<int, int> > q;
queue<pair<int, int> > p1;
pair<int, int> p2;
pair<int, int> p3;
int r, c, canmove[MAX][MAX], wave[MAX][MAX];
char arr[MAX][MAX];
bool visited[MAX][MAX];
bool inRange(int x, int y)
{
  return x >= 0 && x < r && y >= 0 && y < c;
}
bool canGo(int x, int y, bool isWave)
{
  if (!inRange(x, y))
    return false;
  if (isWave)
  {
    if (arr[x][y] == 'D')
      return false;
  }
  if (visited[x][y] == true || arr[x][y] == 'X')
    return false;
  return true;
}
void BFS(bool isWave)
{
  int dx[4] = {-1, 1, 0, 0};
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
      if (isWave)
      {
        if (canGo(nx, ny, true))
        {
          visited[nx][ny] = true;
          wave[nx][ny] = wave[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
      }
      else
      {
        if (canGo(nx, ny, false))
        {
          visited[nx][ny] = true;
          canmove[nx][ny] = canmove[x][y] + 1;
          //wave[nx][ny] != 0-> 물이 돌로 막혀 있어서 s에 닿을 수 없을 경우 패스
          if (canmove[nx][ny] >= wave[nx][ny] && wave[nx][ny] != 0)
            continue;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
}
void Solve()
{
  BFS(true);

  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      visited[i][j] = false;

  q.push(make_pair(p2.first, p2.second));
  visited[p2.first][p2.second] = true;
  BFS(false);
}
int main()
{
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%1s", &arr[i][j]);
      if (arr[i][j] == 'D')
        p3 = make_pair(i, j);
      if (arr[i][j] == 'S')
        p2 = make_pair(i, j);
      if (arr[i][j] == '*')
        q.push(make_pair(i, j));
    }
  }
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      visited[i][j] = false;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      wave[i][j] = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      canmove[i][j] = 0;
  Solve();

  if (canmove[p3.first][p3.second] == 0)
  {
    cout << "KAKTUS";
    return 0;
  }
  cout << canmove[p3.first][p3.second];
}