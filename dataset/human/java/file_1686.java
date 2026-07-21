import java.util.*;

public class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        char[] chars = sc.next().toCharArray();
        
        long[] map = new long[26];
		for (char c : chars) {
			map[c-'a']++;
		}
		
		long sum = 1;
		for (long count : map) {
			sum = sum * (count+1L) % 1_000_000_007L;
		}
		
		System.out.println(sum - 1);
    }
}
