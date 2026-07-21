import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		int len = (int) 1e7;
		long numOrg = num;
		boolean[] hurui = new boolean[len];
		Arrays.fill(hurui, true);
		hurui[0] = false;
		hurui[1] = false;
		for (int i = 2; i < len; i++) {
			if (!hurui[i]) {
				continue;
			} else {
				for (int j = i * 2; j < len; j += i) {
					hurui[j] = false;
				}
			}
		}
		long count = 0l;
		int index = 2;
		int[] used = new int[len];
		while (num > 1 && index < len - 1) {
			if (num % index == 0) {
				num /= index;
				used[index]++;
			} else {
				while (index < len - 1 && !hurui[++index]) {
				}
			}
		}
		index = 2;
		while (index < len) {
			int indexTmp = 1;
			while (used[index] >= indexTmp) {
				used[index] -= indexTmp;
				++count;
				++indexTmp;
			}
			++index;
		}
		int tmp = (int) Math.sqrt(numOrg) + 10;
		boolean flag = true;
		for (int i = 2; i <= tmp; i++) {
			if (numOrg % i == 0) {
				flag = false;
				break;
			}
		}
		if (flag && numOrg > 1) {
			++count;
		}
		if (num != numOrg && num > 1) {
			tmp = (int) Math.sqrt(num) + 10;
			flag = true;
			for (int i = 2; i <= tmp; i++) {
				if (num % i == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				++count;
			}
		}
		System.out.println(count);
	}
}
