import java.util.*;
import java.awt.geom.*;
import java.io.*;

public class Main{
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		int dataset = sc.nextInt();
		while(dataset-- > 0){
			String a = sc.next();
			String b = sc.next();
			int anum = solve(a);
			int bnum = solve(b);
			String c = tostr(anum + bnum);
			System.out.println(c);
		}
	}
	
	private int solve(String a) {
		int mul = 1;
		int res = 0;
		int [] value = new int[26];
		value['m' - 'a'] = 1000;
		value['c' - 'a'] = 100;
		value['x' - 'a'] = 10;
		value['i' - 'a'] = 1;
		for(int i = 0; i < a.length(); i++){
			if(Character.isDigit(a.charAt(i))){
				mul = a.charAt(i) - '0';
			}
			else{
				res += value[a.charAt(i) - 'a'] * mul;
				mul = 1;
			}
		}
		return res;
	}
	
	private String tostr(int num) {
		StringBuilder sb = new StringBuilder();
		String [] c = {"m", "c", "x" , "i"};
		for(int i = 1000, count = 0;i != 0; i = i / 10, count++){
			if(num / i == 0){
				continue;
			}
			int temp = num / i;
			if(temp != 1){
				sb.append(num / i);
			}
			sb.append(c[count]);
			num = num % i;
		}
		return sb.toString();
	}
	
	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
