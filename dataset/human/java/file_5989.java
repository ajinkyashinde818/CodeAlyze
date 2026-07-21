import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		char[] a = sc.next().toCharArray();
		Arrays.sort(a);
		if(a[0] == 'a' && a[1] == 'b' && a[2] == 'c') ou.println("Yes");
		else ou.println("No");
		ou.flush();
	}
}
