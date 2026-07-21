import java.util.*;
public class Main{ 	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		long res = 0;
		int[] arr = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			arr[i] = sc.nextInt();
		}
		Map<Integer, Integer> map = new HashMap<>();
		map.put(1,0);
		int i = 1;
		int next = arr[1];
		int town = 0;
		while(i <= k) {
			town = next;
			next = arr[next];
			if(map.containsKey(town)) {
				int pre = map.get(town);
				k = (k - pre) % (i - pre);
				i = 1;
				break;
			}
			else {
				map.put(town, i);
				i++;
			}
		}
		while(i <= k) {
			town = next;
			next = arr[next];
			i++;
		}
		System.out.println(town);
    }
}
