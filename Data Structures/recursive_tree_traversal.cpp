#include <iostream>
#include <cassert>
#include <vector>

std::vector<int64_t> inorder_result;
std::vector<int64_t> preorder_result;
std::vector<int64_t> postorder_result;

struct Node {                                                 // Data structure to store a binary tree node
    int64_t data = 0;
    Node *left, *right;

    Node(int64_t data)
    {
        this->data = data;
        this->left = this -> right = nullptr;
    }
};                                     
    
std::vector<int64_t> inorder(Node* root) {                      // Recursive function to perform "inorder" traversal on the tree
    
    if (root == nullptr) {                      // return if the current node is empty
        return {};
    }
    
    inorder(root -> left);                        // Traverse the left subtree   
    inorder_result.push_back(root -> data);                  // Display the data part of the root (or current node)
    inorder(root -> right);                       // Traverse the right subtree         
    return inorder_result;
}

std::vector<int64_t> preorder(Node* root) {                      // Recursive function to perform "preorder" traversal on the tree
    
    if (root == nullptr) {                      // if the current node is empty
        return {};
    }

    preorder_result.push_back(root -> data);             // Display the data part of the root (or current node)
    preorder(root -> left);                       // Traverse the left subtree
    preorder(root -> right);                      // Traverse the right subtree
    return preorder_result;
}

std::vector<int64_t> postorder(Node* root) {                     // Recursive function to perform "postorder" traversal on the tree   `
    
    if (root == nullptr) {                      // if the current node is empty
        return {};
    }

    postorder(root -> left);                      // Traverse the left subtree
    postorder(root -> right);                     // Traverse the right subtree
    postorder_result.push_back(root -> data);             // Display the data part of the root (or current node)
    return postorder_result;
}
 
static void test1(){
    Node* root = new Node(2);
    root -> left = new Node(7);
    root -> right = new Node(5);
    root -> left -> left = new Node(2);
    root -> left -> right = new Node(6);
    root -> right -> right = new Node(9);
    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(11);
    root -> right -> right -> left = new Node(4);
    
    std::vector<int64_t> actual_result_inorder{2, 7, 5, 6, 11, 2, 5, 4, 9};
    std::vector<int64_t> actual_result_preorder{2, 7, 2, 6, 5, 11, 5, 9, 4};
    std::vector<int64_t> actual_result_postorder{2, 5, 11, 6, 7, 4, 9, 5, 2};    
    std::vector<int64_t> result_inorder;
    std::vector<int64_t> result_preorder;
    std::vector<int64_t> result_postorder;

    int size = actual_result_inorder.size();
    
    //inorder traversal
    result_inorder = inorder(root);
    std::cout << "Test1 Inorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_inorder[i] == result_inorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //preorder traversal
    result_preorder = preorder(root);
    std::cout << "Test1 Preorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_preorder[i] == result_preorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //postorder traversal
    result_postorder = postorder(root);
    std::cout << "Test1 Postorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_postorder[i] == result_postorder[i]);
    }
    std::cout << "Passed" << std::endl;

    std::cout << std::endl;
}

static void test2(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    root -> right -> left -> left = new Node(7);
    root -> right -> left -> right = new Node(8);
    
    std::vector<int64_t> actual_result_inorder{4, 2, 1, 7, 5, 8, 3, 6};
    std::vector<int64_t> actual_result_preorder{1, 2, 4, 3, 5, 7, 8, 6};
    std::vector<int64_t> actual_result_postorder{4, 2, 7, 8, 5, 6, 3, 1};    
    std::vector<int64_t> result_inorder;
    std::vector<int64_t> result_preorder;
    std::vector<int64_t> result_postorder;

    int size = actual_result_inorder.size();
    
    //inorder traversal
    result_inorder = inorder(root);
    std::cout << "Test2 Inorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_inorder[i] == result_inorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //preorder traversal
    result_preorder = preorder(root);
    std::cout << "Test2 Preorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_preorder[i] == result_preorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //postorder traversal
    result_postorder = postorder(root);
    std::cout << "Test2 Postorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_postorder[i] == result_postorder[i]);
    }
    std::cout << "Passed" << std::endl;

    std::cout << std::endl;
}

static void test3(){
    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    
    std::vector<int64_t> actual_result_inorder{4, 2, 5, 1, 3};
    std::vector<int64_t> actual_result_preorder{1, 2, 4, 5, 3};
    std::vector<int64_t> actual_result_postorder{4, 5, 2, 3, 1};    
    std::vector<int64_t> result_inorder;
    std::vector<int64_t> result_preorder;
    std::vector<int64_t> result_postorder;

    int size = actual_result_inorder.size();
    
    //inorder traversal
    result_inorder = inorder(root);
    std::cout << "Test3 Inorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_inorder[i] == result_inorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //preorder traversal
    result_preorder = preorder(root);
    std::cout << "Test3 Preorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_preorder[i] == result_preorder[i]);
    }
    std::cout << "Passed" << std::endl;

    //postorder traversal
    result_postorder = postorder(root);
    std::cout << "Test3 Postorder Traversal...";
    for (int i = 0; i < size; ++i) {
        assert(actual_result_postorder[i] == result_postorder[i]);
    }
    std::cout << "Passed" << std::endl;

    std::cout << std::endl;
}



int main()
{
    //Testcase #1
    std::cout << "TestCase #1" << std::endl;
    test1();
    inorder_result.clear();
    preorder_result.clear();
    postorder_result.clear();

    //Testcase #2
    std::cout << "TestCase #2" << std::endl;
    test2();
    inorder_result.clear();
    preorder_result.clear();
    postorder_result.clear();

    //Testcase #3
    std::cout << "TestCase #3" << std::endl;
    test3();
    inorder_result.clear();
    preorder_result.clear();
    postorder_result.clear();

    return 0;
}
