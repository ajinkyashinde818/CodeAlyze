import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String S = in.next();
		char[] c = {' ',' ',' '};
		c[0] = S.charAt(0);
		c[1] = S.charAt(1);
		c[2] = S.charAt(2);
		Arrays.sort(c);
		if(c[0] == 'a' &&c[1] == 'b' &&c[2] == 'c')System.out.println("Yes");
		else System.out.println("No");
	}
}
