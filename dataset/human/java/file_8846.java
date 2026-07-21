import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		int a = Integer.parseInt(sc.next());
		int b = Integer.parseInt(sc.next());
		int k = Integer.parseInt(sc.next());
		sc.close();
		int cou = 0;
		boolean che = true;
		for(int i = a ; i > 0 && che ; i--){
			if(a % i == 0 && b % i == 0){
				cou++;
			}
			if(k == cou){
				che = false;
				ou.print(i + "\n");
			}
		}
		ou.flush();
    }
}
