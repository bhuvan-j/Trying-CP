#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Subset / subsequence generation
// subset = 2^n (either that character will be there or not there)
//[abc]=[a,b,c,"",ab,ac,bc,abc]=8=2^3


//RECURSIVELY MAKE SUBSETS OF "bc"
// NOW WE CAN EITHER ADD "a" in front of them or we will not add "a"

//              f(abc) = "a"f(bc) + f(bc)

// vector<string> subset(string a,int i){
//     if(i==a.size()-1){
//         vector<string> p;
//         p.push_back("");
//         string s(1,a[i]);
//         p.push_back(s);
//         return p;
//     }
//     vector<string>sub = subset(a,i+1);
//     vector<string>sub2;
//     string st(1,a[i]);
//     for(int j=0;j<sub.size();j++){
//         sub2.push_back(st+sub[j]);
//     }
//     int x=sub.size()-1;
//     while(x--){
//         sub2.push_back(sub[x]);
//     }
//     return sub2;
// }
void generate_subsequence(char *input,char *output,int i,int j){
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    //include character
    output[j]=input[i];
    generate_subsequence(input,output,i+1,j+1);

    //exclude character
    generate_subsequence(input,output,i+1,j);
}
int main() {
    // vector<string>sub2 = subset("abc",0);
    // for(int i=0;i<sub2.size();i++){
    //     cout<<sub2[i]<<endl;
    // }


    char s[]= "abc";
    char output[10];
    generate_subsequence(s,output,0,0);

    return 0;
}
