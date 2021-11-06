#include <iostream>
#define SPACE 10

using namespace std;
class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v){
        value =v;
        left = NULL;
        right = NULL;
    }
};

class AVLTree{
public:
    TreeNode *root;
    AVLTree(){
        root = NULL;
    }

    bool isTreeEmpty(){
        if(root==NULL){
            return true;
        }else{
            return false;
        }
    }
    int height(TreeNode *r){
        if(r==NULL){
            return -1;
        }else{
            int Lheight = height(r->left);
            int Rheight = height(r->right);

            if(Lheight>Rheight){
                return(Lheight+1);
            }else{
                return(Rheight+1);
            }
        }
    }

    int getBalanceFactor(TreeNode *n){
        if(n==NULL){
            return -1;
        }else{
            return height(n->left) - height(n->right);
        }
    }
    TreeNode *rightRotate(TreeNode *y){
        TreeNode *x = y->left;
        TreeNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode *leftRotate(TreeNode *x){
        TreeNode *y = x->right;
        TreeNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* insert(TreeNode *r, TreeNode *new_node){
        if(r==NULL){
            r = new_node;
            cout<<"Value inserted successfully"<<endl;
            return r;
        }
        if(new_node->value<r->value){
            r->left = insert(r->left,new_node);
        }else if(new_node->value>r->value){
            r->right = insert(r->right,new_node);
        }else{
           cout<<"Value is duplicate"<<endl;
           return r;
        }

        int bf = getBalanceFactor(r);
        if(bf>1 &&new_node->value<r->left->value){
            return rightRotate(r);
        }
        if(bf<-1 && new_node->value>r->right->value){
            return leftRotate(r);
        }
        if(bf>1 && new_node->value > r->left->value){
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        if(bf<-1 && new_node->value < r->right->value){
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }
    void print(TreeNode *r, int space){
        if(r==NULL){
            return;
        }
        space += SPACE;
        print(r->right, space);
        cout << endl;
        for(int i=SPACE; i<space;i++){
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print(r->left, space);
    }
};


int main()
{
    int choice,val;
    AVLTree tree1;

    do{
          cout<<"Enter your choice : "<<endl;
          cout<<"1. Insert Node "<<endl;
          cout<<"2. Search Node "<<endl;
          cout<<"3. Delete Node "<<endl;
          cout<<"4. Print AVL Tree values "<<endl;
          cout<<"5. Pre-Order Traversal "<<endl;
          cout<<"6. In-Order Traversal "<<endl;
          cout<<"7. Post-Order Traversal "<<endl;
          cout<<"8. Level-Order Traversal(BFS) "<<endl;
          cout<<"9. Height of Tree "<<endl;
          cout<<"10. Clear Screen "<<endl;
          cout<<"0. Exit Program "<<endl;
          cin>>choice;
          TreeNode *newNode = new TreeNode();

          switch(choice){
              case 0:
                  break;
              case 1:
                cout<<"Insert"<<endl;
                cout<<"Enter the value of Tree node to insert in AVL Tree : ";
                cin>>val;
                newNode->value = val;
                tree1.root=tree1.insert(tree1.root,newNode);
                break;
              case 2:
                cout<<"Search"<<endl;
                break;
              case 3:
                cout<<"Delete"<<endl;
                break;
              case 4:
                cout<<"AVL Tree Values"<<endl;
                tree1.print(tree1.root,5);
                break;
              case 5:
                cout<<"Per-Order Traversal "<<endl;

                break;
               case 6:
                cout<<"In-Order Traversal "<<endl;

                break;
               case 7:
                cout<<"Post-Order Traversal "<<endl;

                break;
               case 8:
                cout<<"Level-Order(Breadth Fist) Traversal "<<endl;

                break;
               case 9:
                cout<<"Height is "<<tree1.height(tree1.root)<<endl;
                break;
               case 10:
                system("cls");
                break;
              default :
                cout<<"Please enter valid choice number!"<<endl;
                break;
          }

    }while(choice!=0);

    return 0;
}

