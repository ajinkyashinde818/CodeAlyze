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
		int k = parseInt(sc.next());
		int s = parseInt(sc.next());
		sc.close();
		int cnt=0;
		for (i = 0; i <= k; i++) {
			for (j = 0; j <= k; j++) {
				if(0<=s-(i+j) && s-(i+j)<=k)cnt++;
			}
		}
		out.println(cnt);
	}
}
