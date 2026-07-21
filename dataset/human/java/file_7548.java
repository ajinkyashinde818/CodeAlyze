import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuffer str = new StringBuffer(sc.next());
		String S = str.reverse().toString();
		sc.close();
		System.out.println(solve(S));
	}
	
	public static String solve(String S) {
		int index = 0;
		while(index+5<S.length()) {
			if(S.substring(index,index+5).equals("esare")) {
				index += 5;
			}else if(S.substring(index,index+5).equals("maerd")) {
				index += 5;
			}else if(S.substring(index,index+6).equals("resare")) {
				index += 6;
			}else if(S.substring(index,index+7).equals("remaerd")) {
				index += 7;
			}else {
				return "NO";
			}
		}
		return "YES";
	}
}
