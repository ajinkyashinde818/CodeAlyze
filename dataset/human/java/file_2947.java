import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Math.*;
import static java.lang.System.*;

import java.io.PrintWriter;

public class Main {
	public static void main(String[] args) {
		int i=0,j=0,k=0;
		Scanner sc = new Scanner(in);
		int n = parseInt(sc.next());
		int m = parseInt(sc.next());
		int a = 0;
		int b = 0;
		HashSet<Integer> m1 = new HashSet<>();
		HashSet<Integer> m2 = new HashSet<>();
		for(i=0;i<m;i++) {
			a = parseInt(sc.next());
			b = parseInt(sc.next());
			if(a==1) m1.add(b);
			if(b==n) m2.add(a);
		}
		sc.close();
		boolean f=false;
		for (Integer ii:m1) {
			if(m2.contains(ii)) {
				f = true;
				break;
			}
		}
		out.println(f?"POSSIBLE":"IMPOSSIBLE");
	}
}
