//안전영역
#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
int n, arr[MAX][MAX], visited[MAX][MAX];
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < n;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (visited[x][y] == true)
    return false;
  return true;
}
void DFS(int x, int y, int h)
{
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (canGo(nx, ny) && arr[nx][ny] > h)
    {
      visited[nx][ny] = true;
      DFS(nx, ny, h);
    }
  }
}
int count()
{
  int max_h = 0, max_cnt = 0, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      max_h = max(arr[i][j], max_h);
    }
  }
  for (int k = 0; k < max_h; k++)
  {
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        visited[i][j] = false;
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (arr[i][j] > k && visited[i][j] == false)
        {
          visited[i][j] = true;
          DFS(i, j, k);
          cnt++;
        }
      }
    }
    max_cnt = max(cnt, max_cnt);
  }
  return max_cnt;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  cout << count() << endl;
}
