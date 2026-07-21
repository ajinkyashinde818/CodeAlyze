import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a=sc.nextInt(),b=sc.nextInt(),k=sc.nextInt();
		int min = Math.min(a, b);
		int cnt=0;
		int ans=0;

		for(int i=min;1<=i;i--) {

			if(a%i==0 && b%i==0) {
				cnt++;
				if(cnt==k) {
					ans=i;
				}
			}

		}
		System.out.println(ans);
	}
}
