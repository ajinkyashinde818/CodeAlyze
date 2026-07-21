import java.util.*;

public class Main {
    static final long MOD = 1000000007;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		PriorityQueue<Unit> queue = new PriorityQueue<>();
		for (int i = 0; i < n; i++) {
		    queue.add(new Unit(sc.nextInt(), true));
		}
		for (int i = 0; i < n; i++) {
		    queue.add(new Unit(sc.nextInt(), false));
		}
		long ans = 1;
		boolean currentType = false;
		ArrayDeque<Unit> stack = new ArrayDeque<>();
		while (queue.size() > 0) {
		    Unit u = queue.poll();
		    if (stack.size() == 0 || currentType == u.type) {
		        stack.push(u);
		        currentType = u.type;
		    } else {
		        ans *= stack.size();
		        ans %= MOD;
		        stack.pop();
		    }
		}
		System.out.println(ans);
	}
	
	static class Unit implements Comparable<Unit> {
	    int place;
	    boolean type;
	    
	    public Unit (int place, boolean type) {
	        this.place = place;
	        this.type = type;
	    }
	    
	    public int compareTo(Unit another) {
	        return place - another.place;
	    }
	}
	    
}
