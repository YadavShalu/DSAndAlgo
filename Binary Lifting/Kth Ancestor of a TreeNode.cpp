/* Leetcode Link : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/  */

// Approach 1: Binary Lifting (C++ implementation)

// Time Complexity: O(Q * log(n)) where Q= number of queries and n = number of nodes
// Space Complexity: O(n*log(n)) to store the ancestor/parent of each node at different levels.

#include<bits/stdc++.h>
using namespace std;
class TreeAncestor{
    public:
    int rows, cols;
    vector<vector<int>> parentTable;

    TreeAncestor(int n, vector<int>& parent){
        rows = n;
        cols = log2(n)+1;

        parentTable.resize(rows, vector<int>(cols,-1));

        // Pre-compute the parent table using parent vector
        for(int node=0; node<rows ; node++){
            parentTable[node][0] = parent[node];
        }

        // Fill the parent table
        // parentTable[node][j] = parentTable[parentTable[node][j-1]][j-1]
        for(int j=1; j<cols; j++){
            for(int node=0; node<rows; node++){
                if(parentTable[node][j-1] != -1){
                    parentTable[node][j] = parentTable[parentTable[node][j-1]][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k){

        for(int j=0; j<cols; j++){
            if(k & (1<<j)){ // check if the j-th bit is set in k
                node = parentTable[node][j]; //move up to the 2^j-th ancestor
                if(node==-1){ // if we reach -1, it means there is no ancestor at this level
                    return -1;
                }
            }
        }
        return node; // return the k-th ancestor
    }

}