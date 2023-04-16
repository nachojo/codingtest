//도영이가 만든 맛있는 음식
#include <iostream>
#include <climits>
#define MAX 10
using namespace std;
int n = 0, arr1[MAX], arr2[MAX], min_ans = INT_MAX;
bool visited[MAX];
void powerset(int cnt, int total, int mul);
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr1[i] >> arr2[i];
  for (int i = 0; i < n; i++)
    visited[i] = false;
  powerset(0, 1, 0);
  cout << min_ans;
}
void powerset(int cnt, int total, int mul)
{
  if (cnt == n)
  {
    int temp = 0;
    //공집합 빼주기
    for (int i = 0; i < n; i++)
      if (visited[i] == false)
        temp++;
    if (temp == n)
      return;
    //
    min_ans = min(abs(total - mul), min_ans);
    return;
  }
  visited[cnt] = true;
  powerset(cnt + 1, total * arr1[cnt], mul + arr2[cnt]);
  visited[cnt] = false;
  powerset(cnt + 1, total, mul);
}