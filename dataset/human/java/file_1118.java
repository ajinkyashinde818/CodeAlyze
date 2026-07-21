import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    long[] a=new long[n+1];
    for(int i=1;i<=n;i++){
      a[i]=a[i-1]+sc.nextLong();
    }
    long min=Long.MAX_VALUE;
    for(int i=1;i<n;i++){
      min=Math.min(Math.abs(a[i]-a[0]-a[n]+a[i]),min);
    }
    System.out.println(min);
  }
}
