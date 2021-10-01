#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int> &nums, int start, int end){

    if(start > end)
        return nullptr;
    
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = helper(nums,start,mid-1);
    root->right = helper(nums,mid+1,end);

    return root;    
}

TreeNode* arrayToBST(vector<int> &nums){

    int n=nums.size();
    TreeNode* root = helper(nums,0,n-1);
    return root;

}

void preOrder(TreeNode* root){
    if(root != nullptr){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){

    vector<int> num1 = {1,2,3,4,5};
    TreeNode* root1 = arrayToBST(num1);
    preOrder(root1);

    cout << endl;

    vector<int> num2 = {-18,-8,0,7,11};
    TreeNode* root2 = arrayToBST(num2);
    preOrder(root2);


    return 0;
}