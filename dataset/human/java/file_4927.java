import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintWriter ou = new PrintWriter(System.out);
		long n = Long.parseLong(sc.next());
		sc.close();
		if(n % 2 != 0) ou.print(0);
		else{
			long yono = 0;
			n /= 2;
			long five = 5;
			while(n / five != 0){
				yono += n / five;
				five *= 5;
			}
			ou.print(yono);
		}
		ou.print("\n");
		ou.flush();
    }
}
