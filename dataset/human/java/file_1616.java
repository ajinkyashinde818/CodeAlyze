import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		char[] c=s.next().toCharArray();
		int[] b=new int[26];
		Arrays.fill(b,1);
		long r=0;
		for(int i=n-1;i>=0;--i){
			++b[c[i]-'a'];
			long t=1;
			for(int j=0;j<26;++j) {
				if(j!=c[i]-'a') {
					t*=b[j];
					t%=mod;
				}
			}
			r+=t;
			r%=mod;
		}
		System.out.println(r);
	}
	static int mod=1000000007;
}
