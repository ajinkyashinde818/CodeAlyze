import java.util.*;
//import static java.lang.Integer.*;
//import static java.lang.Long.*;
//import static java.lang.Math.*;
import static java.lang.System.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(in);
		char[] x = sc.next().toCharArray();
		char[] y = sc.next().toCharArray();
		sc.close();
		out.println(x[0]<y[0]?"<":x[0]>y[0]?">":"=");
	}
}
