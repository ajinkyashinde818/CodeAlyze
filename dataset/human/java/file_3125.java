import java.util.Scanner;

class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int a=sc.nextInt();
		int b=sc.nextInt();
		for(int i=1;i<=100000;i++) {
			if(i*a>=b) {
				System.out.println(i);
				break;
			}
		}
	}
	}
