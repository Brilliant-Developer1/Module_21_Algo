// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

// #include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dp[N];

int solve(int a[], int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != -1)
        return dp[n];

    else if (n == 2)
    {
        return dp[n] = abs(a[2] - a[1]);
    }
    else
    {
        int choice1 = solve(a, n - 1) + abs(a[n] - a[n - 1]);
        int choice2 = solve(a, n - 2) + abs(a[n] - a[n - 2]);

        return dp[n] = min(choice1, choice2);
    }
}

int main()
{

    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        cin >> a[i];
    }
    cout << solve(a, n);

    return 0;
}