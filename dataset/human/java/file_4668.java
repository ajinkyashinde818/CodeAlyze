import java.util.*;

public class Main{
	
	ArrayList<Long> list;
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		init();
		while(true){
			int n = sc.nextInt();
			int k = sc.nextInt();
			if((n|k) == 0) break;
			int ind = binarySearch(n);
			ind++;
			long num  = pow(ind - 1);
			int diff = (int) (n - list.get(ind-1));
			int div = diff / ind;
			int mod = diff % ind;
			long num2 = num + div;
			StringBuilder sb = new StringBuilder();
			while(sb.length() < k + mod){
				sb.append(num2);
				num2++;
			}
			System.out.println(sb.substring(mod, k + mod));
		}
	}
	
	private int binarySearch(int patt){
		int mid, left = 0, right = list.size()-1;
		while(left <= right){
			mid = (left + right) / 2;
			if(list.get(mid) == patt){
				return mid;
			}
			if(list.get(mid) < patt){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return right;
	}

	private void init() {
		list = new ArrayList<Long>();
		list.add(1L);
		for(int i = 1; i <= 9; i++){
			long temp = (pow(i) - 1 - pow(i-1) + 1) * i + list.get(i-1);
			list.add(temp);
		}
	}

	private long pow(int num) {
		long sum = 1;
		for(int i = 0; i < num; i++){
			sum *= 10;
		}
		return sum;
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
