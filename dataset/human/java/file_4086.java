import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] Astr = br.readLine().split(" ");
        String[] Bstr = br.readLine().split(" ");
        String[] Cstr = br.readLine().split(" ");
        
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];
        
        for(int i = 0; i < N; i++){
            A[i] = Integer.parseInt(Astr[i]);
            B[i] = Integer.parseInt(Bstr[i]);
            if(i != N-1) C[i] = Integer.parseInt(Cstr[i]);
        }
        
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += B[A[i] -1];
            if( (i < N - 1) && (A[i] + 1 == A[i+1]) ) sum += C[A[i]-1];
        }
        
        System.out.println(sum);
    }
}
