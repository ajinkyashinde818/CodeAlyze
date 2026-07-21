import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String s = in.next();
		String t = in.next();
		char[] S = new char[s.length()];
		char[] T = new char[t.length()];
		for(int i = 0; i < s.length(); i++)S[i] = s.charAt(i);
		for(int i = 0; i < t.length(); i++)T[i] = t.charAt(i);
		Arrays.sort(S);
		Arrays.sort(T);
		String sS = "";
		for(int i = 0; i < s.length(); i++)sS += S[i];
		String sT = "";
		for(int i = 0; i < t.length(); i++)sT += T[t.length()-i-1];
		if(sS.compareTo(sT)<0)System.out.println("Yes");
		else System.out.println("No");
	}
}
