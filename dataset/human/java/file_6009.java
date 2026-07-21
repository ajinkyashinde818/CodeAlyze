import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		//String t = sc.next();
		//String g = sc.next();
		//long n = sc.nextLong();
		//long m = sc.nextLong();
		//long k = sc.nextLong();
		//long l = sc.nextLong();
		long count=0;

		/*for(int i=1;i<10000;i++) {
			if(n<500*(i+1)) {
				count=i;
				break;
			}
		}*/
		if(s.substring(0,1).equals(s.substring(1,2))||s.substring(1,2).equals(s.substring(2,3))||s.substring(0,1).equals(s.substring(2,3))) {
			System.out.println("No");
		}else{
			System.out.println("Yes");
		}
		//System.out.println((int)Math.ceil((n+m)/2.0));
		//System.out.println(s.substring(0,1)+t.substring(1,2)+g.substring(2,3));
	}
}
