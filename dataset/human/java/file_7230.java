import java.io.*;
import java.lang.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] s=br.readLine().split(" ");
        int K=Integer.parseInt(s[0]);
        int N=Integer.parseInt(s[1]);
        int arr[]=new int[2*N];
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        for(int i=0;st.hasMoreTokens();i++){
            arr[i]=Integer.parseInt(st.nextToken());
            arr[N+i]=K+arr[i];
        }
        int ans=Integer.MAX_VALUE;
        for(int i=0;i<N;i++){
            int dist=arr[N-1+i]-arr[i];
            if(dist<ans) ans=dist;
        }
        System.out.println(ans);
    }
}
