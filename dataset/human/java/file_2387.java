import java.io.*;
import java.util.*;

public class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		for(int i=0;i<s.length()-8;i++){
			System.out.print(s.charAt(i));
		}
		System.out.println();
	}
}
