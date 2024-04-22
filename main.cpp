#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:

    int bfs(vector<string>& deadends, string target){
        unordered_set<string> deadend_set(deadends.begin(), deadends.end());
        if(deadend_set.find("0000") != deadend_set.end()) return -1;
        string start = "0000";
        queue<pair<string, int>> q;
        q.push({start, 0});
        unordered_set<string> visited;
        visited.insert(start);

        //bfs
        while(!q.empty()){
            auto [node, depth] = q.front();
            q.pop();
            if(node == target) return depth;
            for(int i = 0; i < 4; i++){
                string next = node;
                next[i] = (node[i] - '0' + 1) % 10 + '0';
                if(visited.find(next) == visited.end() && deadend_set.find(next) == deadend_set.end()){
                    q.push({next, depth + 1});
                    visited.insert(next);
                }
                next[i] = (node[i] - '0' + 9) % 10 + '0';
                if(visited.find(next) == visited.end() && deadend_set.find(next) == deadend_set.end()){
                    q.push({next, depth + 1});
                    visited.insert(next);
                }
            }
        }
        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        int res = bfs(deadends, target);
        return res;
    }
};


int main() {
    Solution s;
    vector<string> deadends {"0201","0101","0102","1212","2002"};
    string target = "0202";
    cout << s.openLock(deadends, target);
    return 0;
}
