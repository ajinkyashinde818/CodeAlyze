import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[] a=new int[n];
    boolean mc=false;
    long sum=0;
    for(int i=0;i<n;i++){
      a[i]=sc.nextInt();
      if(a[i]<0){
        mc=!mc;
        a[i]*=-1;
      }
      sum+=a[i];
    }
    if(!mc){
      System.out.println(sum);
      return;
    }
    Arrays.sort(a);
    System.out.println(sum-2*a[0]);
  }
}
