import java.util.Arrays;
import java.util.Scanner;

public class Main 
{
	static long best = 9999999999999l;
	static void go(int[] or)
	{
//		System.out.println("Try: " +Arrays.toString(or));
		
		long cur = 0;
		long remtar = g;
		for(int i = 0; i < d && remtar > 0; i++)
		{
			long nobon = remtar/((or[i]+1)*100);
			if(remtar%((or[i]+1)*100)!=0)nobon++;
			
			if(nobon < pro[or[i]])
			{ //do this many problems only
				cur += nobon;
				break;
			}
			else
			{
				cur += pro[or[i]];
				remtar -= pro[or[i]] * ((or[i]+1)*100);
				remtar -= bon[or[i]];
			}
		}
		best = Math.min(cur, best);
	}

	static void permutate(int[] cur, int i)
	{
		com++;
		for(int j = i; j < d; j++)
		{
			int[] cl = cur.clone();
			if(i!=j)
			{ //swap i and j
				cl[i] = cl[i] + cl[j];
				cl[j] = cl[i] - cl[j];
				cl[i] = cl[i] - cl[j];
			}
			permutate(cl, i+1);
		}
		
		if(i==d)
		{
			tot++;
//			System.out.println(i +" after: " +Arrays.toString(cur));
			go(cur);
		}
	}
	
	static int d;
	static int tot = 0;
	static int com = 0;
	static int g;
	static long[] bon;
	static long[] pro;

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		g = sc.nextInt(); //target score
		bon = new long[d];
		pro = new long[d];
		
		for(int i = 0; i < d; i++)
		{
			pro[i] =  sc.nextInt();
			bon[i] = sc.nextInt();
		}
		int[] init = new int[d];
		for(int i = 0; i < d; i++)
			init[i] = i;
		
		permutate(init, 0);
		
//		System.out.println("Test : " + Arrays.toString(init));
//		System.out.println(tot + " " + com);
		
		System.out.println(best);
	}
}
