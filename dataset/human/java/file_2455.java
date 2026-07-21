import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		// TODO ?????????????????????????????????????????????
		new Main().start();
	}
	void start(){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i = 0; i < n; i++){
			String s1 = in.next();
			String s2 = in.next();
			int a = getValue(s1);
			int b = getValue(s2);
			System.out.println(getMCXI(a+b));
		}
		in.close();
	}
	int getValue(String a){
		int num = 0;
		int x = 1;
		for(int i = 0; i< a.length(); i++){
			
			switch (a.charAt(i)){
			case 'm':
				num += x * 1000;
				x = 1;
				break;
			case 'c':
				num += x * 100;
				x = 1;
				break;
			case 'x':
				num += x * 10;
				x = 1;
				break;
			case 'i':
				num += x;
				x = 1;
				break;
			default:
				x = Integer.parseInt("" + a.charAt(i));
			}
		}
		return num;
	}
	String getMCXI(int a){
		String s = "";
		s += addMCXI(a,1000,"m");
		a -= a/1000 * 1000;
		s += addMCXI(a,100,"c");
		a -= a/100 * 100;
		s += addMCXI(a,10,"x");
		a -= a/10 * 10;
		s += addMCXI(a,1,"i");
		return s;
	}
	String addMCXI(int a, int b, String x){
		String s = "";
		if(a/b > 1){
			s += a/b + x;
		}else if(a/b == 1){
			s += x;
		}
		return s;
	}

}
