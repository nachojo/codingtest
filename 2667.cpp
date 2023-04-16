//단지번호 붙이기
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 26
using namespace std;
int n, arr[MAX_N][MAX_N], visited[MAX_N][MAX_N], *complex, order = 0;
bool inRange(int x, int y);
bool canGo(int x, int y);
void BFS(void);
int find_Complex(void);
void sort_Complex(void);
void Swap(int arr[], int &x, int &y);
queue<pair<int, int> > q;
int main()
{
  cin >> n;
  complex = new int[MAX_N * MAX_N / 2 + 1];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      scanf("%1d", &arr[i][j]);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      visited[i][j] = false;
  }

  cout << find_Complex() << endl;
  // sort(complex, complex + order);
  sort_Complex();
  for (int i = 0; i < order; i++)
    cout << complex[i] << endl;
}
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < n;
}

bool canGo(int x, int y)
{
  if (!inRange(x, y))
    return false;
  if (visited[x][y] == true || arr[x][y] == 0)
    return false;
  return true;
}

void BFS()
{
  int cnt = 0;
  while (!q.empty())
  {
    cnt++;
    int curr_x = q.front().first;
    int curr_y = q.front().second;
    q.pop();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++)
    {
      int nx = curr_x + dx[i];
      int ny = curr_y + dy[i];
      if (canGo(nx, ny))
      {
        q.push(make_pair(nx, ny));
        visited[nx][ny] = true;
      }
    }
  }
  complex[order] = cnt;
  order++;
}

int find_Complex()
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (canGo(i, j))
      {
        q.push(make_pair(i, j));
        visited[i][j] = true;
        BFS();
        cnt++;
      }
    }
  }
  return cnt;
}

void sort_Complex()
{
  for (int i = 0; i < order - 1; i++)
  {
    for (int j = i + 1; j < order; j++)
      if (complex[i] > complex[j])
        Swap(complex, i, j);
  }
}

void Swap(int arr[], int &x, int &y)
{
  int temp = 0;
  temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}
