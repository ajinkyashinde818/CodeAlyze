import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();
		int Q = sc.nextInt();

		boolean hanten = false;
		List<String> mae = new ArrayList<>();
		List<String> ushiro = new ArrayList<>();
		for (int i=0; i<Q; i++) {
			int T = sc.nextInt();
			if (T == 1) {
				hanten = !hanten;
			}
			else {
				int F = sc.nextInt();
				String C = sc.next();
				if (F == 1 && !hanten || F == 2 && hanten) {
					mae.add(C);
				}
				else {
					ushiro.add(C);
				}
			}
		}

		StringBuilder ans = new StringBuilder();
		if (hanten) {
			for (int i=ushiro.size() - 1; i>=0; i--) {
				ans.append(ushiro.get(i));
			}
			for (int i=S.length() - 1; i>=0; i--) {
				ans.append(S.charAt(i));
			}
			for (int i=0; i<mae.size(); i++) {
				ans.append(mae.get(i));
			}
		}
		else {
			for (int i=mae.size() - 1; i>=0; i--) {
				ans.append(mae.get(i));
			}
			ans.append(S);
			for (int i=0; i<ushiro.size(); i++) {
				ans.append(ushiro.get(i));
			}
		}
		
		System.out.println(ans);
	}
}
