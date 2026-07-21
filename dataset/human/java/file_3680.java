import java.util.Scanner;
class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());}
	public static void main(String[]$){
		char a=s.next().charAt(0);
		char b=s.next().charAt(0);
		System.out.println(a<b?'<':a>b?'>':'=');
	}
}
