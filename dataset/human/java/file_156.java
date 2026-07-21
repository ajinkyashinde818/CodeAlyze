import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
      a[i] = scanner.nextInt();
    }
    
    int negative_count_parity;
    if(a[0] < 0){
      negative_count_parity = 1;
    }else{
      negative_count_parity = 0;
    }
    //boolean zero_existence = false;
    int zero_closer = abs(a[0]);
    long sum = 0;
    for(int i = 1; i < n; i++){
      int ai = a[i];
      if(ai > 0){
        if(ai < zero_closer){
          sum += (long)zero_closer;
          zero_closer = ai;
        }else{
          sum += (long)ai;
        }
      }else if(ai == 0){
        sum += (long)zero_closer;
        zero_closer = 0;
      }else{
        if(ai > -zero_closer){
          sum += (long)zero_closer;
          zero_closer = -ai;
        }else{
          sum += (long)(-ai);
        }
        negative_count_parity ^= 1;
      }
    }
    
    if(negative_count_parity == 0){
      sum += (long)zero_closer;
    }else{
      sum -= (long)zero_closer;
    }
    
    System.out.println(sum);
  }
  
  public static int abs(int m){
    if(m < 0) m = -m;
    return m;
  }
}
