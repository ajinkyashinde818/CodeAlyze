import java.util.*;

class Main{
public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	String s = sc.next();
	String t = sc.next();
	char[] sArray = s.toCharArray();
	char[] tArray = t.toCharArray();
	Arrays.sort(sArray);
	String sString = new String(sArray);
	Arrays.sort(tArray);
	char[] tReverse = new char[t.length()];
	for(int i = 0; i < t.length(); i++) {
		tReverse[i] = tArray[t.length() - 1 - i];
	}
	String tString = new String(tReverse);
	if(sString.compareTo(tString) < 0) {
		System.out.println("Yes");
	} else {
		System.out.println("No");
	}
}
}
