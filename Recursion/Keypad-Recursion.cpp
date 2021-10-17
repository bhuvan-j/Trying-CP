#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// keypad
char dialer[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(char *input, char *output,int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
if(input[i]-'0'==0||input[i]-'0'==1){
        keypad(input,output,i+1,j);
    }
for(int k=0;dialer[input[i]-'0'][k]!='\0';k++){
    
    
    output[j]=dialer[input[i]-'0'][k];
    keypad(input,output,i+1,j+1);
    
}
return; 
}
int main() {
char inp[100];
cin>>inp;
char out[100];
keypad(inp,out,0,0);
  
}
