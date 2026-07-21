import java.util.*;

class Main{
  public static int min(int a,int b){
    return (a<b)?a:b;
  }
  
  public static int max(int a,int b){
    return (a>b)?a:b;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String str=sc.next();
    int N=str.length();
    int[] num=new int[N];
    int[][] pay=new int[N+1][2];
    int ans=0;
    
    for(int i=0;i<N;i++){
      num[i]=Character.getNumericValue(str.charAt(i));
    }
    
    pay[0][0]=0;
    pay[0][1]=1;
    
    for(int i=1;i<N+1;i++){
      pay[i][0]=min(pay[i-1][0]+num[i-1],pay[i-1][1]+10-num[i-1]);
      pay[i][1]=min(pay[i-1][0]+num[i-1]+1,pay[i-1][1]+10-num[i-1]-1);
    }
    
   System.out.print(pay[N][0]);
  }
}
