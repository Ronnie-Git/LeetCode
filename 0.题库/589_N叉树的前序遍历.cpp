/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,IList<Node> _children) {
        val = _val;
        children = _children;
    }
}
*/

public class Solution {
    public IList<int> Preorder(Node root) {
        var res = new List<int>();
        if (root == null) return res;
        res.Add(root.val);
        if (root.children == null) return res;
        foreach(var c in root.children) {
            var t = Preorder(c);
            if (t != null) res.AddRange(t);
        }
        return res;
    }
}