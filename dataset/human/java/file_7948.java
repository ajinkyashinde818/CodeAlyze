import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);
	int s;
	int[] a = new int[10];
	int b;
	int d = 0;
	
	public void kei(){
		for(b=0;b<a.length;b++){
			s = sc.nextInt();
			d = d + s;
		}
	}
	
	public void hyouji(){
			System.out.println(d);	
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Main go = new Main();
		go.kei();
		go.hyouji();

	}

}
