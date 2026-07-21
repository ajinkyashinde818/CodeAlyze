import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Deque<List<Integer>> D = new ArrayDeque<>();
		List<Integer> tmp = new ArrayList<Integer>();

		int N=sc.nextInt();
		for(int i=0;i<N;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			tmp.add(a);
			tmp.add(b);
			D.add(tmp.stream().collect(Collectors.toList()));
			tmp.clear();
		}
		tmp=null;

		int cnt=0;
		while(D.size()!=0 && cnt<3){
			List<Integer> d =D.poll();
			if(d.get(0)==d.get(1)) {
				cnt+=1;
			}
			else {
				cnt=0;
			}
		}
		if(cnt>=3) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		sc.close();
	}
}
