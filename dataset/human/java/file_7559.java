import java.util.Scanner;

/**
 * https://abc049.contest.atcoder.jp/tasks/arc065_a
 */
public class Main {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		sc.close();
		
		String ans = "YES";
		int i=0;
		while(i<s.length){
			if(s[i]=='e'){
				if(!((++i)<s.length && s[i]=='r')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='a')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='s')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='e')){ ans = "NO"; break; }
				if((++i)<s.length && s[i]=='r') i++;
			}else if(s[i]=='d'){
				if(!((++i)<s.length && s[i]=='r')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='e')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='a')){ ans = "NO"; break; }
				if(!((++i)<s.length && s[i]=='m')){ ans = "NO"; break; }
				if((++i)<s.length &&s[i] =='e'){
					if(!((i+1)<s.length && s[i+1]=='r')) { ans = "NO"; break; }
					if((i+2)>=s.length || s[i+2]!='a'){
						i = i+2;
					}
				}
			}else{
				ans ="NO";
				break;
			}
		}
		System.out.println(ans);

	}

}
