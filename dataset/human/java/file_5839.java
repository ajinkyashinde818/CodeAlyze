import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		char[] moji3=new char[3];
		String moto=sc.next();
		for(int i=0; i<3; i++) {
			moji3[i]=moto.charAt(i);
		}
		int[] ookisa=new int[3];
		for(int i=0; i<3; i++) {
			ookisa[i]=moji3[i]*1-96;
		}

		if(ookisa[0]*ookisa[1]*ookisa[2]==6) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
