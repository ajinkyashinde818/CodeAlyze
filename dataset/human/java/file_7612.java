import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    long k = sc.nextLong();
    int[] a = new int[n];
    int[] first_time = new int[n];
    boolean[] flag = new boolean[n];

    for(int i=0; i<n; i++){
      a[i] = sc.nextInt()-1;
    }

    int here_start = 0;
    int here = here_start;
    int times = 1;
    flag[0] = true;
    first_time[0] = times;
    times += 1;
    int period = 0;
    int not_period = 0;
    int start_node = 0;

    while(true){
      here = a[here];
      if(flag[here]==false){
        flag[here] = true;
        first_time[here] = times;
      }else{
        period = times - first_time[here];
        not_period = times - period -1;
        start_node = here;
        break;
      }

      times ++;
    }

    // System.out.println(period);
    // System.out.println(not_period);

    int ans = 0;

    if(k<not_period){
      here = here_start;
      for(int i=0; i<k; i++){
        here = a[here];
      }
      System.out.println(here+1);
    }else{
      long bb = (k - not_period) % period;
      for(int i=0; i<bb; i++){
        start_node = a[start_node];
      }
      System.out.println(start_node+1);
    }



  }
}
