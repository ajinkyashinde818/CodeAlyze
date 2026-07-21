import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			int K = scan.nextInt();
			int N = scan.nextInt();
			
			int[] A = new int[N];
			for(int i = 0;i<N;i++) {
				A[i] = scan.nextInt();
			}
			
			int maxdist = 0;
			int maxnum = 0;
			
			for(int i = 0;i<N;i++) {
				if(i == N-1) {
					int dist = K-A[i]+A[0];
					if(maxdist<dist) {
						maxdist = dist;
						maxnum = i;
					}
				}else {
					int dist = A[i+1]-A[i];
					if(maxdist<dist) {
						maxdist = dist;
						maxnum = i;
					}
				}
			}
			
			//System.out.println(maxnum);
			
			if(maxnum == (N-1)) {
				System.out.println(A[maxnum]-A[0]);
			}else {
				int a = A[maxnum];
				int b = K-A[maxnum+1];
				System.out.println(a+b);
			}
			
			
			
			
			
			
		}
		
		
	}
		

}
