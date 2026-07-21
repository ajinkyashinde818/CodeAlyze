import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		char[] s = sc.next().toCharArray();
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		ArrayList<Integer> xList = new ArrayList<>();
		ArrayList<Integer> yList = new ArrayList<>();
		
		boolean isX = true;
		int cnt=0;
		for(int i=0; i<=s.length; i++) {
			if(i==s.length || s[i]=='T') {
				if(isX)
					xList.add(cnt);
				else
					yList.add(cnt);
				cnt=0;
				isX ^= true;
			} else {
				cnt++;
			}
		}

		x -= xList.get(0);
		xList.remove(0);
		System.out.println(reachable(xList, x) && reachable(yList, y) ? "Yes" : "No");
		
		sc.close();
	}
	
	static boolean reachable(ArrayList<Integer> list, int goal) {
		HashSet<Integer> set = new HashSet<Integer>();
		set.add(0);
		
		for(int v : list) {
			HashSet<Integer> next = new HashSet<>();
			for(int base : set) {
				next.add(base + v);
				next.add(base - v);
			}
			set = next;
		}
		
		return set.contains(goal);
	}
}
