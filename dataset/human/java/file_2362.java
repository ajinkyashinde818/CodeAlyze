import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		
		char[] s=S.toCharArray();
		
		int n = s.length;
		char[] s2 = new char[n-8];
		
		for(int i=0;i<n-8;i++) {
			s2[i]=s[i];
		}
		
		S=String.valueOf(s2);
		
		System.out.println(S);

	}


}
