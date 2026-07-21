import java.util.*;
import static java.lang.Integer.*;
//import static java.lang.Long.*;
//import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		char[] s = sc.next().toCharArray();
		sc.close();
		Arrays.sort(s);
		out.println(s[0]=='a'&&s[1]=='b'&&s[2]=='c'?"Yes":"No");
	}
}
