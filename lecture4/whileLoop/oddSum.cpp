
#include <iostream>
using namespace std;
int main()
{
    int oddSum=0;
    int n;
    cout<<"Enter the n";
    cin>>n;
    int i=1;
    
    while( i<=n){
        if(i%2!=0){
           oddSum+=i;
            
        }
        i++;
    }
    cout<<oddSum;
    return 0;
} 