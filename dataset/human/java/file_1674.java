import java.util.*;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		HashMap<Character,Integer> map = new HashMap<Character,Integer>();
		int dupflag = 0;
		for(int i=0;i<N;i++) {
			char c = S.charAt(i);
			if(map.containsKey(c)) {
				map.put(c, map.get(c)+1);
				dupflag = 1;
			}
			else map.put(c, 1);
		}
		long M = (long) (Math.pow(10, 9)+7);
		long a = 1;
		long b = 1;
		int sum = 0;
		long mult = 1;
		for(int i=0;i<N;i++) {
			a = (a*2) % M;
		}
		if(dupflag == 1) {
			for(int x : map.values()) {
				if(x==1) continue;
				sum += x;
				mult = (mult * (x+1)) % M;
				for(int i=0;i<x;i++) {
					b = (b*2) % M;
				}
			}
			if(b-mult <0) b = M+b-mult;
			else b = b-mult;
			for(int i=0;i<N-sum;i++) {
				b = (b*2)%M;
			}
		}
		else b = 0;
		//System.out.println(a + " " + b);
		if(a-1-b<0) System.out.println(M+a-1-b);
		else System.out.println(a-1-b);
	}
	
}
