import java.util.*;


public class Main {
	public static void main (String[] args){
		Scanner sc =  new Scanner(System.in);
		String S = sc.next();
		StringBuffer sb1 = new StringBuffer();
		StringBuffer sb2 = new StringBuffer();
		int Q = sc.nextInt();
		//int sum = 0;
		boolean R = false;
		for(int i = 0; i < Q; i++) {
			int q = sc.nextInt();
			if(q == 1) {
				R = !R;
			}
			else if(q == 2) {
				int F = sc.nextInt();
				String C = sc.next();
				if(F == 1 && R == false) {
					sb1.append(C);
				}					
				else if(F == 2 && R==true){
					sb1.append(C);
				}
				else {
					sb2.append(C);
				}
			}
		}
		StringBuffer sb = new StringBuffer();
		sb1.reverse();
		sb.append(sb1);
		sb.append(S);
		sb.append(sb2);
		if(R == true) {
			sb.reverse();
		}
		System.out.println(sb.toString());
	}	
}
