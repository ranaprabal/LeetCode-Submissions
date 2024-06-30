/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(root->val==key){
            if(root->left && root->right){
                TreeNode* lst = root->left; 
                while(lst->right){
                    lst = lst->right;
                }
                int key2 = lst->val;
                root->val = key2;
                root->left =  deleteNode(root->left,key2);
            }
            else if(root->left){
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else if(root->right){
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else{
                delete root;
                return NULL;
            }
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right =  deleteNode(root->right,key);
        }
        return root;
    }
};