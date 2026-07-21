import java.util.*;
import java.io.PrintWriter;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		long[][] dp=new long[s.length()+1][2];
		dp[s.length()][1]=11;
		for(int i=s.length()-1; i>=0; i--){
			
				dp[i][0]=Math.min(dp[i+1][0]+(s.charAt(i)-'0'),dp[i+1][1]+(s.charAt(i)-'0'));
				dp[i][1]=Math.min(dp[i+1][0]+11-(s.charAt(i)-'0'),dp[i+1][1]+9-(s.charAt(i)-'0'));
			
		}
		System.out.println(Math.min(dp[0][0],dp[0][1]));
	}
}
