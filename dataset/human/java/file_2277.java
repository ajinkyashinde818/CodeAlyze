import java.util.*;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
	
	public static HashMap<String,String> map = new HashMap<>();


	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int e = sc.nextInt();
		int y = sc.nextInt();
		if(e == 0) {
			if(y >= 1868 && y <= 1911) System.out.println("M" + (y - 1867));
			else if(y >= 1912 && y <= 1925) System.out.println("T" + (y - 1911));
			else if(y >= 1926 && y <= 1988) System.out.println("S" + (y - 1925));
			else if(y >= 1989 && y <= 2016) System.out.println("H" + (y - 1988));
		} else if(e == 1) {
			System.out.println((y + 1867));
		} else if(e == 2) {
			System.out.println((y + 1911));
		} else if(e == 3) {
			System.out.println((y + 1925));
		} else if(e == 4) {
			System.out.println((y + 1988));
		}
	}
}
