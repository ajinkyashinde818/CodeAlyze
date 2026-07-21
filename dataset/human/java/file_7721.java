import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int a[] = new int[N];
		int b[] = new int[N];
		for (int i=0;i<N;i++) {
			a[i] = sc.nextInt();
		}
		List<Integer> list  = new ArrayList<Integer> ();
		int count =0;
		int now =1;
		int breakKey=0;
		for (;count<N;count++) {
			if (b[a[now-1]-1]!=0) {
				breakKey =  a[now-1];
				break;
			}
			b[a[now-1]-1]= 1;
			list.add(a[now-1]);
			now = a[now-1];
		}
		if (count<N&&breakKey !=1) {
			int start =0;;
			for (int i=0;i<list.size();i++) {
				if (list.get(i)==breakKey) {
					start= i;
					break;
				}
			}
			if (K<start+1) {
				System.out.println(list.get((int)(K-1)));
			} else {
				K= K-start-1;
				int index = (int)(K%(list.size()-start));
				System.out.println(list.get(index+start));
			}
		} else {
			int index = (int) (K%(count));
			if (index==0) {
				System.out.println(1);
			} else {
				System.out.println(list.get(index-1));
			}
		}

	}
}
