import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N];
		for(int i = 0;i < N;i++){
			A[i] = sc.nextInt();
		}

		//訪れた頂点のメモ
		List<Integer> s = new ArrayList<>();
		//頂点に割り振る数字
		int[] ord = new int[N+1];
		Arrays.fill(ord, -1);
		int cycle = 1;
		int l = 0;
		{
			int v = 1;
			while(ord[v] == -1){
				ord[v] = s.size();
				s.add(v);
				v = A[v-1];
			}
			cycle = s.size() - ord[v];
			l = ord[v];
		}
		if(K < l){
			System.out.println(s.get((int) K));
		}else{
			K -= l;
			K %= cycle;
			System.out.println(s.get(l+(int)K));
		}
	}
}
