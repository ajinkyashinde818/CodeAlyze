import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 0; i < n; i++){

			String mcxi1 = sc.next();
			String mcxi2 = sc.next();
			int val = 0;
			for(int j = 0; j < mcxi1.length(); j++){
				if(Character.isDigit(mcxi1.charAt(j))){
					val += Character.getNumericValue(mcxi1.charAt(j)) * reval(mcxi1.charAt(j + 1));
					j++;
				}else{
					val += reval(mcxi1.charAt(j));
				}
			}
			for(int j = 0; j < mcxi2.length(); j++){
				if(Character.isDigit(mcxi2.charAt(j))){
					val += Character.getNumericValue(mcxi2.charAt(j)) * reval(mcxi2.charAt(j + 1));
					j++;
				}else{
					val += reval(mcxi2.charAt(j));
				}
			}

			System.out.println(reviw(val));
		}
		
		
		sc.close();
	}
	static int reval(char x){
		if(x == 'm') return 1000;
		if(x == 'c') return 100;
		if(x == 'x') return 10;
		if(x == 'i') return 1;
		return -1;
	}
	static String reviw(int val){
		char[] c = {'m', 'c', 'x', 'i'};
		int[] x = {1000, 100, 10, 1};
		String res = "";
		for(int j = 0; j < c.length; j++){
			int tmp = val / x[j];
			if(tmp == 1){
				res = res + c[j];
			}else if(tmp > 1){
				res = res + tmp + c[j]; 
			}
			val = val % x[j];
		}
		return res;
	}
}
