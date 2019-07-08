#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/toeplitz-matrix/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool vectorEQ(vector<int> &v1, vector<int> &v2, int v1b, int v2b, int len) {
        while (--len >= 0) {
            if (v1[v1b + len] != v2[v2b + len])
                return false;
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return true;
        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        for (int r = 1; r < rows; ++r) {
            if (matrix[r].size() != cols) return false;
            bool match = vectorEQ(matrix[r - 1], matrix[r], 0, 1, cols - 1);
            if (!match)
                return false;
        }
        return true;
    }
};

void test1() {
    vector<vector<int>> v1{
            vector<int>{1, 2, 3, 4},
            vector<int>{5, 1, 2, 3},
            vector<int>{9, 5, 1, 2}
    };

    cout << " ? " << Solution().isToeplitzMatrix(v1) << endl;
}

void test2() {

}

void test3() {

}