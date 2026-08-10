/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flatten(root *TreeNode) {
    if root == nil {
        return
    }

    // 1. Recursively flatten the left and right subtrees first
    flatten(root.Left)
    flatten(root.Right)

    // 2. Store the flattened right subtree safely
    tempRight := root.Right

    // 3. Move the flattened left subtree to the right side
    root.Right = root.Left
    root.Left = nil // Strictly clear the left pointer

    // 4. Traverse to the end of the new right chain (the old left side)
    curr := root
    for curr.Right != nil {
        curr = curr.Right
    }

    // 5. Append the original right subtree to the very end
    curr.Right = tempRight
}

