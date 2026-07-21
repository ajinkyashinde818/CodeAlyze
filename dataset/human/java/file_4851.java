import java.util.*;
 
public class Main { 
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long twoCount = 0;
		long fiveCount = 0;
		long tmp = n;
		if(n%2 == 1){
			System.out.println(0);
			return;
		}
		while(tmp > 0){
			twoCount += tmp/2;
			tmp = tmp/2;
		}
		tmp = n;
		fiveCount += tmp/(5*2);
		tmp = tmp/(5*2);
		while(tmp > 0){
			fiveCount += tmp/5;
			tmp = tmp/5;
		}
		System.out.println(Math.min(twoCount, fiveCount));
	}
}
