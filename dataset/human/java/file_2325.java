import java.util.HashMap;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	Scanner sc = new Scanner(System.in);
	HashMap<String, Integer> map = new HashMap<String, Integer>();
	String[] stations = {
			"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
			"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
			"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", 
			"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
	};
	
	public void run(){
		for(int i = 0; i < 52; i++){
			map.put(stations[i], i);
		}
		while(true){
			int n = sc.nextInt();
			if(n==0) break;
			calc(n);
		}
	}
	public void calc(int n){
		int[] k = new int[100];
		for(int i = 0; i < n; i++){
			k[i] = sc.nextInt();
		}
		
		String s = sc.next();
		int len = s.length();
		int knum = 0;
		
		for(int i = 0; i < len; i++){
			String sta = s.substring(i, i+1);
			int stanum = map.get(sta);
			stanum -= k[knum];
			if(stanum < 0) stanum += 52;
			
			System.out.print(stations[stanum]);
			
			knum++;
			if(knum == n) knum = 0;
		}
		
		System.out.println();
	}
	
	public static void main(String[] args){
		new Main().run();
	}
	
}
