#include <iostream>

using namespace std;

typedef struct node{
    int num;
    int depth;
    struct node * parent;
    struct node * left;
    struct node * right;
}_node;

_node* root;

int ans;
void inorder(_node* node){
    if(node==nullptr){
        return;
    }
    inorder(node->left);
    // printf("inorder %d\n",node->num);
    ans+=node->depth;
    inorder(node->right);
}

void insert(_node** node, int num,_node* par){
    if((*node)==nullptr){
        *node=new _node;
        (*node)->num=num;
        (*node)->parent=par;
        (*node)->depth= par ? par->depth+1 : 1;


        ans+=(*node)->depth;
        return;
    }
    if(num<(*node)->num){
        insert( &((*node)->left) ,num,*node);
    }else{
        insert(&((*node)->right),num,*node);
    }
}

int N;
int main(){
    cin>>N;
    ans=1;

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(root==nullptr){
            root=new _node;
            root->num=num;
            root->depth=1;
        }else{
            insert(&root,num,nullptr);
        }
    }
    // ans=0;
    // inorder(root);
    cout<<ans;
}
