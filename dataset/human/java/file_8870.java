import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(), b = sc.nextInt(), k = sc.nextInt();
		int [] Array = new int [50];
		int counter = 0;
		for(int i = 1; i <= a && i <= b; i++) {
			if(a % i == 0 && b % i == 0) {
				Array[counter] = i;
				counter++;
			}
		}
		System.out.println(Array[counter - k]);
		sc.close();
	}

}
