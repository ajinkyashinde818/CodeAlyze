import static java.lang.System.in;
import static java.lang.System.out;

import java.util.*;


public class Main {
	Scanner sc = new Scanner(in);
	
	int calc(String s) {
		char[] m = s.toCharArray();
		int n = m.length;
		int i = 0;
		int ans = 0;
		int pre = 1;
		while (i < n) {
			switch(m[i]) {
			case 'm':
				ans += pre*1000;
				i++;
				pre = 1;
				break;
			case 'c':
				ans += pre*100;
				i++;
				pre = 1;
				break;
			case 'x':
				ans += pre*10;
				i++;
				pre = 1;
				break;
			case 'i':
				ans += pre;
				i++;
				pre = 1;
				break;
			default:
				pre = Integer.parseInt(String.valueOf(m[i]));
				i++;
				break;
			}
		}
		return ans;
	}
	
	String calc(int n) {
		int m, c, x, i;
		m = n/1000;
		c = (n-1000*m)/100;
		x = (n-1000*m-100*c)/10;
		i = n-1000*m-100*c-10*x;
		
		String ans = "";
		if (m > 1)
			ans += String.format("%dm", m);
		else if (m == 1)
			ans += "m";
		
		if (c > 1)
			ans += String.format("%dc", c);
		else if (c == 1)
			ans += "c";
		
		if (x > 1)
			ans += String.format("%dx", x);
		else if (x == 1)
			ans += "x";
		
		if (i > 1)
			ans += String.format("%di", i);
		else if (i == 1)
			ans += "i";
		
		return ans;
	}
	
	void run() {
		int n = Integer.parseInt(sc.next());
		String a, b;
		
		for (int i = 0; i < n; i++) {
			a = sc.next();
			b = sc.next();
			out.println(calc(calc(a)+calc(b)));
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main().run();
	}
}
