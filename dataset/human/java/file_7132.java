import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int a[] = new int[n];
    int total = 0;
    int max = 0;
    for(int i = 0;i<n;i++){
      a[i] = sc.nextInt();
    }
    int dis[] = new int[n];
    for(int i = 0;i<n-1;i++){//最後の以外の距離をだす&totalとmaxの管理
      dis[i] = a[i+1] - a[i];
      total += dis[i];
      if(max < dis[i]){
        max = dis[i];
      }
    }
    //最後と最初の距離をだす&&totalとmaxの管理
    dis[n-1] = k - a[n-1] + a[0];
    total += dis[n-1];
    if(max < dis[n-1]){
      max = dis[n-1];
    }

    int ans = total - max;
    System.out.println(ans);


  }
}
