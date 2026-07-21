import java.util.*;
import static java.lang.System.*;

public class Main {

	Scanner sc = new Scanner(in);
	
	void run() {
		int t = sc.nextInt();
		for (int z = 0; z < t; z++) {
			int n = sc.nextInt();
			String s = sc.next();
			int count1 = 0, count2 = 0;
			count1 += (s.charAt(0) == 'Y') ? 1 : 0;
			count1 += (s.charAt(2*n-1) == 'Y') ? 1 : 0;
			for (int i = 1; i < 2*n-2; i += 2) {
				if (s.charAt(i) == 'Y' || s.charAt(i+1) == 'Y')
					count1++;
			}
			for (int i = 2*n+1; i < 4*n-2; i += 2) {
				if (s.charAt(i) == 'Y' || s.charAt(i+1) == 'Y')
					count2++;
			}
			if (s.charAt(2*n) == 'Y') count2++;
			if (s.charAt(4*n-1) == 'Y') count2++;
			if (count2 == 0) {
				out.println(count1+n);
			} else {
				int i = 0;
				while (i < 2*n) {
					if (s.charAt(i) == 'N' && s.charAt(i+2*n) == 'Y') {
						count1++;
						break;
					} else if ((s.charAt(i) == 'Y' && s.charAt(i+2*n) == 'Y') || (s.charAt(i) == 'Y' && s.charAt(i+2*n) == 'N')) {
						break;
					}
					i++;
				}
				i = 2*n-1;
				while (i >= 0) {
					if (s.charAt(i) == 'N' && s.charAt(i+2*n) == 'Y') {
						count1++;
						break;
					} else if ((s.charAt(i) == 'Y' && s.charAt(i+2*n) == 'Y') || (s.charAt(i) == 'Y' && s.charAt(i+2*n) == 'N')) {
						break;
					}
					i--;
				}
				out.println(count1+count2+n);
			}
			
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}
