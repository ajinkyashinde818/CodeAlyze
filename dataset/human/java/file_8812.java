import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		sc.close();
		
		int count = 0;
		for(int i=100;i>0;i--) {
			if(a%i==0 && b%i==0) {
				count++;
				if(count ==k) {
					System.out.println(i);
					return;
				}
			}
		}
	}

}
