import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		if(a+b>=c) {
			System.out.println(b+c);
		}else {
			int ans=0;
			ans=c-(a+b);
			int ans1=0;
			ans1=c-ans+b+1;
			System.out.println(ans1);
		}
		
	}

}
