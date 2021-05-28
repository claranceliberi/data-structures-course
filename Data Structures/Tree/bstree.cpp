#include <iostream>
using namespace std;

class BST{
    int data;
    BST *left, *right;

    public:
        BST();

        BST(int);

        BST* Insert(BST*, int);

        void Inorder(BST*);

        BST* max(BST*);

        BST* min(BST*);

        int height(BST*);

        BST* deleteNode(BST*, int);
};


BST::BST(): data(0),left(NULL), right(NULL){
}


BST::BST(int value){
    data = value;
    left = right = NULL;
} 


BST* BST::Insert(BST* root, int value){
    if(!root){
        return new BST(value);
    }


    if(value > root->data){
        root->right = Insert(root->right, value);
    } else {
        root->left = Insert(root->left, value);
    }

    return root;
}

void BST::Inorder(BST* root){

    if(!root){
        return ;
    }

    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

BST* BST::max(BST* root){
    BST* bst  = root;

    while(bst->right) bst = bst->right;

    cout << "Max : " << bst->data << endl;

    return bst;
}

BST* BST::min(BST* root){
    BST* bst  = root;

    while(bst->left) bst = bst->left;

    cout << "Min : " << bst->data << endl;

    return bst;
}

int BST::height(BST* root){
    if(!root){
        return 0;
    } else {
        int lb = height(root->left);
        int rb = height(root->right);

        return std::max(lb,rb) + 1;
    }
}

BST* BST::deleteNode(BST* root, int key){
    if(!root) return NULL;

    if(key < root->data){
        root->left = BST::deleteNode(root->left,key);
    } else if (key > root->data){
        root->right = BST::deleteNode(root->right,key);
    } else {
        if(!root->left){
            BST* temp = root->right;
            delete(root);
            return temp;
        } else if(!root->right){
            BST* temp = root->left;
            delete(root);
            return temp;
        }

        BST* temp  = BST::min(root->right);

        root->data = root->data;

        root->right = deleteNode(root->right, temp->data); 

    }

    return root;
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.max(root);
    b.min(root);
    cout << "height : " << b.height(root) << endl;
    b.Inorder(root);
    b.deleteNode(root,60);
    cout << endl << endl;
    b.Inorder(root);
    return 0;
}