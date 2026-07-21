import java.util.*;

public class Main{
    public static void main(String[] args){
	Scanner kbd = new Scanner(System.in);

	char[] m = {'m', 'c', 'x', 'i'};
	int[] s = {1000, 100, 10, 1};

	int count = kbd.nextInt();

	for(int c=1; c<=count; c++) {
	    String s1 = kbd.next();
	    String s2 = kbd.next();
	    
	    int a1 = toInt(s1, m, s);
	    int a2 = toInt(s2, m, s);
	    // System.out.println(a1 + " " + a2);
	    String res = toMCXI(a1+a2, m, s);
	    System.out.println(res);
	}
    }

    static int toInt(String st, char[] m, int[] s) {
	int pt = 0;
	int res = 0;
	char c = st.charAt(pt);

	for(int i=0; i<m.length; i++) {
	    int k = 1;
	    if(c>='2' && c<='9'){
		k *= (c-'0');
		c = st.charAt(++pt);
	    }

	    while(c != m[i]) i++;
	    res += k*s[i];
	    if(++pt >= st.length()) break;
	    c = st.charAt(pt);
	}
	return res;
    }

    static String toMCXI(int res, char[] m, int[] s) {
	String c = "";
	int d = res;
	for(int i=0; i<4; i++) {
	    if(d/s[i] > 1){
		c += d/s[i];
		c += m[i];
	    }
	    if(d/s[i] == 1) {
		c += m[i];
	    }
	    d = d - d/s[i]*s[i];
	}
	return c;
    }
}
