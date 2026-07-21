import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int n = sc.nextInt();
			if(n==0) break;
			int[] b = new int[n];
			for(int i=0;i<n;i++) b[i] = sc.nextInt();
			char[] a = sc.next().toCharArray();
			
			int j = 0;
			for(int i=0;i<a.length;i++){
				int p = 0;
				if(97<=(int)a[i] && (int)a[i]<=122) p = (int)a[i]-96;
				else p = (int)a[i]-38;
				p -= b[j];
				if(p<=0) p+=52;
				if(1<=p && p<=26) System.out.print((char)(p+96));
				else System.out.print((char)(p+38));
				j++;
				if(j==n) j=0;
			}
			System.out.println();
		}
	}
}
