import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sc1 = sc.nextInt();
		int[] ary = new int[sc1];
		for(int i = 0; i < ary.length; i++) {
			ary[i] = sc.nextInt();
		}
		Numbers n = new Numbers(ary);
		n.disp();
	}
}
class Numbers{
	int numbers[];
	boolean isMinusOdd;
	int minIdx;
	Numbers(int[] ary){
		numbers = ary;
		isMinusOdd = false;
		for(int i = 0; i < numbers.length; i++) {
			if(numbers[i] < 0) {
				isMinusOdd = !isMinusOdd;
			}
			if(Math.abs(numbers[minIdx]) > Math.abs(numbers[i])) {
				minIdx = i;
			}
		}
	}
	void disp() {
		long point = 0;
		for(int i = 0; i < numbers.length; i++) {
			point += Math.abs(numbers[i]);
		}
		if(isMinusOdd) {
			point -= 2 * Math.abs(numbers[minIdx]);
		}
		System.out.println(point);
	}
}
