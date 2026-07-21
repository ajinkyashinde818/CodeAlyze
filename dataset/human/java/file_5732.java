import java.util.*;



public class Main{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char c[] = s.toCharArray();
		int a = 0;
		int b = 0;
		int d = 0;
		
		for(int i = 0; i < 3; i ++) {
			if(c[i] == 'a') {
				a ++;
			}else if(c[i] == 'b') {
				b ++;
			}else if(c[i] == 'c') {
				d ++;
			}
		}
		if(a == 1 && b == 1 && d == 1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
