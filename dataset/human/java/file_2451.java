import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for(int i = 0; i<N; i++) {
			int a = MCXItoInteger(sc.next());
			int b = MCXItoInteger(sc.next());
			System.out.println(toMCXI(a + b));
		}
		sc.close();
		// System.out.println(MCXItoInteger("m2ci"));
		// System.out.println(toMCXI(1204));
	}

	public static int MCXItoInteger(String str) {
		int MCXIValue = 0;
		int beforeTheNumber = 1;
		for(int i = 0; i < str.length(); i++) {
			String theCharacter = String.valueOf(str.charAt(i));
			if(theCharacter.equals("m")) {
				MCXIValue += (beforeTheNumber * 1000);
				beforeTheNumber = 1;
			}else if(theCharacter.equals("c")) {
				MCXIValue += (beforeTheNumber * 100);
				beforeTheNumber = 1;
			}else if(theCharacter.equals("x")) {
				MCXIValue += (beforeTheNumber * 10);
				beforeTheNumber = 1;
			}else if(theCharacter.equals("i")) {
				MCXIValue += (beforeTheNumber * 1);
				beforeTheNumber = 1;
			}else {
				beforeTheNumber = Integer.valueOf(theCharacter);
			}
		}
		return MCXIValue;
	}

	public static String toMCXI(int num) {
		int m = num / 1000;
		int c = (num - (m * 1000)) / 100;
		int x = (num - (m * 1000) - (c * 100)) / 10;
		int i = num - (m * 1000) - (c * 100) - (x * 10);
		// System.out.println("m:" + m + " c:" + c +" x:"+ x + " i:" + i);
		StringBuffer MCXIValue = new StringBuffer();
		if(m == 1) {
			MCXIValue.append("m");
		}else if(m > 1) {
			MCXIValue.append(String.valueOf(m));
			MCXIValue.append("m");
		}
		if(c == 1) {
			MCXIValue.append("c");
		}else if(c > 1) {
			MCXIValue.append(String.valueOf(c));
			MCXIValue.append("c");
		}
		if(x == 1) {
			MCXIValue.append("x");
		}else if(x > 1) {
			MCXIValue.append(String.valueOf(x));
			MCXIValue.append("x");
		}
		if(i == 1) {
			MCXIValue.append("i");
		}else if(i > 1) {
			MCXIValue.append(String.valueOf(i));
			MCXIValue.append("i");
		}
		return String.valueOf(MCXIValue);
	}
}
