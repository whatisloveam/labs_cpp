#include "TreeNode.h"

TreeNode::~TreeNode() 
{
    delete right;
    delete left;
}