import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		long k=s.nextLong();
		
		int[] arr=new int[n+1];
		
		for(int i=1;i<n+1;i++)
		{
			arr[i]=s.nextInt();
		}
		
		int[] visited=new int[n+1];
		
		ArrayList<Integer> translate=new ArrayList<>();
		ArrayList<Integer> cycle=new ArrayList<>();
		
		visited[1]=1;
		
		int curr=1;
		
		while(visited[arr[curr]]==0)
		{
			visited[arr[curr]]=1;
			curr=arr[curr];
		}
		
		int goal=arr[curr];
		curr=arr[goal];
		
		cycle.add(goal);
		
		while(curr!=goal)
		{
			cycle.add(curr);
			curr=arr[curr];
		}
		
		int start=1;
		
		while(start!=goal)
		{
			translate.add(start);
			start=arr[start];
		}
		
		translate.add(goal);
		
		if(k<translate.size())
		{
			System.out.println(translate.get((int)k));
		}
		else
		{
			k=k-translate.size()+1;
			
			long rem=k%cycle.size();
			
			System.out.println(cycle.get((int)rem));
		}
	}
	
}
