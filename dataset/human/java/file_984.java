import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long C = sc.nextLong();
        long[] x = new long[N];
        long[] v = new long[N];
        for(int n=0;n<N;n++){
        	x[n] = sc.nextLong();
        	v[n] = sc.nextLong();
        }
        
        long[] forwardSum = new long[N];
        forwardSum[0]=v[0];
        for(int n=1;n<N;n++) forwardSum[n]= forwardSum[n-1]+v[n];
        long[] forwardMax = new long[N];
        long[] forwardBackMax = new long[N];
        for(int n=0;n<N;n++){
	forwardMax[n] = Math.max(forwardSum[n]-x[n],(n==0)?0:forwardMax[n-1]);
	forwardBackMax[n] = Math.max(forwardSum[n]-2*x[n],(n==0)?0:forwardBackMax[n-1]);
        }
        long[] backwardSum = new long[N];
        backwardSum[N-1]=v[N-1];
        for(int n=N-2;n>=0;n--) backwardSum[n]= backwardSum[n+1]+v[n];
        long[] backwardMax = new long[N];
        long[] backwardBackMax = new long[N];
        for(int n=N-1;n>=0;n--){
        	backwardMax[n] = Math.max(backwardSum[n]-(C-x[n]) , (n==N-1)?0:backwardMax[n+1]);
        	backwardBackMax[n] = Math.max(backwardSum[n]-2*(C-x[n]) , (n==N-1)?0:backwardBackMax[n+1]);
        }
        
        long ans = Math.max(forwardMax[N-1], backwardMax[0]);
        for(int f=0;f<N-1;f++){
        	int b=f+1;
        	ans = Math.max(ans, forwardMax[f]+backwardBackMax[b]);
        	ans = Math.max(ans, forwardBackMax[f]+backwardMax[b]);
        }
        
        System.out.println(ans);

        
    }
}
