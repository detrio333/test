#include <algorithm>

#include "tree.h"

std::tuple<int, std::vector<TreeNode*>> getDepht(TreeNode* root)
{
    if (root == nullptr)
        return { 0,  {} };

    const auto [ldepth, lnodes] = getDepht(root->leftChild);
    const auto [rdepth, rnodes] = getDepht(root->rightChild);

    if (ldepth == rdepth)
    {
        if (ldepth == 0)
            return { 1, { root } };

        std::vector<TreeNode*> newNodes;
        newNodes.reserve(lnodes.size() + rnodes.size());
        for (const auto node : lnodes)
            newNodes.push_back(node);
        for (const auto node : rnodes)
            newNodes.push_back(node);
        return { ldepth + 1, newNodes };
    }

    if (ldepth > rdepth)
        return { ldepth + 1, lnodes };

    return { rdepth + 1, rnodes };
}
