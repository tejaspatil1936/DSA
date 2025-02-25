#include <iostream>
#include <vector>
#include <climits> // Include this for INT_MIN

using namespace std;

class Solution
{
public:
    vector<vector<int>> graph;
    vector<int> bobTime;

    void findBobPath(int node, int parent, int time, vector<int> &path, int bob)
    {
        path.push_back(node);
        if (node == bob)
        {
            for (int i = 0; i < path.size(); ++i)
                bobTime[path[i]] = i;
            return;
        }
        for (int neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                findBobPath(neighbor, node, time + 1, path, bob);
                if (!bobTime.empty())
                    return;
            }
        }
        path.pop_back();
    }

    int dfsAlice(int node, int parent, int time, vector<int> &amount)
    {
        int income = 0;
        if (bobTime[node] == -1 || time < bobTime[node])
            income = amount[node]; // Alice takes full amount
        else if (time == bobTime[node])
            income = amount[node] / 2; // Split with Bob
        int maxProfit = INT_MIN;
        for (int neighbor : graph[node])
        {
            if (neighbor != parent)
            {
                maxProfit = max(maxProfit, dfsAlice(neighbor, node, time + 1, amount));
            }
        }
        return (maxProfit == INT_MIN) ? income : income + maxProfit; // If leaf, return income
    }

    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = amount.size();
        graph.resize(n);
        bobTime.assign(n, -1);

        // Build graph (undirected tree)
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Find Bob's arrival times at each node
        vector<int> path;
        findBobPath(0, -1, 0, path, bob);

        // Compute Alice's maximum net income using DFS
        return dfsAlice(0, -1, 0, amount);
    }
};

// **Driver Code**
int main()
{
    Solution sol;

    // **Example 1**
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    int bob1 = 3;
    vector<int> amount1 = {-2, 4, 2, -4, 6};
    cout << "Output: " << sol.mostProfitablePath(edges1, bob1, amount1) << endl; // Expected Output: 6

    // **Example 2**
    vector<vector<int>> edges2 = {{0, 1}};
    int bob2 = 1;
    vector<int> amount2 = {-7280, 2350};
    cout << "Output: " << sol.mostProfitablePath(edges2, bob2, amount2) << endl; // Expected Output: -7280

    return 0;
}
