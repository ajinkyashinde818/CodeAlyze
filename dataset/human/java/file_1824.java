import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int d = sc.nextInt();//問題番号
    int g = sc.nextInt();//目標点数
    int[] p = new int[d];//各番号の問題数
    int[] c = new int[d];//各番号のボーナス点数
    int min_count = Integer.MAX_VALUE;

    for(int i = 0; i < d; i++){
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }

    for(int i = 0; i < (int)Math.pow(2, d); i++){
      int max_idx = -1;
      int idx = d;
      int cnt = 0;
      int sum = 0;
      for(int j = 0; j < d; j++){
        idx -= 1;
        if((1 & (i >> j)) == 1){
          sum += p[idx] * (idx+1) * 100 + c[idx];
          cnt += p[idx];
        }else{
          max_idx = Math.max(max_idx, idx);
        }
      }
      if(sum < g){
        int one_cnt = 0;
        while( sum < g && one_cnt <= p[max_idx]){
          sum += 100 * (max_idx + 1);
          one_cnt += 1;
        }
        if(sum >= g){
          cnt += one_cnt;
        }else{
          cnt = Integer.MAX_VALUE;
        }
      }
      min_count = Math.min(min_count, cnt);
    }

    System.out.println(min_count);
  }
}
