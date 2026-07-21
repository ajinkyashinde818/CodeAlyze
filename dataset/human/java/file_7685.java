import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			int N = scan.nextInt();
			long K = scan.nextLong();
			int[]A = new int[N];
			int[]C = new int[N];
			Arrays.fill(C, -1);
			int count = 0;
			C[0]=count;;
			for(int i = 0;i<N;i++) {
				A[i] = scan.nextInt()-1;
			}
			int loop = 0;
			int loopcount = 0;
			int loopad = 0;
			
			int genzai = 0;
			
			while(true) {
				count++;
				
				if(C[A[genzai]]==-1) {
					C[A[genzai]]=count;
					genzai = A[genzai];
				}else {
					loop = C[genzai]-C[A[genzai]]+1;
					loopcount = C[A[genzai]];
					loopad = A[genzai];
					//System.out.println(genzai);
					//System.out.println(A[genzai]);
					//System.out.println(C[genzai]);
					//System.out.println(C[A[genzai]]);
					break;
				}

			}
			
			
			if(loopcount>K) {
				int gen  =0;
				
				while(K>0) {
					gen = A[gen];
					K--;
				}
				
				System.out.println(gen+1);
			}else {
				
				int gen  =loopad;
				
				K-=loopcount;
				
				K = K%loop;
				
				while(K>0) {
					gen=A[gen];
					K--;
				}
				
				System.out.println(gen+1);
				
				
				
			}
			
			/*
			for(int i = 0;i<N;i++) {
				System.out.print(C[i]);
				System.out.print(" ");
			}
			
			System.out.println();
			System.out.println(loop);
			System.out.println(loopcount);
			System.out.println(loopad);
			*/
			
			
			
			
			
			
			
			
		}
		
		
	}
		

}
