#include <vector>
using namespace std;

vector<long long> solve(int N, int M, vector<int> A, vector<vector<int>> queries) {
    A.insert(A.begin(), 0);
    vector<int> count(N + 1, 0), sum(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        sum[i] = (sum[i - 1] + A[i]) % 2;
        count[i] = count[i - 1];
        if (sum[i] % 2 == 0)
            count[i]++;
    }

    vector<long long> results;
    for (auto& query : queries) {
        int L = query[0], R = query[1];
        int even = count[R] - count[L - 1];
        int odd = (R - L + 1) - even;
        if (sum[L - 1] == 1)
            swap(even, odd);
        even++;
        long long subCount = (long long)(even * (even - 1)) / 2 + (long long)(odd * (odd - 1)) / 2;
        results.push_back(subCount);
    }

    return results;
}
