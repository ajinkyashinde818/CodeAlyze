import java.util.Scanner;

public class Main{
	public static void main(String[] args)
	{
		Scanner sc =new Scanner(System.in);
		int K=sc.nextInt();	//縦
		int S=sc.nextInt();	//横
		int num=0;

		for(int i=0;i<=K;i++){
			for(int j=0;j<=K;j++){
				if(S-i-j>=0 && S-i-j<=K) num++;
			}
		}
		System.out.println(num);
	}
}
