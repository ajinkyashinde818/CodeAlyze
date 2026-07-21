import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		StringBuilder sb2 = new StringBuilder();
		sb.append(sc.next());
		int q = sc.nextInt();
		int reverse = 0;

		for(int i = 0; i < q; i++) {
			int n = sc.nextInt();
			switch(n) {
			case 1:
				reverse = 1 - reverse;
				break;
			case 2:
				if(sc.nextInt() - 1 == reverse){
					sb2.append(sc.next());
				}else {
					sb.append(sc.next());
				}
				break;
			}
		}
		if(reverse == 1) System.out.println(sb.reverse().toString() + sb2.toString());
		else System.out.println(sb2.reverse().toString() + sb.toString());
		sc.close();
	}
}
