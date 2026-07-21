import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    long k=sc.nextLong();
    int[] a=new int[n];
    int[] aa=new int[n];
    int[] tmp;
    for(int i=0;i<n;i++){
      a[i]=sc.nextInt()-1;
    }
    int ans=0;
    while(k>0){
      if((k&1)==1){
        ans=a[ans];
      }
      for(int i=0;i<n;i++){
        aa[i]=a[a[i]];
      }
      tmp=aa;
      aa=a;
      a=tmp;
      k=k>>1;
    }
    System.out.println(ans+1);
  }
}
