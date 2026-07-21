import java.util.*;
class Main {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String s1 = sc.next();
	String s2 = sc.next();

	char[] c1 = s1.toCharArray();
	char[] c2 = s2.toCharArray();

	Arrays.sort(c1);
	Arrays.sort(c2);

	char ch1, ch2;
	int max = Math.min(c1.length, c2.length);
	for(int i = 0; i<max; i++) {
	    ch1 = c1[i];
	    ch2 = c2[c2.length-1-i];
	    if(ch1<ch2) {
		System.out.println("Yes");
		return;
	    }
	    if(ch1>ch2) {
		System.out.println("No");
		return;
	    }
	}
	if(c1.length<c2.length) {
	    System.out.println("Yes");
	}else {
	    System.out.println("No");
	}



    }
}
