import java.util.Scanner;

public class Main {

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		long k = sc.nextLong();
		
		int[] a = new int[n];
		int[] vis = new int[n];
		
		
		for(int i = 0; i < n; i++)
		{
			a[i] = sc.nextInt()-1;
		}
		
		int pos = 0;
		int time = 1;
		
		int loopstart = -1;
		int looptime = 0;
		
		while(true)
		{
//			System.out.println("Time " + time + " on " + pos);
			vis[pos] = time;
			pos = a[pos];
			
			time++;
			if(vis[pos] > 0)
			{
				loopstart = pos;
				looptime = time - vis[pos];
//				System.out.println("Loop found start " + pos + " len " + looptime);
				break;
			}
		}
		
		pos = 0;
		long more = k;
		while(more > 0)
		{
//			System.out.println("Pos " + pos + " " + loopstart);
			if(pos == loopstart)
			{
				if(more >= looptime)more = more%looptime;
				while(more<0)more+=looptime;
			}
			if(more<=0)break;
			pos = a[pos];
			more--;
		}
		pos++;
		System.out.println(pos);
	}

}
