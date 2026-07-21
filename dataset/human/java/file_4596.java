import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner stdin = new Scanner( System.in);
		int  a,b,c;
		int i=0,j=0;
		c =stdin.nextInt();
		b =stdin.nextInt();
		a =stdin.nextInt();
		if(b+c+1>a) {
		System.out.print(b+a);
	}else {
		System.out.print(b*2+c+1);
		}
	}
}
