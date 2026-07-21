import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
	
		int[] on_take = {4, 1, 4, 1, 2, 1, 2, 1};
		for(; scanner.hasNext();)
		{
			int[] on_guest = new int[8];
			int min_take = 0;
			for(int i=0; i<8; i++)
			{
				on_guest[i] = scanner.nextInt();
				min_take += on_guest[i];
			}
			
			String output="";
			for(int i=0; i<8; i++)
			{
				int not_take = 0;
				String array="";
				for(int j=0; j<8; j++)
				{
					int n = i+j;
					if(n >= 8)
					{
						n -= 8;
					}
					array += on_take[n];
					
					if(on_guest[j]-on_take[n] > 0)
					{
						not_take += on_guest[j]-on_take[n];
					}
				}
				
				if(min_take >= not_take)
				{
					boolean updata = false;
					if(i>0 && min_take==not_take)
					{
						if(Integer.parseInt(output)>Integer.parseInt(array))
						{
							updata = true;
						}
					}
					else
					{
						updata = true;
					}
					
					if(updata)
					{
						min_take = not_take;
						output = array;
					}
				}
			}
			
			for(int i=0; i<8; i++)
			{
				System.out.print(output.substring(i, i+1)+(i<7?" ":"\n"));
			}
		}
	}
}
