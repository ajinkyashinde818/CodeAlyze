import java.util.Scanner;
 


//StringBuffer str = new StringBuffer(hoge1);
//String hoge2 = str.reverse().toString();
public class Main {
	private static Scanner sc = new Scanner(System.in);
	static void p(String ans) {System.out.println(ans);};
	static void p(int ans) {System.out.println(ans);};
	static void p(long ans) {System.out.println(ans);};
	static String eikomoji[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
	
	
	public static void main(String[] args) {
	int N =sc.nextInt();
	int R =sc.nextInt();
	int ans=0;
	
	if(N<10) {
		p(R+100*(10-N));
	}else {
		p(R);
		//N-  100*10-k = R
	}
	
	
	
	}
}
