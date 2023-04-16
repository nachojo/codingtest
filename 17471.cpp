//게리맨더링
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#define MAX 10
using namespace std;
vector<int> v[MAX + 1];
int N, nums[MAX], min_ans = INT_MAX;
bool area[MAX], visited[MAX];
void DFS(int vertex)
{
  for (int i = 0; i < v[vertex].size(); i++)
  {
    int nv = v[vertex][i];
    if (!visited[nv - 1] && area[vertex - 1] == area[nv - 1])
    { //다음지역을 방문하지 않았고, 현재 지역과 다음 지역(인접한 지역)이 같은 구역이라면 간다
      visited[nv - 1] = true;
      DFS(nv);
    }
  }
}
int Solve()
{
  for (int i = 0; i < N; i++)
    visited[i] = false;
  //a,b구역 시작점을 잡고 DFS를 돌린다
  for (int i = 0; i < N; i++)
  {
    if (area[i] == false)
    {
      visited[i] = true;
      DFS(i + 1);
      break;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (area[i] == true)
    {
      visited[i] = true;
      DFS(i + 1);
      break;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (visited[i] == false)
      return INT_MAX;
  }
  //visited배열이 모두 true(방문한 상태)라면 구역이 옳게 나눠진 것이므로 인구차이 계산
  int a = 0, b = 0;
  for (int i = 0; i < N; i++)
  {
    if (area[i] == true)
      a += nums[i];
    if (area[i] == false)
      b += nums[i];
  }
  return abs(a - b);
}
void Combination(int cnt, int start, int point)
{
  if (cnt == point)
  {
    //true와 false로 a,b 구역을 나눔
    min_ans = min(Solve(), min_ans);
    return;
  }
  for (int i = start; i < N; i++)
  {
    area[i] = true;
    Combination(cnt + 1, i + 1, point);
    area[i] = false;
  }
}
int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> nums[i];

  for (int i = 1; i <= N; i++)
  {
    int l;
    cin >> l;
    while (l--)
    {
      int temp;
      cin >> temp;
      v[i].push_back(temp);
    }
  }
  for (int i = 0; i < N; i++)
    area[i] = false;

  for (int i = 1; i < N / 2 + 1; i++)
    Combination(0, 0, i);
  if (min_ans == INT_MAX)
  {
    cout << -1;
    return 0;
  }
  cout << min_ans;
}
