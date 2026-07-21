import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
      	int N = sc.nextInt();
        int[] A = new int[N]; 
      	for(int i = 0; i < N; i++){
        	A[i] = sc.nextInt();
        }
      	int[] ad = new int[N]; 
      	for(int j = 0; j < N-1; j++){
        	ad[j] = A[j+1] - A[j];
        }
		ad[N-1] = K - A[N-1] + A[0];
      
      	Integer max = ad[0];
      	for(int k = 1; k < N; k++){
          if(max < ad[k]){
            max = ad[k];
          }
        }
      	int ii = (K-max);
		System.out.println(ii);
	}
}
