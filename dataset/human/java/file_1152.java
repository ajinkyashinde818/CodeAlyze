import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		long[] a = new long[n];
		long sum = 0;
		
		for(int i = 0; i < n; i++) {
			a[i] = in.nextInt();
            sum += a[i];
		}
        long x = a[0];
        long y = sum - a[0];
        //System.out.println(x + " " + y);
        long min = Math.abs(x - y);
		
		for(int i = 1; i < n-1; i++) {
			x += a[i];
			y -= a[i];
			//System.out.println(x + " " + y);
            if(Math.abs(x - y) < min) min = Math.abs(x - y);
		}
		
		System.out.println(min);
	}
}
