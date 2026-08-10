/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

func flatten(root *Node) *Node {
	if root == nil {
		return root
	}

	curr := root

	for curr != nil {
		if curr.Child != nil {
			next := curr.Next
			curr.Next = flatten(curr.Child)
			curr.Next.Prev = curr
			curr.Child = nil

			// find tail
			for curr.Next != nil {
				curr = curr.Next
			}

			if next != nil {
				curr.Next = next
				next.Prev = curr
			}
		}

        curr = curr.Next
	}

	return root
}