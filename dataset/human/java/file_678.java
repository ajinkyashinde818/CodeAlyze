import java.util.Scanner;
public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		
		String[] strAry = str.split(" ");
		int int1 = Integer.parseInt(strAry[0]);
		int int2 = Integer.valueOf(strAry[1]).intValue();
		
		int rate;
		
		if(int1 >=10) {
		    rate = int2;
		}else {
			rate = int2 + 100*(10-int1);
			
		}
		System.out.println(String.valueOf(rate));

		
		
	}

}
