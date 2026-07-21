import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		
		long n=s.nextLong();
		
		HashMap<Long,Integer> map=new HashMap<>();
		
		pf(n,map);
		
		int ans=0;
		
		for(Map.Entry<Long,Integer> entry:map.entrySet())
		{
			ans=ans+fun(entry.getValue());
		}
		
		System.out.println(ans);
		
	}
	
	public static int fun(int val)
	{
		int sum=0;
		int count=0;
		
		for(int i=1;i<=val;i++)
		{
			if(sum+i<=val)
			{
				sum=sum+i;
				count++;
			}
			else
				break;
		}
		
		return count;
	}
	
	public static void pf(long n,HashMap<Long,Integer> map) 
    { 
        while (n%2==0) 
        { 
            if(map.containsKey(2l))
            {
            	map.put(2l,map.get(2l)+1);
            }
            else
            {
            	map.put(2l,1);
            }
            
            n /= 2; 
        } 
  
        for (long i = 3; i <= Math.sqrt(n); i+= 2) 
        { 
            while (n%i == 0) 
            { 
            	if(map.containsKey(i))
                {
                	map.put(i,map.get(i)+1);
                }
                else
                {
                	map.put(i,1);
                }
            	
                n /= i; 
            } 
        } 
        
        if (n > 2) 
        {
        	if(map.containsKey(n))
            {
            	map.put(n,map.get(n)+1);
            }
            else
            {
            	map.put(n,1);
            }
        }
    } 
	
}
