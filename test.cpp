#include <iostream>
#include <vector>

using namespace std;

bool canAchieveTargetScore(int N, int M, vector<int> &marks)
{
    vector<bool> dp(M + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = M; j >= marks[i]; j--)
        {
            dp[j] = dp[j] || dp[j - marks[i]];
        }
    }

    return dp[M];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        vector<int> marks(N);

        for (int i = 0; i < N; i++)
        {
            cin >> marks[i];
        }

        int remainingScore = 1000 - M;

        if (canAchieveTargetScore(N, remainingScore, marks))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
