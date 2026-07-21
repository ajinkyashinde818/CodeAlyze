import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scanner = new Scanner(System.in);

		int k = scanner.nextInt();
		int n = scanner.nextInt();
//		List<Integer> a = new ArrayList<Integer>();
//		Map<Integer, Integer> distMap = new HashMap<Integer, Integer>();
//		for(int i = 1; i <= n; i++){
//			a.add(scanner.nextInt());
//			if(i > 1){
//				distMap.put(i, a.get(i-1)-a.get(i-2));
//			}
//			if(i == n){
//				distMap.put(1, k-a.get(i-1)+a.get(0));
//			}
//		}
		int [] a = new int[n];
		int[] dist = new int[n];
		Map<Integer, Integer> distMap = new HashMap<Integer, Integer>();
		for(int i = 0 ; i < n; i++){
			a[i] = scanner.nextInt();
			if(i > 0){
				dist[i] = a[i] - a[i-1];
				distMap.put(dist[i], i);
			}
			if(i == n-1){
				dist[0] = k - a[i] + a[0];
				distMap.put(dist[0], 0);
			}
		}
		Arrays.sort(dist);
		int result =  k - (dist[n-1]);
		System.out.println(result);
//		System.out.println(Math.abs(maxDistNum));


		scanner.close();
	}

}
