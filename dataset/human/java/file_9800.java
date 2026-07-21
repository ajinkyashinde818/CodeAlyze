import java.util.*;

class Main {
  public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
    
    int N = sc.nextInt();
    int M = sc.nextInt();
    long X = sc.nextLong();
    long[] P= new long[N]; 
    long[][]  Y = new long[N][M];
    long[] ans = new long[M];
    for (int i = 0; i < N; i++){
      P[i] = sc.nextLong();
      for (int j = 0;j<M;j++){        
        Y[i][j] = sc.nextLong();
      }
    }
            
    long max = 10000000;
    for (long bit = 0; bit < (1<< N);bit++){
      Arrays.fill(ans, 0);
      long sum = 0;
      for (int j = 0; j < N; j++){
        if ((bit & (1 << j)) == 0){
          sum += P[j];
          for (int i = 0; i < M; i++){            
          	ans[i] += Y[j][i];            
          }
        }
      }
      int temp = 0;
      while (temp < M  && ans[temp] >= X){
      	temp++;        
      }
      if (temp == M){
        max = Math.min(sum,max);
      }
    }
   if (max != 10000000){
     System.out.println(max);
   }else{
     System.out.println(-1);
   }
  }
}
