import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int count=0;
		int k = sc.nextInt();
		int s = sc.nextInt();
		for(int i=0;i<=k;i++) {
			for(int w=0;w<=k;w++) {
				if(s-i-w>=0 && s-i-w<=k) {
					count++;
				}
			}
		}
		System.out.print(count);
	}
}
