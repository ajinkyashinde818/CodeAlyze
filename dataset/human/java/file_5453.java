import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = Long.parseLong(sc.next());
//		String t = sc.next();
//		String buff="";
		//long b = Long.parseLong(sc.next());
		//int c = Integer.parseInt(sc.next());
		//int n = Integer.parseInt(sc.next());
		//long res=n;
		//int l = Integer.parseInt(sc.next());
		//int sum=0;
		//String s = sc.next();
		//String t = sc.next();
		//String b = sc.next();
		//int a = Integer.parseInt(sc.next());
		//String t = sc.next();

		if(a>=1200) {//a、e、i、o、u
			System.out.println("ARC");
		}else {
			System.out.println("ABC");
		}
		/*for(int i=0;i<t.length();i++) {
			if(t.substring(i,i+1).equals(",")) {
				buff+=" ";
			}else {
				buff+=t.substring(i, i+1);
			}
		}*/
		//System.out.println(buff);
	}
}
