import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	String [] table = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101","1110", "1111"};
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		int dataset = sc.nextInt();
		while(dataset-- > 0){
			String s = sc.next();
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < s.length(); i++){
				int ind = s.charAt(i) - '0';
				if(ind > 9){
					ind = s.charAt(i) - 'a' + 10;
				}
				sb.append(table[ind]);
			}
			double min = 0.0, value = 0.5;
			for(int i = 0; i < 7; i++){
				char c = sb.charAt(32 - 7 + i);
				if(c == '1'){
					min += value;
				}
				value = value * 0.5;
			}
			String op = sb.charAt(0) == '0' ? "" : "-";
			String temp = sb.substring(1, 32-8 + 1);
			int num = Integer.parseInt(temp, 2);
			String res = (min - (int)min) + "";
			System.out.println(op + num + "." + res.substring(2));
		}
	}


	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
