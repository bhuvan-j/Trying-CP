#include <iostream>
#include<set>
#include<string>
using namespace std;
void permute_string(char *inp,int i,set<string> &s){
    //base
    if(inp[i]=='\0'){
    //     cout<<inp<<","<<endl;
    string t(inp);
    s.insert(t);
    
        return;
    }

    //recursive
    for(int j=i;inp[j]!='\0';j++){
        swap(inp[i],inp[j]);

        permute_string(inp,i+1,s);

        swap(inp[i],inp[j]);

    }
    return;

}

int main() {
    
    char inp[100];
    set<string> s;
    cin>>inp;
    permute_string(inp,0,s);

    for(auto str : s){
        cout<<str<<endl;
    }



}
