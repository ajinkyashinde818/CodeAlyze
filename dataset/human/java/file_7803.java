import java.io.*;
import java.math.*;
import java.util.*;
public class Main {
 
	public static void main(String[] args) {
		long mod = (long)(1e9+7);
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		long K = input.nextLong();
		int[] A = new int[N+1];
		boolean[] vis = new boolean[N+1];
		boolean quick = false;
		vis[1]=true;
		int curIndex = 1;
		ArrayList<Integer> seq = new ArrayList<Integer>();
		seq.add(1);
		for (int i = 1; i <= N; i++) {
			A[i] = input.nextInt();
		}
		while (true) {
			K--;
			int temp = A[curIndex];
			curIndex=temp;
			if (vis[curIndex]) {
				while (seq.get(0)!=curIndex) {
					seq.remove(0);
				}
				break;
			} 
			else {
				seq.add(curIndex);
				vis[curIndex]=true;
			}
			if (K==0) {
				System.out.println(curIndex);
				quick = true;
				break;
			}
		}
		if (!quick) {
			long period = seq.size();
			int index = (int) (K%period);
			System.out.println(seq.get(index));
		}
	}
}
