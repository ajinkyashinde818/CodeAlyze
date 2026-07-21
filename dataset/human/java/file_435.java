import java.util.Scanner;
public class Main {
	public static void main(String[] args)throws Exception{
		Scanner stdIn=new Scanner(System.in);
		int N=stdIn.nextInt();
		int R=stdIn.nextInt();
		if(N>=10)
			System.out.println(R);
		else
			System.out.println(100*(10-N)+R);
	}
}
