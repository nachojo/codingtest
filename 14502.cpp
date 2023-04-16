//연구소
#include <iostream>
#include <algorithm>
using namespace std;
int **arr, n, m;
bool inRange(int x, int y);
bool canGo(int **_temp, bool **_visited, int _x, int _y);
int Combination();
int search(int **temp, bool **visite);
void DFS(int **temp, bool **visited, int x, int y);
int *Arr_1D();
int **Arr_2D(int *_arr);
bool **Arr_Visited();
int main()
{
  cin >> n >> m;
  //초기화
  arr = new int *[n];
  for (int i = 0; i < n; i++)
    arr[i] = new int[m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  cout << Combination() << endl;
  //해제
  for (int i = 0; i < n; i++)
    delete arr[i];
  delete[] arr;
}
bool inRange(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}
// bool canGo(int **_temp, int **_visited, int _x, int _y)
// {
//   if (!inRange(_x, _y))
//     return false;
//   if (_visited[_x][_y] == true || _temp[_x][_y] != 0)
//     return false;
//   return true;
// }
int *Arr_1D()
{
  int *_temp = new int[n * m];
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      _temp[cnt] = arr[i][j];
      cnt++;
    }
  }
  return _temp;
}
int **Arr_2D(int *_arr)
{
  int **_temp = new int *[n];
  for (int i = 0; i < n; i++)
    _temp[i] = new int[m];
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      _temp[i][j] = _arr[cnt];
      cnt++;
    }
  }
  return _temp;
}
bool **Arr_Visited()
{
  bool **_visited = new bool *[n];
  for (int i = 0; i < n; i++)
    _visited[i] = new bool[m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      _visited[i][j] = false;
  return _visited;
}
int Combination()
{
  int *temp1 = nullptr, **temp2 = nullptr, max_ans = 0;
  bool **visited = nullptr;
  for (int i = 0; i < n * m - 2; i++)
  {
    for (int j = i + 1; j < n * m - 1; j++)
    {
      for (int k = j + 1; k < n * m; k++)
      {
        //1차원 배열에 복사
        temp1 = Arr_1D();
        if ((temp1[i] == 0 && temp1[j] == 0 && temp1[k] == 0))
        {
          //1차원 배열에 조합 값 넣어주고 다시 2차원 배열 복사
          temp1[i] = 1;
          temp1[j] = 1;
          temp1[k] = 1;
          temp2 = Arr_2D(temp1);
          visited = Arr_Visited();
          max_ans = max(search(temp2, visited), max_ans);
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    delete visited[i];
  delete[] visited;
  for (int i = 0; i < n; i++)
    delete temp2[i];
  delete[] temp2;
  delete[] temp1;

  return max_ans;
};
int search(int **temp, bool **visited)
{
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (temp[i][j] == 2 && visited[i][j] == false)
      {
        visited[i][j] = true;
        DFS(temp, visited, i, j);
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      if (temp[i][j] == 0)
        cnt++;
  }
  return cnt;
};
void DFS(int **temp, bool **visited, int x, int y)
{
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  for (int k = 0; k < 4; k++)
  {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (!inRange(nx, ny))
      continue;
    if (visited[nx][ny] || temp[nx][ny] != 0)
      continue;
    visited[nx][ny] = true;
    temp[nx][ny] = 2;
    DFS(temp, visited, nx, ny);
  }
}
