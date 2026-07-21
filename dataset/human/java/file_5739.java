import java.io.File;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;

public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		String S = sc.next();
		int a = 0; int b = 0; int c = 0;
		for(int i = 0; i < 3; i++){
			char cc = S.charAt(i);
			if(cc == 'a') a++;
			if(cc == 'b') b++;
			if(cc == 'c') c++;
			
		}
		
		System.out.println((a == b && b == c)?"Yes":"No");
	}
}
