#include <bits/stdc++.h>                                                                       
using namespace std;                                                                           
                                                                                               
int main(){                                                                                    
                                                                                               
        int n,r,o;                                                                             
        scanf("%d %d", &n,&r);                                                                 
        if(n<=10){                                                                             
                o=100*(10-n);                                                                  
                printf("%d", r+o);                                                             
        } else if(n>=10){                                                                      
                printf("%d", r);                                                               
        }                                                                                      
        return 0;                                                                              
}
