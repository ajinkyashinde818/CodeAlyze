import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	Scanner sc = new Scanner(System.in);
	int a; 

	public void syori(){
		for(int u=0;u<10;u++){
			int suji = sc.nextInt();
			a += suji;
		}
	}

	public void out(){
		System.out.println(a);
	}


	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Main m = new Main();

		m.syori();
		m.out();
	}
}
