//스타트 택시
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define MAX 20
#define MAX_M 400
using namespace std;
int n, m, arr[MAX][MAX], temp[MAX][MAX];
bool visited[MAX][MAX], del[MAX_M];
queue<pair<int, int> > q;
vector<int> v[MAX_M];
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < n;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (visited[x][y] == true || arr[x][y] == 1)
    return false;
  return true;
}
bool canMove(int _fuel, int _dist)
{
  _fuel -= _dist;
  if (_fuel < 0)
    return false;
  return true;
}

void BFS()
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
      if (canGo(nx, ny))
      {
        visited[nx][ny] = true;
        temp[nx][ny] = temp[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}
int Simulation(int _fuel)
{
  for (int t = 0; t < m; t++)
  {
    //승객찾기
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        temp[i][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        visited[i][j] = false;
    visited[q.front().first][q.front().second] = true;
    BFS();
    //벽으로 막혀있어 승객에게 갈 수 없으면 종료
    for (int i = 0; i < m; i++)
    {
      if (visited[v[i][0]][v[i][1]] == false)
        return -1;
    }
    int dist = INT_MAX, point;
    //가장 가까운 거리 고르기
    for (int i = 0; i < m; i++)
      if (del[i] == false)
        dist = min(temp[v[i][0]][v[i][1]], dist);

    bool flag = true;
    //가까운 거리를 dist에 저장하고 해당 거리의 승객 좌표를 큐에 저장
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        for (int k = 0; k < m; k++)
        {
          //del[k] == false -> 이미 태운 승객 제외
          if (temp[i][j] == dist && v[k][0] == i && v[k][1] == j && del[k] == false)
          {
            q.push(make_pair(i, j));
            point = k;
            flag = false;
            //행, 열 우선순위이므로 처음 승객을 찾으면 반복문 종료
            break;
          }
        }
        if (flag == false)
          break;
      }
      if (flag == false)
        break;
    }

    if (!canMove(_fuel, dist))
      return -1;
    _fuel -= dist;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        temp[i][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        visited[i][j] = false;
    visited[q.front().first][q.front().second] = true;
    BFS();
    for (int i = 0; i < m; i++)
    {
      if (visited[v[i][2]][v[i][3]] == false)
        return -1;
    }
    dist = temp[v[point][2]][v[point][3]];
    if (!canMove(_fuel, dist))
      return -1;
    _fuel -= dist;
    _fuel += dist * 2;
    q.push(make_pair(v[point][2], v[point][3]));
    del[point] = true;
  }
  return _fuel;
}
int main()
{
  int fuel;
  cin >> n >> m >> fuel;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  int x, y;
  cin >> x >> y;
  q.push(make_pair(x - 1, y - 1));

  int start, end;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y >> start >> end;
    v[i].push_back(x - 1);
    v[i].push_back(y - 1);
    v[i].push_back(start - 1);
    v[i].push_back(end - 1);
  }

  for (int i = 0; i < m; i++)
    del[i] = false;

  cout << Simulation(fuel);
}