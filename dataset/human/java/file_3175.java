import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		for(int i=0;i<str.length();i++){
			if(str.charAt(i)=='9'){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

}
