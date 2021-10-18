#include <iostream>
using namespace std;
//char alpha[]={'.','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void generate_strings(char * inp, char * out,int i,int j){
//base
if(inp[i]=='\0'){
    out[j]='\0';
    cout<<out<<endl;
    return;

}

int digit= inp[i]-'0';
out[j]= digit+'a'-1;                      //alpha[inp[i]-'0'];
generate_strings(inp,out,i+1,j+1);

if(inp[i+1]!='\0'){
    int seconddigit=inp[i+1]-'0';
    int no=(digit*10+seconddigit);
    if(no<=26){
        out[j]=no+'a'-1;
        generate_strings(inp,out,i+2,j+1);
}
}
return;

}
int main() {
    
    char input[100];
    cin>>input;
    char output[100];
    generate_strings(input,output,0,0);
}
