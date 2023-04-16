#include <iostream>
#include <vector>
#include <cstdlib>
#define MAX 101
using namespace std;
int w, h;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int temp = MAX * MAX;
vector<pair<int, int> > v;
vector<pair<int, int> > v2;
bool inRange(int x, int y);
bool canGo(int x, int y);
void Solve2(int x, int y);
int c = 0;
int main()
{
  cin >> w >> h;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> arr[i][j];
      if (arr[i][j] == 'C')
        v.push_back(make_pair(i, j));
    }
  }

  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      visited[i][j] = false;
  visited[v[0].first][v[0].second] = true;
  v2.push_back(make_pair(v[0].first, v[0].second));
  Solve2(v[0].first, v[0].second);
  cout << temp << endl;
  cout << c;
}
bool inRange(int x, int y)
{
  return x >= 0 && x < h && y >= 0 && y < w;
}
bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (arr[x][y] == '*' || visited[x][y] == true)
    return false;
  return true;
}
void Solve2(int x, int y)
{
  if (x == v[1].first && y == v[1].second)
  {
    c++;
    int cnt = 0;
    for (int i = 2; i < v2.size(); i++)
    {
      if (abs(v2[i].first - v2[i - 2].first) == 1 && abs(v2[i].second - v2[i - 2].second) == 1)
        cnt++;
    }
    temp = min(cnt, temp);
    return;
  }
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {-1, 0, 1, 0};
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!canGo(nx, ny))
      continue;
    visited[nx][ny] = true;
    v2.push_back(make_pair(nx, ny));
    Solve2(nx, ny);
    v2.pop_back();
    visited[nx][ny] = false;
  }
}