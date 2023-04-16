#include <iostream>
#include <vector>
#define MAX 16
using namespace std;
vector<pair<int, int> > v[3];
int cnt = 0, n = 0;
int **arr;
bool inRange(int x, int y);
bool canGo(int x, int y);
void DFS(int x, int y, int Dir);

int main()
{
  arr = new int *[MAX];
  for (int i = 0; i < MAX; i++)
  {
    arr[i] = new int[MAX];
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }

  v[0].push_back(make_pair(1, 1));
  v[0].push_back(make_pair(0, 1));
  v[0].push_back(make_pair(1, 0));

  v[1].push_back(make_pair(1, 1));
  v[1].push_back(make_pair(0, 1));

  v[2].push_back(make_pair(1, 1));
  v[2].push_back(make_pair(1, 0));

  DFS(0, 1, 1);
  cout << cnt << endl;

  for (int i = 0; i < MAX; i++)
  {
    delete arr[i];
  }
  delete[] arr;
}
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < n;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (arr[x][y] == 1)
    return false;
  return true;
}
void DFS(int x, int y, int Dir)
{
  if (x == n - 1 && y == n - 1)
    cnt++;
  for (int i = 0; i < v[Dir].size(); i++)
  {
    int nx = x + v[Dir][i].first;
    int ny = y + v[Dir][i].second;
    if (i == 0)
    {
      if (!canGo(x, y + 1) || !canGo(x + 1, y))
        continue;
    }
    if (canGo(nx, ny))
    {
      if (Dir == 2 && i == 1)
      {
        ++i;
      }
      DFS(nx, ny, i);
    }
  }
}