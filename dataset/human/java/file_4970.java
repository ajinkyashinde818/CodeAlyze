import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args)throws Exception{
    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    try{
      String S = sc.readLine();
      Deque<String> deq = new ArrayDeque<>();
      deq.add(S);
      int N = Integer.parseInt(sc.readLine());
      boolean f = true;
      for(int i = 0; i < N; i++){
        String[] T = sc.readLine().split(" ");
        int order = Integer.parseInt(T[0]);
        if(order == 1){
          f = !f;
        }else{
          int o2 = Integer.parseInt(T[1]);
          if(o2 == 1){
            if(f){
              deq.addFirst(T[2]);
            }else{
              deq.addLast(T[2]);
            }
          }else{
            if(f){
              deq.addLast(T[2]);
            }else{
              deq.addFirst(T[2]);
            }
          }
        }
      }
      StringBuilder sb = new StringBuilder();
      for(String s : deq){
        sb.append(s);
      }
      System.out.println(f ? sb.toString() : sb.reverse().toString());
    }catch(Exception e){
    }
  }
}
