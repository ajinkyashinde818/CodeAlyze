import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int R=scan.nextInt();
		int a;
		a=100*(10-N);
		if(N>=10) {
			System.out.println(R);
		}
		else {
			System.out.println(R+a);
		}
	}
}
