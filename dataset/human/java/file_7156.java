import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    
    int[] a = new int[n];
    for(int i=0;i<n;i++){
      a[i] = sc.nextInt();
    }
    int ans = a[n-1] - a[0];
    for(int i=0;i<n-1;i++){
      ans = Math.min(ans,k-(a[i+1]-a[i]));
    }
    System.out.println(ans);
  }
}
