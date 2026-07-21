import java.util.Scanner;

public class Main {
	public void output(){
		Scanner scan = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 10; i++){
			int x = scan.nextInt();
			sum += x;
		}
		System.out.println(sum);
	}
	
	public static void main(String[] args){
		Main m = new Main();
		m.output();
	}

}
