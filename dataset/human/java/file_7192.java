import java.util.*;
public class Main {
    public static void main(String[] args){
      // 入力
      Scanner sc = new Scanner(System.in);
      int K = sc.nextInt();
      int N = sc.nextInt();
      int[] A = new int[N];
      for(int i = 0; i < N; i++){
        A[i] = sc.nextInt();
      }
      
      // 家間の距離の総和と最も離れた距離を算出
      int total = 0;
      int max = 0;
      for(int i = 0; i < N; i++){
        int distance = 0;
        if(i < N-1){
          distance = A[i+1] - A[i];
        }else{
          distance = A[0] + K - A[i];
        }
        
        if(max < distance){
          max = distance;
        }
        
        total += distance;
      }
      
      int result = total - max;
      
      // 出力
      System.out.println(result);
    }
    
}
