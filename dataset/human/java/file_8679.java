import java.util.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		int max = a;
		if( a < b ) {
			max = b;
		}
		int flag = 0;
		for(int i = max; i > 0; i--) {
			if( a%i == 0 && b%i == 0 ) {
				flag++;
			}
			if(flag == k) {
				System.out.println(i);
				break;
			}
		}
	}
}
