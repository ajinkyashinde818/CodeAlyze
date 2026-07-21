import java.util.Arrays;
import java.util.Scanner;

public class Main{
	 public static void main(String[] args) {
		 char [] station = new char[52];
		 for(int i=0;i<26;i++) {
			 station[i] = (char)('A'+i);
		 }
		 for(int i=0;i<26;i++) {
			 station[i+26] = (char)('a'+i);
		 }
		 Arrays.sort(station);
		 //for(int i=0;i<52;i++) System.err.print(station[i]);
	   
		 try (Scanner sc = new Scanner(System.in)) {
	        while(true) {
	            int n = sc.nextInt();
	            if(n==0) break;
	            int[] key = new int[n];
	            for(int i=0;i<n;i++) {
	            	key[i] = sc.nextInt();
	            }
	            String str = sc.next();
	            String ans = "";
	            for(int i=0;i<str.length();i++) {
	            	char c = str.charAt(i);
	            	int b = key[i%n];
	            	int x = Arrays.binarySearch(station, c);
	            	if(x-b>=0) {
	            		ans += station[x-b];
	            	}else {
	            		ans += station[x-b+52];
	            	}
	            }
	            System.out.println(ans);
	        }
	    }
	 }
}
