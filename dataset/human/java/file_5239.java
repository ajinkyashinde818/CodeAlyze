import java.util.*;
import java.io.PrintWriter;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		String s = sc.next();
		int n = parseInt(sc.next());
		StringBuffer pre = new StringBuffer();
		StringBuffer post = new StringBuffer();
		int rev = 0;
		for (i = 0; i < n; i++) {
			if(sc.next().equals("1")) {
				rev++;
			} else {
				int pp = (parseInt(sc.next())+rev)%2;
				if(pp==1) {
					pre.append(sc.next());
				} else {
					post.append(sc.next());
				}
			}
		}
		StringBuffer ans = pre.reverse().append(s).append(post);
		if(rev%2==1) ans = ans.reverse();
		out.println(ans.toString());
	}
}
