import java.util.*;
 
public class Main{
  public static void main(String[]args){
    Scanner sc =  new Scanner(System.in);
    String[] S = sc.nextLine().split(" ");
    int N = Integer.parseInt(S[0]);
    int M = Integer.parseInt(S[1]);
    int X = Integer.parseInt(S[2]);
    
    int[][] val = new int[N][M+1];
    for(int i = 0; i < N; i++){
      S = sc.nextLine().split(" ");
      for(int j = 0; j < M+1; j++){
        val[i][j] = Integer.parseInt(S[j]);
      }
    }
    
    int ans = 1000000000;
    for(int i = 1; i < 1<<N; i++){
      String bit = "000000000000"+Integer.toBinaryString(i);
      bit = bit.substring(bit.length()-N);
      int[] abi = new int[M];
      int sum = 0;
      for(int j = 0; j < N; j++){
        if(bit.charAt(j) == '1'){
          sum += val[j][0];
          for(int k = 1; k <= M; k++){
            abi[k-1] += val[j][k];
          }
        }
      }
      boolean flag = true;
      for(int j = 0; j < M; j++){
        if(abi[j] < X){
          flag = false;
          break;
        }
      }
      
      if(flag){
        ans = Math.min(ans, sum);
      }
    }
    System.out.println(ans == 1000000000 ? -1 : ans);
  }
}
