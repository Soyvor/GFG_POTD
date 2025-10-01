#include <bits/stdc++.h>
using namespace std;
#define int long long

class Solution {
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        // Sort arrays
        sort(arr, arr + n);
        sort(brr, brr + m);

        int i = 0, j = m - 1;
        int diff = LLONG_MAX;
        int ans1 = -1, ans2 = -1;

        // Two pointer approach
        while (i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int currDiff = abs(sum - x);

            if (currDiff < diff) {
                diff = currDiff;
                ans1 = arr[i];
                ans2 = brr[j];
            }

            // Move pointers
            if (sum > x) {
                j--;  // need smaller sum
            } else {
                i++;  // need bigger sum
            }
        }

        return {ans1, ans2};
    }
};

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;
        int arr[n], brr[m];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < m; i++) cin >> brr[i];

        Solution sol;
        vector<int> ans = sol.printClosest(arr, brr, n, m, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
