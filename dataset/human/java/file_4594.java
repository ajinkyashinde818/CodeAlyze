import java.util.*;
public class Main {
	public static void main(String[] args)
	{
		//変数
		//long count=0;
		//boolean sw=false;
		long answer=0;
		//boolean poison=false;
		
		//入力
		Scanner sc = new Scanner(System.in);
		long A=sc.nextInt();
		long B=sc.nextInt();
		long C=sc.nextInt();
		
		//処理
		if(C<B || C<A || C<A+B)
		{
			answer=B+C;
		}else
		{
			long canIeatC=C-(C-B-A);
			if(canIeatC==C)
			{
				answer=B+C;
			}
			else
			{
				answer=B+canIeatC+1;
			}
			
		}
		// 出力
		System.out.println(answer);
	}
}
