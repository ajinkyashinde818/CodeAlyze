import java.util.*;


public class Main{
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		long ans=1;
		int []map=new int[26];
		for (int i=0;i<n;i++) {
			map[s.charAt(i)-'a']++;
		}
		for(int i=0;i<26;i++) {
			ans=ans*(map[i]+1)%1000000007;
		}
		ans--;
		int res=(int)ans;
		sc.close();
        System.out.println(res);	
	}
	

}
