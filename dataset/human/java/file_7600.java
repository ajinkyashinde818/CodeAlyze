import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {

	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		Long k = Long.parseLong(sc.next());
		int[] town = new int[n]; 
		boolean[] town_flag = new boolean[n];
		for(int i = 0 ; i < n ; i++) {
			town[i] = Integer.parseInt(sc.next());
		}
		
		List visit = new ArrayList<Integer>();
		town_flag[0] = true;
		visit.add(1);
		
		int pos = 0;
		while(true) {
			int temp = town[pos]-1;
			visit.add(temp+1);
			if(town_flag[temp]) {
				break;
			}
			town_flag[temp] = true;
			pos = temp;
		}
		pos = (int) visit.get(visit.size()-1);
		int looppos =visit.indexOf(pos)+1;
		
		
		int ans = 0;
		if(k < looppos) {
			ans = (int) visit.get(k.intValue());
		}else {
			int loop = visit.size() - looppos; 
			pos = (int) ((k-looppos)%loop);
			pos = pos + looppos;
			ans = (int) visit.get(pos);
		}
		System.out.println(ans);
	}
}
