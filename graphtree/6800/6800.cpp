#include <iostream>
using namespace std;
#include <string>
typedef struct node{
    char c;
    struct node* left;
    struct node* right;
    node() : left(NULL),right(NULL),c(NULL) {}
}_node;
_node root;



char* str;
int n;
void print_aux(_node *node){
    // printf("%s\n",str);
    char c= *str;
    // str++;
    
    if(c=='0'){
        
        if(node->left==NULL){
            // str++;
            cout<<node->c;
            return;
        }else{
            str++;
            print_aux(node->left);
        }
    }else{
        if(node->right==NULL){
            // str++;
            cout<<node->c;
            return;
        }else{
            str++;
            print_aux(node->right);
        }
    }
}
void print(){
    // printf("%s\n",str);
    while(*str!='\0'){
        print_aux(&root);
    }
}


int main(){
    cin>>n;
    str=new char[1001];
    char c;
    string code;
    _node* node;
    for(int i=0;i<n;i++){
        cin>>c>>code;
        node=&root;
        // /size_t size=code.length();
        
        for(int j=0;j<code.size();j++){
            // printf("a:%d\n",j);
            if(code[j]=='0'){
                if(node->left==nullptr){
                    node->left=new _node;
                }
                // node=node->left;
                node=node->left;
            }else{
                if(node->right==nullptr){
                    node->right=new _node;
                }
                node=node->right;
            }
            
        }
        node->c=c;
    }
    cin>>str;
    print();

}

