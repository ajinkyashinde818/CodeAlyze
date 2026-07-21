import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s=scan.next();
		String t=scan.next();
		scan.close();
		char sc[] = s.toCharArray();
		char st[] = t.toCharArray();

		Arrays.sort(sc);
		Arrays.sort(st);
		int min=Math.min(st.length, sc.length);
		int check=0;
		int cnt=0;
		for(int i=0;i<min;i++) {

			if(sc[i] < st[st.length-1-i]) {
				check=1;
				break;
			}
			if(sc[i] == st[st.length-1-i])cnt++;
			if(cnt==min)check=-1;
		}
		if(check==-1) {
			if(sc.length < st.length)check=1;
			else check=0;
		}

		System.out.println((check==1)? "Yes":"No");
	}

}
