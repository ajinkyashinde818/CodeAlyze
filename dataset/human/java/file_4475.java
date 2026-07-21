import java.util.Scanner;

public class Main{
	static public void  main(String[] args){
		Scanner scan = new Scanner(System.in);

		long a = scan.nextLong();
		long b = scan.nextLong();
		long c = scan.nextLong();
		if(c <= a + b) {
			System.out.println(b+c);
		}else{
			long _c = (a + b + 1 <= c)?  a + b + 1 : c;
			System.out.println(b + _c);
		}
	}
}
