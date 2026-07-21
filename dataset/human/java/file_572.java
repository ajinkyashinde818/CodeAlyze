import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int N= sc.nextInt(),R=sc.nextInt();
		if(N>=10) {
			System.out.println(R);
		}else {
			System.out.println(R+100*(10-N));
		}

	}

}
