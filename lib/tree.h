#pragma once
#include <vector>

struct TreeNode
{
    TreeNode(int i) : number(i) {}

    int number;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

std::tuple<int, std::vector<TreeNode*>> getDepht(TreeNode* root);