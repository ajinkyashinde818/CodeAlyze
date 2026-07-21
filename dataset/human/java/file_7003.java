import java.io.*;

class Main{
	public static void main(String []args)throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int K, N, i, j, minDist = Integer.MAX_VALUE;
      String str = br.readLine();
      
      K = Integer.parseInt(str.substring(0, str.indexOf(" ")));
      N = Integer.parseInt(str.substring(str.indexOf(" ") + 1));
      
      int A[] = new int[N];
      str = br.readLine();
      String s[] = str.split(" ");
      
      for(i = 0; i < s.length; i++)
      {
        A[i] = Integer.parseInt(s[i]);
      }
      int dist[] = new int[N];
      int max = 0;
      for(i = 0; i < N - 1; i++)
      {
        	dist[i] = Math.abs(A[(i + 1) % N] - A[i % N]);
        if(dist[i] > dist[max])
          max = i;
      }
      dist[i] = K - A[N - 1] + A[0];
      if(dist[i] > dist[max])
        max = i;
      minDist = 0;
      for(i = 0; i < N; i++)
      {
          minDist = minDist + dist[i];
      }
      System.out.println(minDist - dist[max]);
    }
}
