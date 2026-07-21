import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int R=scan.nextInt();
		int d=0,r=0;
		if(N<=10)
		{
			d=100*(10-N);
			r=d+R;
			System.out.println(r);
		}
		else
		{
			System.out.println(R);
		}

	}

}
