auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if (!p || !q){
        return p==q;
       }
        return p->val == q->val && 
                isSameTree(p->left,q->left) &&
                isSameTree(p->right,q->right);
    }
};
