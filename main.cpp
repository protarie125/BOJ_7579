#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll n, m;
vl mem, cost;
vvl dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  dp = vvl(n + 1, vl(100 * 100 + 1, 0));

  mem = vl(n + 1);
  cost = vl(n + 1);

  for (auto i = 1; i <= n; ++i) {
    cin >> mem[i];
  }

  auto total = ll{0};
  for (auto i = 1; i <= n; ++i) {
    cin >> cost[i];
    total += cost[i];
  }

  for (auto i = 1; i <= n; ++i) {
    for (auto j = 0; j <= total; ++j) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);

      if (0 <= j - cost[i]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
      }
    }
  }

  for (auto j = 0; j <= total; ++j) {
    if (m <= dp[n][j]) {
      cout << j << '\n';
      return 0;
    }
  }

  return 0;
}