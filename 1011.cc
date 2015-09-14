#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> result;
    if(n == 0) return -1;
    vector<int> resource(n, 0);
    vector<int> sorted(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> resource[i];
    }
    vector<int> min(n, INT_MAX);
    min[0] = INT_MIN;
    int curMin = INT_MIN;
    for(int i = 1; i < n; ++i) {
        min[i] = (resource[i-1] > curMin) ? resource[i-1] : curMin;
        curMin = min[i];
    }
    vector<int> max(n, INT_MIN);
    max[n-1] = INT_MAX;
    int curMax = INT_MAX;
    for(int i = n - 2; i >= 0; --i) {
        max[i] = (resource[i+1] < curMax) ? resource[i+1] : curMax;
        curMax = max[i];
    }
    for(int i = 0; i < n;++i) {
        if(resource[i] > min[i] && resource[i] < max[i])
            result.push_back(resource[i]);
    }
    cout << result.size() << endl;
    for(int i = 0; i < result.size()-1; i++) {
      cout << result[i] << " ";
    }
    cout << result[result.size()-1] << endl;
    return 0;
}
