import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n,m,k,a,b,c;
		String s=sc.next();
		s+=sc.next();
		char ch[]=s.toCharArray();
		if(ch[0]>ch[1]) {
			System.out.println(">");
		}else if(ch[0]==ch[1]) {
			System.out.println("=");
		}else {
			System.out.println("<");
		}


	}
}
