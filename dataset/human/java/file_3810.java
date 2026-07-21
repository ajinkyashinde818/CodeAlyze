import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] arr = sc.next().toCharArray();
		int left = 0;
		int right = arr.length - 1;
		int count = 0;
		while (right - left > 0) {
			if (arr[right] == arr[left]) {
				left++;
				right--;
			} else if (arr[right] == 'x') {
				right--;
				count++;
			} else if (arr[left] == 'x') {
				left++;
				count++;
			} else {
				System.out.println(-1);
				return;
			}
		}
		System.out.println(count);
	}
}
