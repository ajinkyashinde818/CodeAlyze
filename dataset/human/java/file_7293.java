import java.util.*;

public class Main {
	public static void main(String[] args) {
		int i,j;
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		i = s.length();
		boolean f = true;
		int ss = 0;
		String[] t = {"dream","dreamer","erase","eraser"};
		while(i>0) {
			boolean f2 = false;
			for(j=0;j<t.length;j++) {
				ss = i - t[j].length();
				if(ss>=0) {
					if(s.substring(ss, i).equals(t[j])) {
						f2 = true;
						i=ss;
						break;
					}
				}
			}
			if(!f2) {
				f = false;
				break;
			}
		}
		String ans=f?"YES":"NO";
		System.out.println(ans);
	}
}
