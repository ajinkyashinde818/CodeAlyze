#include<stdio.h>

int main(){
  char S[101],T[101];
  int S_length=0,T_length=0,ans=0;
  scanf("%s",S);
  for (int i = 0; i < 101; i++){
    if(S[i]!='\000'){
      S_length++;
    }else{
      break;
    }
  }
  scanf("%s",T);
  for (int i = 0; i < 101; i++){
    if(T[i]!='\000'){ 
      T_length++;
    }else{
      break;
    }
  }

  for (int i = 0; i < S_length-1; i++){
    int min=S[i];
    int t,s=i;
    for (int j = i+1; j < S_length; j++){
      if (min>S[j]){
        min=S[j];
        s=j;
      }
    }
    t=S[i]; S[i]=S[s]; S[s]=t;
  }
  
  for (int i = 0; i < T_length-1; i++){
    int max=S[i];
    int t,l=i;
    for (int j = i+1; j < T_length; j++){
      if (max<T[j]){
        max=T[j];
        l=j;
      }
    }
    t=T[i]; T[i]=T[l]; T[l]=t;
  }

  for (int i = 0; i < S_length; i++)
  {
    if(S[i]==T[i]){
      ans=0;
    }else if(S[i]<T[i]){
      ans=1;
      break;
    }else{
      ans=-1;
      break;
    }
  }

  if (ans==1){
    puts("Yes");
  }else if (ans==0&&S_length<T_length){
    puts("Yes");
  }else{
    puts("No");
  }

  return 0;
}
