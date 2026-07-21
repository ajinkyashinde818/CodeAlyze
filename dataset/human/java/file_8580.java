import java.util.*;

public class Main {
public static void main(String[] args) {
		
		Scanner keyboard = new Scanner(System.in); 
		
		int A  = keyboard.nextInt();
		int B  = keyboard.nextInt();
		int K  = keyboard.nextInt();
		
		int N = A < B ? A : B;
		int[] ans = new int[N+1];
		
		for(int i=1; i<N+1; i++){
			int a = A % i;
			int b = B % i;
			if(a == 0 && b == 0){
				ans[i] = i;
			}
		}
		
		Arrays.sort(ans); 
		for(int j=N; j>=0; j--){
			if(N-j +1 == K){
				System.out.println(ans[j]) ;
				break;
			}
		}
		keyboard.close();	
	}
}
