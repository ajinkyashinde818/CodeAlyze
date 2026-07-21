import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		int m[][]={
				{1,2,1,2,1,4,1,4},
				{1,2,1,4,1,4,1,2},
				{1,4,1,2,1,2,1,4},
				{1,4,1,4,1,2,1,2},
				{2,1,2,1,4,1,4,1},
				{2,1,4,1,4,1,2,1},
				{4,1,2,1,2,1,4,1},
				{4,1,4,1,2,1,2,1},
		};
		while(in.hasNext())
		{
			int a[]=new int[8];
			for(int i=0;i<8;i++)
				a[i]=in.nextInt();
			
			int id=-1;
			int min=Integer.MAX_VALUE;
			for(int i=0;i<8;i++)
			{
				int sam=0;
				for(int j=0;j<8;j++)
				{
					int cnt=m[i][j]-a[j];
					if(cnt>0)
						sam+=cnt;
				}
				if(sam<min)
				{
					min=sam;
					id=i;
				}
			}
			for(int i=0;i<7;i++)
				System.out.print(m[id][i]+" ");
			System.out.println(m[id][7]);
		}
	}

	static public void debug(Object... o)
	{
		System.out.println(Arrays.deepToString(o));
	}
}
