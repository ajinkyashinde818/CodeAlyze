import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		List<String> l = new ArrayList<>();
		l.add("dream");
		l.add("dreamer");
		l.add("erase");
		l.add("eraser");
		

		boolean dp[] = new boolean[s.length()+1];
		dp[0] = true;
		for(int i=0;i<=s.length();i++) {			
			for(String t : l) {
				int len = t.length();
				if(i-len>=0) {
					if(dp[i-len]==false)continue;
					if(s.substring(i-len, i).equals(t)) dp[i]=true;
				}
			}
		}
		if(dp[s.length()]==true)System.out.println("YES");
		else System.out.println("NO");
	}
}
