import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		String s = sc.next() , t = sc.next();
		sc.close();
		char[] ss = s.toCharArray();
		char[] tt = t.toCharArray();
		Arrays.sort(ss);
		Arrays.sort(tt);
		s = "";
		t = "";
		for(char i : ss) s += i;
		for(char i : tt) t = i + t;
		String[] yo = {s , t};
		Arrays.sort(yo);
		if(s.equals(t)) ou.println("No");
		else if(yo[0] == s) ou.println("Yes");
		else ou.println("No");
		ou.flush();
	}
}
