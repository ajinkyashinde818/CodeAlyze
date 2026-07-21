import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		if (n % 10 == 9) {
			System.out.println("Yes");
		} else if (n / 10 % 10 == 9) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		
		
		
		
	}
}
