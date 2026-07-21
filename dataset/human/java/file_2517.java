import java.util.Scanner;

public class Main {
	
	Scanner sc = new Scanner(System.in);
	public void run() {
			int n = sc.nextInt();
			sc.nextLine();
			calc(n);
	}

	public void calc(int n){
		for(int i = 0; i < n; i++){
			String line = sc.nextLine();
			String[] mcxis = line.split(" ");
			int n1 = getNum(mcxis[0]);
			int n2 = getNum(mcxis[1]);
			System.out.println(getMCXI(n1 + n2));
		}
	}
	public int getNum(String s){
		int t = 1;
		int sum = 0;
		for(int i = 0; i < s.length(); i++){
			char c = s.charAt(i);
			if(c == 'm') {
				sum = sum + t * 1000;
				t = 1;
			}
			else if(c == 'c') {
				sum = sum + t * 100;
				t = 1;
			}
			else if(c == 'x') {
				sum = sum + t * 10;
				t = 1;
			}
			else if(c == 'i') {
				sum = sum + t;
				t = 1;
			}
			else{
				t = Integer.parseInt(""+c);
			}
		}
		return sum;
	}
	public String getMCXI(int n){
		String ans = "";
		if(n > 999){
			int m = n / 1000;
			if(m == 1) ans = ans + "m";
			else ans = ans + m + "m";
			n = n - m * 1000;
		}
		if(n > 99){
			int c = n / 100;
			if(c == 1) ans = ans + "c";
			else ans = ans + c + "c";
			n = n - c * 100;
		}
		if(n > 9){
			int x = n / 10;
			if(x == 1) ans = ans + "x";
			else ans = ans + x + "x";
			n = n - x * 10;
		}
		if(n != 0){
			if(n == 1) ans = ans + "i";
			else ans = ans + n + "i";
		}
		return ans;
	}
	public static void main(String[] args) {
		new Main().run();
	}
}
