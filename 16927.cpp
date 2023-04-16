// 배열돌리기2 
#include <iostream>
#include <cstdlib>
#define MAX_N 301
using namespace std;
int n, m, t;
bool inRange(int x, int y);
void Simulation(int arr[][MAX_N], bool visited[][MAX_N], int x, int y, int cnt);
int main()
{
  int arr[MAX_N][MAX_N];
  cin >> n >> m >> t;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  }
  bool visited[MAX_N][MAX_N];
  for (int a = 0; a < n; a++)
  {
    for (int b = 0; b < m; b++)
      visited[a][b] = false;

    int cnt, minus = 0;
    for (int j = 0; j < min(n, m) / 2; j++)
    {
      cnt = t % (2 * (n - minus) + 2 * (m - minus) - 4);
      cout << cnt << endl;
      Simulation(arr, visited, j, j, cnt);
      minus += 2;
    }
  }
  cout << " -------------- " << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}

void Simulation(int arr[][MAX_N], bool visited[][MAX_N], int x, int y, int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    int temp = arr[x][y];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int sx = x, sy = y;
    for (int dir = 0; dir < 4;)
    {
      int nx = sx + dx[dir];
      int ny = sy + dy[dir];
      if (nx == x && ny == y)
        break;
      if (!inRange(nx, ny) || nx >= n - x || ny >= m - y || nx < x - 1 || ny <= y - 1)
      {
        dir++;
        continue;
      }
      arr[sx][sy] = arr[nx][ny];
      sx = nx;
      sy = ny;
    }
    arr[x + 1][y] = temp;
  }
}
