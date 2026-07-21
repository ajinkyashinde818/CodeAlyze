import java.util.*;
public class Main {
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) 
	{
		int n = sc.nextInt();
		int[][]arr = new int[n][2];
		for(int i=0;i<n;i++)
		{
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		boolean flag = false;
		for(int i=0;i<n-2;i++)
		{
			if((arr[i][0]==arr[i][1]) && (arr[i+1][0]==arr[i+1][1]) && (arr[i+2][0]==arr[i+2][1]))
			{
				flag = true;
				break;
			}
		}
		if(flag)
			System.out.println("Yes");
		else
			System.out.println("No");

	}

}
