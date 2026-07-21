import java.util.HashMap;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		HashMap <Character,Integer> units = new HashMap<>();
		units.put('m',1000);
		units.put('c',100);
		units.put('x',10);
		units.put('i',1);
		
		HashMap <Integer,Character> uni = new HashMap<>();
		uni.put(1000,'m');
		uni.put(100,'c');
		uni.put(10,'x');
		uni.put(1,'i');
		
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			char [] s1 = sc.next().toCharArray();
			char [] s2 = sc.next().toCharArray();
			int d1 = 0;
			int d2 = 0;
			for(int j=0;j<s1.length;j++) {
				if('2'<=s1[j] && s1[j]<='9') {
					int a = s1[j] - '0';
					char c = s1[j+1];
					d1 += a*(units.get(c));
					j++;
				}else {
					d1 += units.get(s1[j]);
				}
			}
			for(int j=0;j<s2.length;j++) {
				if('2'<=s2[j] && s2[j]<='9') {
					int a = s2[j] - '0';
					char c = s2[j+1];
					d2 += a*(units.get(c));
					j++;
				}else {
					d2 += units.get(s2[j]);
				}
			}
			int sum = d1 + d2;
			String ans = "";
			for(int j=1000;j>=1;j /= 10) {
				int b = sum/j;
				if(b>=2) {
					ans += b;
					ans += uni.get(j);
				}else if(b == 1) {
					ans += uni.get(j);
				}
				sum -= b*j;
			}
			System.out.println(ans);
		}
		
	}
}
