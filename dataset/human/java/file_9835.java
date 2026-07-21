import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int c[] = new int[n];
    int a[][] = new int[n][m];
    for(int i = 0;i<n;i++){
      c[i] = sc.nextInt();
      for(int j = 0;j<m;j++){
        a[i][j] = sc.nextInt();
      }
    }

    boolean exist = false;
    int value = 1<<30;
    //bitzenntannsakudeha???
    for(int bit = 0;bit < (1<<n);bit++){
      int tmpvalue = 0;
      int understand[] = new int[m];
      for(int i = 0;i < n;i++){//c ni tuite kakuninn
        int bibi = bit & (1<<i);
        if(bibi != 0){
          tmpvalue += c[i];
          for(int j = 0;j<m;j++){//iroiro kasann
            understand[j] += a[i][j];
          }
        }
      }
      int checkcount = 0;
      for(int i = 0;i<m;i++){
        if(understand[i] >= x){
          checkcount++;
        }
      }
      if(checkcount != m){
        continue;
      }else{//jyoukenn ni tekisiteireba exist -> true nisite,value wo min de
        exist = true;
        value = Math.min(tmpvalue,value);
      }

    }
    if(exist){
      System.out.println(value);
    }else{
      System.out.println(-1);
    }
  }
}
