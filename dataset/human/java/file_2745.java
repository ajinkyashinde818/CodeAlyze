import java.io.File;
import java.io.IOException;
import java.util.*;

import javax.swing.plaf.synth.SynthSeparatorUI;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		String t = sc.next();
		char[] ss = s.toCharArray();
		Arrays.sort(ss);
		char[] tt = t.toCharArray();
		Arrays.sort(tt);
		
		int lenS = s.length();
		int lenT = t.length();
		int len = lenS;
		if(lenS > lenT) len = lenT;
		
		for(int i = 0; i < len; i++){
			if(ss[i] < tt[lenT-i-1]){
				System.out.println("Yes");
				return;
			}
			if(ss[i] > tt[lenT-i-1]){
				System.out.println("No");
				return;
			}
		}
		
		System.out.println((lenS < lenT) ? "Yes" : "No");
	}
}
