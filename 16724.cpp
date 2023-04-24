//피리 부는 사나이
#include <iostream>
#define MAX 1000
using namespace std;
int n, m, num = 1;
int temp[MAX][MAX];
char map[MAX][MAX];
void DFS(int x, int y)
{
  int nx, ny;
  if (map[x][y] == 'R')
  {
    nx = x;
    ny = y + 1;
  }
  else if (map[x][y] == 'L')
  {
    nx = x;
    ny = y - 1;
  }
  else if (map[x][y] == 'U')
  {
    nx = x - 1;
    ny = y;
  }
  else
  {
    nx = x + 1;
    ny = y;
  }
  if (temp[nx][ny] == 0)
  {
    temp[nx][ny] = num;
    DFS(nx, ny);
    temp[x][y] = temp[nx][ny];
    return;
  }
  if (temp[nx][ny] == temp[x][y])
  {
    num++;
    return;
  }
  else if (temp[nx][ny] != temp[x][y])
  {
    temp[x][y] = temp[nx][ny];
    return;
  }
}
void Solve()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (temp[i][j] == 0)
      {
        temp[i][j] = num;
        DFS(i, j);
      }
    }
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%1s", &map[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      temp[i][j] = 0;
  Solve();
  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //     cout << temp[i][j] << " ";
  //   cout << endl;
  // }
  cout << num - 1;
}