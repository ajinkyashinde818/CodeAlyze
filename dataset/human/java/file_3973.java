import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int mzd = 0;
		Scanner sc = new Scanner(System.in);
		String N = sc.nextLine();
		String A = sc.nextLine();
		String B = sc.nextLine();
		String C = sc.nextLine();
		
		int NI = Integer.parseInt(N);
		String[] AL = A.split(" ");
		int[] AI = new int[NI];
		for(int i=0; i<NI; i++) {
			AI[i] = Integer.parseInt(AL[i]);
		}
		String[] BL = B.split(" ");
		int[] BI = new int[NI];
		for(int i=0; i<NI; i++) {
			BI[i] = Integer.parseInt(BL[i]);
		}
		String[] CL = C.split(" ");
		int[] CI = new int[NI-1];
		for(int i=0; i<NI-1; i++) {
			CI[i] = Integer.parseInt(CL[i]);
		}
		
		int temp = 0;
		for(int i=0; i < NI; i++) {
			int crnt = AI[i];
			mzd += BI[crnt-1];
			
			if(temp == 0) {
				temp = crnt;
			}else {
				if(crnt == temp+1) {
					mzd += CI[temp-1];
				}
				temp = crnt;
			}
		}
		System.out.println(mzd);
		sc.close();
	}
}
