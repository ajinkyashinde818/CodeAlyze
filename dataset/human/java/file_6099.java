import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int s = scan.nextInt();

		int x = 0;
		int y = 0;
		int z = s-(x+y);
		int yz = y+z;
		int count = 0;
		for(x=0;x<=k;x++) {
			for(y=0;y<=k;y++) {
					if(x+y<=s&&x+y+k>=s) {
						count++;
					}
				}
		}
		/*
		for(y=0;y<=k;y++) {
			for(z=0;z<=k;z++) {
					if(y+z==s) {
						count++;
					}
				}
		}*/

		if(s==k*3) {
			count =1;
		}
		System.out.println(count);
	}

}




/*import java.util.Scanner;

public class B051 {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int s = scan.nextInt();

		int x = 0;
		int y = 0;
		int z = 0;

		int countS = 0;
		int countK = 0;
		countS = (s + 2) * (s + 1) / 2; //0以上で合計がｓになる３つの数
		//System.out.println(countS);

		//あとは→ｋ以上を使っているのを排除
		for(x=k;x<=s;x++) {
			for(y=k;y<=s;y++) {
				for(z=k;z<=s;z++) {
					if(x+y==s-z) {
						countK++;
					}
				}
			}
		}

		int show = countS;
		if(s==3*k) {
			show=1;
		}




		System.out.println(show);
	}
}
*/
