import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		List<Integer> a = new ArrayList<Integer>();
		for (int i=1;i<=100;i++) {
			if (A%i==0) {
				a.add(i);
			}
		}
		List<Integer> b = new ArrayList<Integer>();
		for (int i=1;i<=100;i++) {
			if (B%i==0) {
				b.add(i);
			}
		}
		List<Integer> c = new ArrayList<Integer>();
		for (int i=0;i<a.size();i++){
			if (b.contains(a.get(i))) {
				c.add(a.get(i));
			}
		}
		System.out.println(c.get(c.size()-K));
	}
}
