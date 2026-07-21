import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);

	int s;
	int [] a = new int[10];
	int h;
	int w = 0;

	public void main(){
		for(h = 0;h < a.length;h++){
			s = sc.nextInt();
			w = w + s;
		}
	}

	public void hyouji(){
		System.out.println(w);
	}

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Main dou = new Main();
		dou.main();
		dou.hyouji();
	}

}
