import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String a=sc.next();
		int ax=Integer.parseInt(a,16);

		String b=sc.next();
		int bx=Integer.parseInt(b,16);

		if(ax>bx) {
			System.out.println(">");
		}

		else if(ax==bx) {
			System.out.println("=");
		}

		else if(ax<bx) {
			System.out.println("<");
		}
	}
}
