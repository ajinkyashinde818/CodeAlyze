import java.math.*;
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong(),k=sc.nextLong();
		int arr[]=new int[(int) n+1];
//		int ans[]=new int[(int) n+1];
		for(int i=1;i<=n;i++){
			arr[i]=sc.nextInt();
		}
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		int index=1;
		int count=1;
		while(!map.containsKey(arr[index])){
			map.put(arr[index], count);
//			ans[count]=index;
			count++;
			index=arr[index];
		}
		int cell=count-map.get(arr[index]);
		int form=map.get(arr[index]);
		if(k>=count){
			k-=count;
			k%=cell;
			k+=count;
			k-=cell;
		}
		for(int ts:map.keySet()){
//			System.out.println(ts+" "+map.get(ts));
			if(map.get(ts)==k){
				
				System.out.println(ts);
			}
		}
	}
}
