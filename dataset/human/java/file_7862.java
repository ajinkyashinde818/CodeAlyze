import java.io.*;
import java.util.*;

class Main{
	public static void main(String []args)throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      String str = br.readLine();
      String s[] = str.split(" ");
      
      int N = Integer.parseInt(s[0]);
      long K = Long.parseLong(s[1]);
      
      str = br.readLine();
      String arr[] = str.split(" ");
      int town[] = new int[N + 1];
      
      for(int i = 0; i < arr.length; i++){
      	town[i + 1] = Integer.parseInt(arr[i]);
      }
      
      boolean visited[] = new boolean[N + 1];
      
      Arrays.fill(visited, false);
      visited[1] = true;
      int cycleStart, nextTown = town[1], edgesTillCycle = 0;
      //for(int i = 1; i <= N; i++){
      while(true){
     	edgesTillCycle++;
        if(visited[nextTown]){
          cycleStart = nextTown;
          break;
        }
      	visited[nextTown] = true;
        nextTown = town[nextTown];
      }
      
      int lengthCycle = 0;
      nextTown = town[nextTown];
      while(true){
        lengthCycle++;
        if(nextTown == cycleStart)
          break;
        nextTown = town[nextTown];
      }
      
      int beforeCycle = edgesTillCycle - lengthCycle;
      
      if(K > beforeCycle){
        K = K - beforeCycle;
        K = K % lengthCycle;
        nextTown = cycleStart;
      }
      else{
        nextTown = 1;
      }
      
       while(K != 0){
          K--;
          nextTown = town[nextTown];
        }
        System.out.println(nextTown);        
    }
}
