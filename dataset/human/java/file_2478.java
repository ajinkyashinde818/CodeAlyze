import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.util.*;
import java.io.*;

public class Main {
	
	int[] v = {1000, 100, 10, 1};
	String s = "mcxi";
	
	void run() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=0;t<T;t++) {
			String str1 = sc.next(), str2 = sc.next();
			System.out.println( int2str(str2int(str1) + str2int(str2)) );
		}
	}
	
	int str2int(String str) {
		int ret = 0, val=1;
		for(int i=0;i<str.length();i++) {
			if( '0' <= str.charAt(i) && str.charAt(i) <= '9')
				val = str.charAt(i) - '0';
			for(int j=0;j<s.length();j++) if(s.charAt(j) == str.charAt(i)){
				ret += val * v[j]; val = 1;
			}
		}
		return ret;
	}
	
	String int2str(int val) {
		String str = "";
		for(int i=0;i<v.length;i++) if(val / v[i] > 0){
			if(val/v[i] != 1) str += (val/v[i]);
			str += s.charAt(i);
			val %= v[i];
		}
		return str;
	}

	void debug(Object... os) {
		System.err.println(Arrays.deepToString(os));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
