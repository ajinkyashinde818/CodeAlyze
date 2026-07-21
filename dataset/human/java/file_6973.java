import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args)throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    try{
      String[] S = br.readLine().split(" ");
      int K = Integer.parseInt(S[0]);
      int N = Integer.parseInt(S[1]);
      S = br.readLine().split(" ");
      int[] val = new int[N];
      for(int i = 0; i < N; i++){
        val[i] = Integer.parseInt(S[i]);
      }
      int max = 0;
      for(int i = 0; i < N; i++){
        int a = 0;
        if(i == N-1){
          a = K-val[i]+val[0];
        }else{
          a = Math.abs(val[i]-val[i+1]);
        }
        max = a > max ? a : max;
      }
      System.out.println(K-max);
    }catch(Exception e){
    }
  }
}
