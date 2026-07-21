import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner s=new Scanner(System.in);
    int n=s.nextInt();
    int arr[][]=new int[n][n];
     for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
          arr[i][j]=s.nextInt();
        }
    }
    int flag=0;
    for(int i=0;i<=n-3;i++){
        if(arr[i][0]==arr[i][1] && arr[i+1][0]==arr[i+1][1] && arr[i+2][0]==arr[i+2][1]){
          flag=1;
          break;
    }
   }
    
    if(flag==1)
    System.out.println("Yes");
    else
     System.out.println("No");
  }
}
