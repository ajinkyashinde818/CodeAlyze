import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		scan.close();
		char[] sc=s.toCharArray();
		char[] c= {'a','b','c'};
		int cnt[]= {0,0,0};
		for(int i=0;i<s.length();i++) {
			for(int j=0;j<s.length();j++) {
				if(sc[i]==c[j]) {
					cnt[j]++;
				}
			}
		}
		int check=1;
		for(int i=0;i<s.length();i++)if(cnt[i]!=1) check=0;
		System.out.println((check==1)? "Yes":"No");
	}
}
