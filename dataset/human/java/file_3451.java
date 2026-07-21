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
		int x = 0;
		String a = "No";
		

for(int i=2;i > 0;i--)
{
x=n%10;
if (x == 9) {
	a = "Yes";
}

n=n/10;

}
		System.out.println(a);
		
	}
}
