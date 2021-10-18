#include <iostream>
using namespace std;
void permute_string(char *inp,int i){
    //base
    if(inp[i]=='\0'){
        cout<<inp<<",";
        return;
    }

    //recursive
    for(int j=i;inp[j]!='\0';j++){
        swap(inp[i],inp[j]);

        permute_string(inp,i+1);

        swap(inp[i],inp[j]);

    }
    return;

}

int main() {
    
    char inp[100];
    cin>>inp;
    permute_string(inp,0);




}
