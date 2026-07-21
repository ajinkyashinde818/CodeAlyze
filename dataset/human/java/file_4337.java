import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
     	
      	int N = sc.nextInt();
      	 int[] A = new int[N + 1];
        int[] B = new int[N + 1];
        int[] C = new int[N + 1];
 
        for (int i = 1 ; i <= N ; i++) {
            A[i] = sc.nextInt();
        }
 
        for (int i = 1 ; i <= N ; i++) {
            B[i] = sc.nextInt();
        }
 
        for (int i = 1 ; i < N ; i++) {
            C[i] = sc.nextInt();
        }
 
      	int sum = 0;
      	for(int i=1;i<=N;i++){
          sum += B[A[i]];
          if(A[i-1] == A[i] - 1){
          	sum += C[A[i-1]];
          }
        } 
      System.out.println(sum);
      	
    }       
}
