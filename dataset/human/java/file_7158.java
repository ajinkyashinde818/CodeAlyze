import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] a = new int[n];
    int sub = 0;
    int dis = 0;
    int max_dis = 0;

    for(int i=0; i<n; i++){
      a[i] = sc.nextInt();
    }

    for(int j=0; j<n; j++){
      if(j<n-1){
        sub = a[j+1]-a[j];
        dis += sub;
      }else if(j==n-1){
        sub = k - a[n-1]+a[0];
        dis += sub;
      }

      max_dis = Math.max(max_dis,sub);
      //System.out.println("MAX_DIS"+max_dis);


    }
    System.out.println(dis - max_dis);





  }
}
