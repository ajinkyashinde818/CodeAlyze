import java.util.*;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		long[] a = new long[n];
		long sum = 0;
		int minusCount = 0;
		
		for(int i=0; i<n; i++) {
		    a[i] = Long.parseLong(sc.next());
		    if(a[i] < 0) {sum += -a[i]; minusCount++; a[i] = -a[i];} 
		    else sum += a[i];
		}
    	
		Arrays.sort(a);
		if(minusCount % 2 == 0) minusCount = 0;
		else minusCount = 1;
		for(int i=0; i<minusCount; i++) {
		    sum -= a[i]*2;
		}
        
        System.out.println(sum);
	}
}
