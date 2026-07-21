import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int k = scan.nextInt();
		scan.close();
		int num=0,cnt=0;
		int max = Math.min(a, b);
		for(int i=max; i>=1;i--) {
			if(a%i==0 && b%i==0) {
				cnt++;
				if(cnt==k) {
					num=i;
					break;
				}
			}
		}
		System.out.println(num);
	}
}
