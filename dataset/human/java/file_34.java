import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long n = sc.nextInt();
		for (long i=0;i*(i+1)/2<=n;i++) {
			if (i*(i+1)/2==n) {
				System.out.println("Yes");
				System.out.println(i+1);
				List<List<Long>> ans = (solve(i));
				for (List<Long> l : ans) {
					System.out.println(parse(l));
				}
				return;
			}
		}
		System.out.println("No");

	}
	
	static List<List<Long>> solve (long n) {
		if (n==2) {
			List<List<Long>> ans = new ArrayList<>();
			List<Long> l1 = new ArrayList<Long>();
			l1.add(1L);
			l1.add(2L);
			ans.add(l1);
			List<Long> l2 = new ArrayList<Long>();
			l2.add(2L);
			l2.add(3L);
			ans.add(l2);
			List<Long> l3 = new ArrayList<Long>();
			l3.add(3L);
			l3.add(1L);
			ans.add(l3);
			return ans;
		} else if (n==1) {
			List<List<Long>> ans = new ArrayList<>();
			List<Long> l1 = new ArrayList<Long>();
			l1.add(1L);
			ans.add(l1);
			List<Long> l2 = new ArrayList<Long>();
			l2.add(1L);
			ans.add(l2);
			return ans;
		} else if (n==0) {
			List<List<Long>> ans = new ArrayList<>();
			ans.add(new ArrayList<Long>());
			return ans;
		} else {
			List<List<Long>> ans = solve (n-3);
			for (int i=0;i<n-2;i++) {
				ans.get(i).add((n-2)*(n-3)/2+i+1);
				ans.get(i).add((n-2)*(n-3)/2+i+n);
				ans.get(i).add((n-2)*(n-3)/2+i+2*n-1);
			}
			List<Long> tmp1 = new ArrayList<Long>();
			List<Long> tmp2 = new ArrayList<Long>();
			List<Long> tmp3 = new ArrayList<Long>();
			for (int i=0;i<n;i++) {
				tmp1.add((n-2)*(n-3)/2+(i==0 ? 3*n-3 : i));
				tmp2.add((n-2)*(n-3)/2+i+n-1);
				tmp3.add((n-2)*(n-3)/2+i+2*n-2);
			}
			ans.add(tmp1);
			ans.add(tmp2);
			ans.add(tmp3);
			return ans;
		}
	}

	static String parse ( List<Long> l) {
		String ans = ""+l.size();
		for (Long lo : l) {
			ans = ans + " " + lo;
		}
		return ans;
	}



}
