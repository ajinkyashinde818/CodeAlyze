import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] arr = new int[n];
    for(int i=0;i<n;i++){
      arr[i]=sc.nextInt();
    }
    int[] dist = new int[n];
    for(int i=0;i<n-1;i++){
      dist[i]=arr[i+1]-arr[i];
    }
    dist[n-1]=k-arr[n-1]+arr[0];
    Arrays.sort(dist);
    int ans=0;
    for(int i=0;i<n-1;i++){
      ans = ans +dist[i];
    }
    System.out.println(ans);
  }
}
