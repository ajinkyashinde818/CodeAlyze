import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int data = sc.nextInt();
		for(int i=0; i<data; i++){
			String mcxi_1 = sc.next();
			String mcxi_2 = sc.next();

			int a = Main.numeral_system(mcxi_1);
			int b = Main.numeral_system(mcxi_2);

			String str = Main.changeMCXI(a+b);	

			System.out.println(str);
		}
	}

	static int numeral_system(String mcxi){
		int num = 0;
		int coefficient = 1;
		for(int i=0; i<mcxi.length(); i++){
			char temp = mcxi.charAt(i);
			if(temp>'0'&&temp<='9'){
				coefficient = temp - '0';
			}else if(temp == 'm'){
				num += coefficient*1000;
				coefficient = 1;
			}else if(temp == 'c'){
				num += coefficient*100;
				coefficient = 1;
			}else if(temp == 'x'){
				num += coefficient*10;
				coefficient = 1;
			}else{
				num += coefficient;
			}
		}
		return num;
	}

	static String changeMCXI(int num){
		String str = "";
		int coefficient, n = 1000;
		for(int i=0; i<4; i++){
			coefficient = num/n;
			if(coefficient!=0){
				if(coefficient!=1) str += String.valueOf(coefficient);
				switch(i){
					case 0:
						str += "m";
						break;
					case 1:
						str += "c";
						break;
					case 2:
						str += "x";
						break;
					case 3:
						str += "i";
				}
			}
			num -= coefficient*n;
			n /= 10;
		}
		return str;
	}
}
