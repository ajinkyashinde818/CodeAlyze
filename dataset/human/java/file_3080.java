import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		List<Integer> from1 = new ArrayList<>();
		List<Integer> toN = new ArrayList<>();
		for(int i=0;i<m;i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			if(a==1) from1.add(b);
			if(b==n) toN.add(a);
		}
		from1.sort(Comparator.naturalOrder());
		toN.sort(Comparator.naturalOrder());
		int fmax = from1.size();
		int tmax = toN.size();
		int fidx = 0;
		int tidx = 0;
		while(fidx<fmax && tidx<tmax) {
			int f = from1.get(fidx);
			int t = toN.get(tidx);
			if(f==t) break;
			else if(f<t) fidx++;
			else tidx++;
		}
		
		if(fidx==fmax || tidx==tmax) System.out.println("IMPOSSIBLE");
		else System.out.println("POSSIBLE");
		in.close();
	}

}
