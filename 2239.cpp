#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > v;
int arr[9][9] = {};
bool flag = false;
bool inRange(int x, int y)
{
  return x >= 0 && x < 9 && y >= 0 && y < 9;
}
bool isPossible(int x, int y, int val)
{
  for (int i = 0; i < 9; i++)
  {
    if (val == arr[x][i] || val == arr[i][y])
      return false;
  }
  for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
  {
    for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
    {
      if (val == arr[i][j])
        return false;
    }
  }
  return true;
}
void DFS(int next)
{
  if (flag == true)
    return;
  if (next == v.size())
  {
    if (flag == false)
    {
      for (int i = 0; i < 9; i++)
      {
        for (int j = 0; j < 9; j++)
        {
          cout << arr[i][j];
        }
        cout << endl;
      }
      flag = true;
    }
    return;
  }
  for (int j = 1; j < 10; ++j)
  {
    if (isPossible(v[next].first, v[next].second, j))
    {
      arr[v[next].first][v[next].second] = j;
      DFS(++next);
    }
  }
}
int main()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (arr[i][j] == 0)
      {
        v.push_back(make_pair(i, j));
      }
    }
  }
  cout << " ---------------------- " << endl;
  DFS(0);
}
