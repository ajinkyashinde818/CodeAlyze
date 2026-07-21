import java.util.Scanner;
class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] arr=new int[n];
		int[] arr1=new int[n];
		int count=0,flag=0;
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
			arr1[i]=sc.nextInt();
		}
		for(int i=0;i<n;i++) 
		{
				
			if(arr[i]==arr1[i])
			{
				count++;
				if(count>=3)
				{
					flag=1;
					break;
					
				}
			}
			else
			{
				count=0;
			}
			
		}
			
			
		
		if(flag==1)
		{
			System.out.println("Yes");
		}
		else
		{
			System.out.println("No");
		}

	}

}
