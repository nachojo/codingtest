//감시
#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;
int **arr, n, m;
bool inRange(int x, int y);
bool canGo(int x, int y);
void Temp(void);
int DFS(int x, int y, int nx, int ny, int cnt);
int max_cnt = 0;
int main()
{
  arr = new int *[MAX];
  for (int i = 0; i < MAX; i++)
    arr[i] = new int[MAX];

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  Temp();
  for (int i = 0; i < MAX; i++)
    delete arr[i];
  delete[] arr;
  arr = nullptr;
}

bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (arr[x][y] == 6)
    return false;
  return true;
}
void Temp(void)
{
  int max_dfs = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  for (int i = 0; i < 4; i++)
  {
    max_dfs = max(DFS(2, 2, dx[i], dy[i], 0), max_dfs);
  }
  cout << n * m - max_cnt;
}
int DFS(int x, int y, int nx, int ny, int cnt)
{
  max_cnt = max(cnt, max_cnt);
  if (canGo(x + nx, y + ny))
    DFS(x + nx, y + ny, nx, ny, cnt + 1);
}
