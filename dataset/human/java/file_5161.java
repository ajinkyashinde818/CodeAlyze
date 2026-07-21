import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder S = new StringBuilder(sc.next());
		int Q = sc.nextInt();
		int T = 0;
		int F = 0;

		StringBuilder addHead = new StringBuilder();
		StringBuilder addTail = new StringBuilder();
		boolean reverse = false;
		for(int i = 0; i < Q; i++) {
			 T = sc.nextInt();
			 if(T == 1) {
				 reverse = !reverse;//反転
				 continue;
			 }
			 F = sc.nextInt();
			 if((!reverse && F == 1) || (reverse && F == 2) ) {
				 addHead.insert(0, sc.next());
			 }else {
				 addTail.append(sc.next());
			 }
		}
		if(reverse) {
			S = addTail.reverse().append(S.reverse()).append(addHead.reverse());
		}else {
			S = addHead.append(S).append(addTail);
		}
		System.out.println(S.toString());
	}
}
