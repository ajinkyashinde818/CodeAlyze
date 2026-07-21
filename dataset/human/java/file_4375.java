import java.util.Scanner;
     
public class Main {
    	
    private final static Scanner sc = new Scanner(System.in);
    	
    public static void main(String[] arg) {
    	int N = sc.nextInt();
    	int [] A = new int[N];
        for(int i =0; i < N; i++) {
        	A[i] = sc.nextInt();
        } 
         int sum = 0;
         for(int i =0; i < N; i++) {
             sum += sc.nextInt();
           	
         } 
         int [] C = new int[N-1];
         for (int i = 0; i < N-1; i++) {
            C[i] = sc.nextInt();
         }
         for(int i = 0; i < N-1; i++) {
         	if( (A[i]+1) == A[i+1]) {
            	sum += C[A[i]-1];
          	}
       	 }
          	System.out.println(sum);
    	}
    }
