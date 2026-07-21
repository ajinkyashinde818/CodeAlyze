import java.util.Scanner;
public class Main{
	public static void main(String[]args) {
		Scanner input=new Scanner(System.in);
		int x;
		do {
			x=input.nextInt();
		}while(x<1||x>3000);
		if(x<1200) {
			System.out.println("ABC");
		}else{
			System.out.println("ARC");
		}
	}
}
