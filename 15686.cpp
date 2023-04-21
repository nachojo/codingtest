#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX 51
using namespace std;
vector<pair<int, int> > house;
vector<pair<int, int> > chiken;
int n, m, arr[MAX][MAX], min_ans = INT_MAX;
int result[14];
void combi(int cnt, int start)
{
  if (cnt == m)
  {

    int sum = 0;
    for (int i = 0; i < house.size(); i++)
    {
      int min_dis = MAX * MAX;
      for (int j = 0; j < m; j++)
      {
        min_dis = min(abs(house[i].first - chiken[result[j]].first) + abs(house[i].second - chiken[result[j]].second), min_dis);
        if (min_dis == 1)
          break;
      }
      sum += min_dis;
    }

    min_ans = min(sum, min_ans);
    return;
  }
  for (int i = start; i < chiken.size(); i++)
  {
    result[cnt] = i;
    combi(cnt + 1, i + 1);
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == 1)
        house.push_back(make_pair(i, j));
      if (arr[i][j] == 2)
        chiken.push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < m; i++)
    result[i] = 0;

  combi(0, 0);

  cout << min_ans;
}