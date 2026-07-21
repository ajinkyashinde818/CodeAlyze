import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		char a = sc.next().charAt(0);
		char b = sc.next().charAt(0);
		sc.close();
		if(a < b) ou.println("<");
		else if(a > b) ou.println(">");
		else ou.println("=");
		ou.flush();
	}
}
