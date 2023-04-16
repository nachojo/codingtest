#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
vector<int> v;
int num = 0;
bool check;
void Solve(int cnt, int num)
{
  if (cnt == N)
  {
    if (num >= pow(10, N) * 2)
      cout << num / 10 << endl;
    return;
  }
  for (int i = 0; i <= 9; i++)
  {
    check = true;
    for (int j = 2; j < num + i; j++)
    {
      if ((num + i) % j == 0)
      {
        check = false;
        break;
      }
    }
    if (!check)
      continue;
    Solve(cnt + 1, (num + i) * 10);
  }
}
int main()
{
  cin >> N;
  Solve(0, 0);
}
