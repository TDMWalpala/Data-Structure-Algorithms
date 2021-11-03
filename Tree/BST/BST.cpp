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
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    TreeNode *root;
    BST(){
        root = NULL;
    }

    bool isEmpty(){
        if(root==NULL){
            return true;
        }else{
            return false;
        }
    }
    void insertNode(TreeNode *newNode){
        if(root==NULL){
            root = newNode;
            cout<<"Value inserted as root node"<<endl;
        }
        else{
            TreeNode *temp = root;
            while(temp!=NULL){
                if(newNode->value==temp->value){
                    cout<<"You inserted value is already exist!"<<endl;
                    return;
                }else if((newNode->value < temp->value)&&(temp->left==NULL)){
                    temp->left = newNode;
                    cout<<"Value inserted"<<endl;
                    break;
                }else if(newNode->value < temp->value){
                    temp = temp->left;
                }else if((newNode->value > temp->value) && (temp->right==NULL)){
                    temp->right = newNode;
                    cout<<"Value inserted"<<endl;
                    break;
                }else
                    temp = temp->right;
                }
            }
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
    void printPreOrder(TreeNode *r){
        if(r==NULL){
            return;
        }
        cout<<r->value<<" ";
        printPreOrder(r->left);
        printPreOrder(r->right);
    }

    void printInOrder(TreeNode *r){
        if(r==NULL){
            return;
        }else{
            printInOrder(r->left);
            cout<<r->value<<" ";
            printInOrder(r->right);
        }
    }

    void printPostOrder(TreeNode *r){
        if(r==NULL){
            return;
        }else{
            printPostOrder(r->left);
            printPostOrder(r->right);
            cout<<r->value<<" ";
        }
    }
    int heightBST(TreeNode *r){
        if(r==NULL){
            return -1;
        }else{
            int Lheight = heightBST(r->left);
            int Rheight = heightBST(r->right);

            if(Lheight>Rheight){
                return(Lheight+1);
            }else{
                return(Rheight+1);
            }
        }
    }

    void PrintBreadthfist(TreeNode *r, int level){
        if(r==NULL){
            return;
        }else if(level==0){
            cout<<r->value<<" ";
        }else{
            PrintBreadthfist(r->left,level-1);
            PrintBreadthfist(r->right,level-1);
        }
    }

    void LevelBFS(TreeNode *r){
        int h = heightBST(r);
        for(int i = 0; i<=h; i++){
            PrintBreadthfist(r,i);
        }
    }
};

int main()
{
    int choice,val;
    BST tree1;

    do{
          cout<<"Enter your choice : "<<endl;
          cout<<"1. Insert Node "<<endl;
          cout<<"2. Search Node "<<endl;
          cout<<"3. Delete Node "<<endl;
          cout<<"4. Print BST values "<<endl;
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
                cout<<"Enter the value of Tree node to insert in BST : ";
                cin>>val;
                newNode->value = val;
                tree1.insertNode(newNode);
                break;
              case 2:
                cout<<"Search"<<endl;
                break;
              case 3:
                cout<<"Delete"<<endl;
                break;
              case 4:
                cout<<"BST Values"<<endl;
                tree1.print(tree1.root,5);
                tree1.printPreOrder(tree1.root);
                break;
              case 5:
                cout<<"Per-Order Traversal "<<endl;
                tree1.printPreOrder(tree1.root);
                break;
               case 6:
                cout<<"In-Order Traversal "<<endl;
                tree1.printInOrder(tree1.root);
                break;
               case 7:
                cout<<"Post-Order Traversal "<<endl;
                tree1.printPostOrder(tree1.root);
                break;
               case 8:
                cout<<"Level-Order(Breadth Fist) Traversal "<<endl;
                tree1.LevelBFS(tree1.root);
                break;
               case 9:
                cout<<"Height is "<<tree1.heightBST(tree1.root)<<endl;
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
