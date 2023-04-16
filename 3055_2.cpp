//탈출 BFS 라운드
#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
queue<pair<int, int> > q;
queue<pair<int, int> > hed;
pair<int, int> p;
int r, c;
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
int BFS()
{
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int cnt = 0;
  while (!q.empty() || !hed.empty())
  {
    cnt++;
    //물, 고슴도치가 한 턴씩 이동
    int _size_q = q.size();
    for (int j = 0; j < _size_q; j++)
    {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (canGo(nx, ny, true))
        {
          visited[nx][ny] = true;
          q.push(make_pair(nx, ny));
        }
      }
    }
    bool flag = false;
    int _size = hed.size();
    for (int j = 0; j < _size; j++)
    {
      int x = hed.front().first;
      int y = hed.front().second;
      hed.pop();
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];
        //종료조건 1. 고슴도치가 굴을 찾았을 때
        if (arr[nx][ny] == 'D')
          return cnt;
        if (canGo(nx, ny, false))
        {
          flag = true;
          visited[nx][ny] = true;
          hed.push(make_pair(nx, ny));
        }
      }
    }
  }
  return -1;
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
        p = make_pair(i, j);
      if (arr[i][j] == 'S') //고슴도치
        hed.push(make_pair(i, j));
      if (arr[i][j] == '*') //물
        q.push(make_pair(i, j));
    }
  }
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      visited[i][j] = false;
  visited[hed.front().first][hed.front().second] = true;
  int ans = BFS();
  if (ans == -1)
  {
    cout << "KAKTUS";
    return 0;
  }
  else
    cout << ans;
}
