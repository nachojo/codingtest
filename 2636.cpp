//치즈
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
queue<pair<int, int> > q;
queue<pair<int, int> > new_q;
queue<int> ans;
int n, m, cnt = 0, before = 0, arr[MAX][MAX];
bool visited[MAX][MAX];
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (visited[x][y] == true)
    return false;
  return true;
}
void BFS()
{
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};
  int cnt = 0;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (canGo(nx, ny) && arr[nx][ny] == 0)
      {
        visited[nx][ny] = true;
        q.push(make_pair(nx, ny));
        new_q.push(make_pair(nx, ny));
        //큐에 바깥공기 넣기
      }
    }
  }
}

void BFS2()
{ //치즈 녹이기
  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {1, -1, 0, 0};
  while (!new_q.empty())
  {
    int _size = new_q.size();
    for (int j = 0; j < _size; j++)
    {
      int x = new_q.front().first;
      int y = new_q.front().second;
      new_q.pop();
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canGo(nx, ny) && arr[nx][ny] == 1)
        {
          visited[nx][ny] = true;
          arr[nx][ny] = 0;
          new_q.push(make_pair(nx, ny));
        }
      }
    }
    cnt++;
    break;
  }
}
void Solve()
{
  while (true)
  {
    before = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (arr[i][j] == 1)
          before++;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        visited[i][j] = false;

    q.push(make_pair(0, 0));
    new_q.push(make_pair(0, 0));
    visited[0][0] = true;
    BFS();

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        visited[i][j] = false;

    for (int i = 0; i < new_q.size(); i++)
    {
      visited[new_q.front().first][new_q.front().second] = true;
      new_q.push(make_pair(new_q.front().first, new_q.front().second));
      new_q.pop();
    }

    BFS2();

    for (int i = 0; i < new_q.size(); i++)
      new_q.pop();

    bool flag = false;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (arr[i][j] == 1)
          flag = true;

    if (flag == false)
      break;
  }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  cout << cnt << '\n';
  cout << before;
}