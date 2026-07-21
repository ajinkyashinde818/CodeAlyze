import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	static int[][] map;
	static int[][] directions8= {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	static int[][] directions4= {{-1,0},{1,0},{0,-1},{0,1}};
	static String ans;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		while(true) {

			int n = sc.nextInt();

			if(n==0) {
				break;
			}
			ans ="";
			int[] keys = new int[n];
			for(int i = 0; i < n; i++) {
				keys[i] = sc.nextInt();
				if(keys[i] > 26) {
					keys[i] = (52- keys[i])*-1;
				}
			}
			String stations = sc.next();
			for(int i = 0; i < stations.length(); i++) {
				int stationNum = (int)stations.charAt(i) - keys[i%keys.length];
				Character thisChar = stations.charAt(i);

				if(Character.isUpperCase(thisChar)) {
					if(stationNum < 65) {
						int tmp = 65- stationNum;
						stationNum = 123 - tmp;
					}else if(stationNum > 90) {
						int tmp = stationNum - 90;
						stationNum = 96 + tmp;
					}
				}else {
					if(stationNum < 97) {
						int tmp = 97 -stationNum;
						stationNum = 91 - tmp;
					}else if(stationNum > 122) {
						int tmp = stationNum - 122;
						stationNum = 64 + tmp;
					}
				}
				ans += (char)stationNum;
			}
			System.out.println(ans);
		}
	}

	//BFS用に二つの配列を足し算する
	static int[] addArrayElms(int[] a, int[] b) {
		int[] c = new int[a.length];
		for(int i = 0; i < a.length; i++) {
			c[i] = a[i] + b[i];
		}
		return c;
	}

	//	//二分探索
	//k <= num となる最小の配列要素kのインデックスを返す
	static private int binarySearch(long num, long[] orderedArray){
		int lowerBorder = -1;
		int upperBorder = orderedArray.length;
		int mid;

		while(upperBorder - lowerBorder >1) {
			mid = (upperBorder + lowerBorder)/2;
			if(orderedArray[mid]<=num) {
				lowerBorder = mid;
			}else {
				upperBorder = mid;
			}
		}
		return lowerBorder;
	}

	//二分探索
	//k <= num となる最小のList要素kのインデックスを返す
	static private int binarySearch(long num, ArrayList<Long> orderedList){
		int lowerBorder = -1;
		int upperBorder = orderedList.size();
		int mid;

		while(upperBorder - lowerBorder >1) {
			mid = (upperBorder + lowerBorder)/2;
			if(orderedList.get(mid)<=num) {
				lowerBorder = mid;
			}else {
				upperBorder = mid;
			}
		}
		return lowerBorder;
	}

	//aとbの最小公倍数を求める
	public static int gcd(int a, int b) {
		return b == 0 ? a: gcd(b, a % b);
	}
	public static long gcd(long a, long b) {
		return b == 0 ? a: gcd(b, a % b);
	}
}
