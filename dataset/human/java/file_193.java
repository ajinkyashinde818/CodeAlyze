import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			
			int N = scan.nextInt();
			int[]A = new int[N];
			for(int i = 0;i<N;i++)A[i] = scan.nextInt();
			
			
			Arrays.sort(A);
			
			
			for(int i = 0;i<N-1;i++) {
				if(A[i]<0&&A[i+1]<0) {
					A[i]=-1*A[i];
					A[i+1]=-1*A[i+1];
				}else if(A[i]<0&&A[i+1]==0) {
					A[i]=-1*A[i];
				}else if(A[i]<0&&A[i+1]>0) {
					if(A[i]+A[i+1]<-A[i]-A[i+1]) {
						A[i]=-1*A[i];
						A[i+1]=-1*A[i+1];
					}
				}
	
			}
			
			
			
			long goukei = 0;
			
			for(int i = 0;i<N;i++) {
				goukei+=A[i];
			}
			
			System.out.println(goukei);
			
			
			
			
			
			
		}
		
		
	}
		

}
