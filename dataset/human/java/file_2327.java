import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;


public class Main {
	static int N;
	static int[] K;
	static String S;
	
	static char[] station = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 
							 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
			
	static private void solve()
	{
		StringBuilder sb = new StringBuilder();
		ArrayList<String> list = new ArrayList<String>();
		for (int i = 0; i < station.length; i++) {
			list.add(station[i] + "");
		}
		
		int keyindex = 0;
		for (int i = 0; i < S.length(); i++) {
			
			int index = list.indexOf(S.substring(i, i+1));
			
			index -= K[keyindex];
			if(index < 0) index += 52;
			
			sb.append(station[index]);
			keyindex++;
			if (keyindex == N) {
				keyindex = 0;
			}
		}
		
		System.out.println(sb.toString());
	}
	
	static public void main(String[] args)
	{
		Scanner sca = new Scanner(System.in);
		
		while(true)
		{
			N = sca.nextInt();
			if(N == 0) break;
			
			K = new int[N];
			for (int i = 0; i < N; i++) {
				K[i] = sca.nextInt();
			}
			
			S = sca.next();

			solve();
		}
	}
}
