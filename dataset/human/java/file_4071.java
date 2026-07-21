import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner scan = new Scanner(System.in);
		
      	int N = scan.nextInt();
      	int A[] = new int[N];
      	int B[] = new int[N];
      	int C[] = new int[N - 1];
      
		for(int i = 0; i < N; i++){
			A[i] = scan.nextInt();
        }
		for(int i = 0; i < N; i++){
			B[i] = scan.nextInt();
        }
		for(int i = 0; i < N - 1; i++){
			C[i] = scan.nextInt();
        }
      	
      	int sum = 0;
      	for(int i = 0; i < N; i++){
        	sum = sum + B[A[i] - 1];
          	if(i + 1 < N) {
            	if(A[i + 1] - A[i] == 1) {
                	sum = sum + C[A[i] - 1];
                }
            }
        }
     	System.out.println(sum);
    }
}
