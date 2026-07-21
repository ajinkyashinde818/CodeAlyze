import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		while(N>0) {
			if(N%10 == 9) {
				System.out.println("Yes");
				System.exit(0);
			}
			N/=10;
		}
		
		System.out.println("No");
	}

}
