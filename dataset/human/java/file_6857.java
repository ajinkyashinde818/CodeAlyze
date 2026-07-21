import java.util.*;
class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt(),n = sc.nextInt();
    int a[]=new int[n];
    a[0]=sc.nextInt();
    int max=0;
    for(int i=1;i<n;i++){
      a[i]=sc.nextInt();
      if(max<a[i]-a[i-1]){
        max = a[i]-a[i-1];
      }
    }
    if(max<a[0]+k-a[n-1]){
      max = a[0]+k-a[n-1];
    }

    pl((k-max)+"");
  }

  public static void pr(String str){
    System.out.print(str);
  }
  public static void pl(String str){
    System.out.println(str);
  }
}
