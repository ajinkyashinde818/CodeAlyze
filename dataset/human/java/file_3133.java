import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner stdin = new Scanner(System.in);	
		int n = stdin.nextInt();
		if(n/10%9==0||n%10%9==0&&n%10!=0) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}

}
