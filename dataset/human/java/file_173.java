import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc =  new Scanner(System.in);
		int num = sc.nextInt();
		int min;
		long sum = 0;
		int  input = sc.nextInt();
		int minus = input > 0 ? 0: 1;
		input *= input > 0 ? 1: -1;
		min = input;
		sum += input;
		for(int i=1;i<num;i++) {
			input = sc.nextInt();
			if(input < 0) {
				++minus;
				input *= -1;
			}
			if(input < min)
				min = input;
			sum += input;
		}
			
		sc.close();
		System.out.println(minus%2==0?sum:sum-2*min);
	}
}
