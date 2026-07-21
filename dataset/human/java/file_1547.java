import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int m=sc.nextInt();
    String[] a = new String[n];
    String[] b = new String[m];
    for(int i=0;i<n;i++){
      a[i]=sc.next();
    }
    for(int i=0;i<m;i++){
      b[i]=sc.next();
    }
    for(int i=0;i<=n-m;i++){
      for(int j=0;j<=n-m;j++){
        if(calc(a,b,i,j)){
          System.out.println("Yes");
          return;
        }
      }
    }
    System.out.println("No");
  }
  static boolean calc(String[] a,String[] b,int y,int x){
    for(int i=0;i<b.length;i++){
      for(int j=0;j<b.length;j++){
        if(a[y+i].charAt(x+j)!=b[i].charAt(j)){
          return false;
        }
      }
    }
    return true;
  }
}
