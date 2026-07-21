import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		sc.close();
		String[] array = str.split(" ");
		int x=0,y=0;

		if(array[0].equals("A")) {
			x = 10;
		}
		if(array[0].equals("B")) {
			x = 11;
		}
		if(array[0].equals("C")) {
			x = 12;
		}
		if(array[0].equals("D")) {
			x = 13;
		}
		if(array[0].equals("E")) {
			x = 14;
		}
		if(array[0].equals("F")) {
			x = 15;
		}


		if(array[1].equals("A")) {
			y = 10;
		}
		if(array[1].equals("B")) {
			 y = 11;
		}
		if(array[1].equals("C")) {
			y = 12;
		}
		if(array[1].equals("D")) {
			 y = 13;
		}
		if(array[1].equals("E")) {
			 y = 14;
		}
		if(array[1].equals("F")) {
			 y = 15;
		}

		if(x<y) {
			System.out.print("<");
		}
		if(x>y) {
			System.out.print(">");
		}
		if(x==y) {
			System.out.print("=");
		}


	}
}
