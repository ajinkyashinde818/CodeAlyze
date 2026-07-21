import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		int ca=0;
		int cb=0;
		int cc=0;
		String str[] = new String[3];
		for(int i=0;i<3;i++) {
		str[i] = String.valueOf(line.charAt(i));
		}
		for(int i=0;i<3;i++) {
			if(str[i].equals("a")) {
				ca++;
			}else if(str[i].equals("b")) {
				cb++;
			}else {
				cc++;
			}
		}
			if(ca==1&&cb==1&&cc==1) {
				System.out.printf("Yes");
			}else {
				System.out.printf("No");
			}
	}
}
