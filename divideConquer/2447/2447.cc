#include <iostream>

using namespace std;

void star(int i,int j,int num){
    // printf("%d %d / %d ",i,j,num);
    if((i/num)%3 ==1 && (j/num)%3==1 ){
        // printf("blank\n");
        //cout<<" ";
    }else{
        if(num/3==0){
                printf("%d %d / %d ",i,j,num);
            printf("star\n");
            //cout<<"*";
        }else{
            star(i,j,num/3);
        }
    }
}

void bf(){

}
int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            star(i,j,num);

        }
                    bf();
        cout<<"\n";
    }
}