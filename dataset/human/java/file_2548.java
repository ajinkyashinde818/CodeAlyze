import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		String a =sc.next();
		String b=sc.next();



		char[] chara = a.toCharArray();
		char[] charb = b.toCharArray();

		for(int i=0;i<chara.length;i++) {
			for(int j=0;j<charb.length;j++) {

				if((int)chara[i]<(int)charb[j]) {
					System.out.print("Yes");
					return;
				}

			}
		}
		int aruhabetoA =0;
		int aruhabetoB =0;
		if(chara.length<charb.length) {
			for(int i=0;i<26;i++) {
				for(int j=0;j<chara.length;j++) {
					if(chara[j]==97+i) {
						aruhabetoA++;
					}
				}
				for(int j=0;j<charb.length;j++) {
					if(charb[j]==97+i) {
						aruhabetoB++;
					}
				}
				if(aruhabetoA>aruhabetoB) {
					System.out.print("No");
					return;
				}
				aruhabetoA =0;
				aruhabetoB =0;
			}

		}
		else {
			System.out.print("No");
			return;
		}
		System.out.print("Yes");

	}

}
