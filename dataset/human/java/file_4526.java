import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int c = Integer.parseInt(sc.next());
		int yono = Math.min(b , c) * 2;
		b -= yono / 2;
		c -= yono / 2;
		if(a < c) yono += a + 1;
		else yono += c;
		yono += b;
		ou.println(yono);
		ou.flush();
	}
}
