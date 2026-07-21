import java.util.*;

public class Main {

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int q = sc.nextInt();
		boolean reversflag = false;
		List<String> prelist = new ArrayList<String>();
		List<String> aftlist = new ArrayList<String>();
		for (int i = 0; i < q; ++i) {
			int t = sc.nextInt();
			if (t == 1)
				reversflag = !reversflag;
			else {
				int f = sc.nextInt();
				String c = sc.next();
				if (reversflag) {
					if (f == 1)
						f = 2;
					else
						f = 1;
				}
				if (f == 1)
					prelist.add(c);
				else
					aftlist.add(c);
			}
		}
		int len = prelist.size();
		StringBuffer ans = new StringBuffer();
		for (int i = len - 1; i >= 0; --i)
			ans.append(prelist.get(i));
		ans.append(s);
		for (String t : aftlist)
			ans.append(t);
		if (reversflag)
			ans.reverse();
		System.out.println(ans.toString());
		sc.close();
	}
}
