import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		int Q = sc.nextInt();
		int[] T = new int[Q];
		int[] F = new int[Q];
		char[] C = new char[Q];
		for(int i = 0; i < Q; i++) {
			T[i] = sc.nextInt();
			if(T[i] == 2) {
				F[i]= sc.nextInt();
				C[i]= (sc.next()).charAt(0);				
			}
		}
		
		StringBuilder s = new StringBuilder();
		StringBuilder sStart = new StringBuilder();
		s.append(S);
		boolean rev = false;
		for(int i = 0; i < Q; i++) {
			if(T[i] == 2) {
				if(F[i] == 1) {
					if(!rev) sStart.append(C[i]);
					else s.append(C[i]);
				}else {
					if(!rev) s.append(C[i]);
					else sStart.append(C[i]);
				}
			}else {
				rev = !rev ;
			}
		}
		
		if(rev) {
			s.reverse();
			S = s.toString() + sStart.toString();
		}else {
			sStart.reverse();
			S = sStart.toString() + s.toString();
		}
		System.out.println(S);
		

	}
}
