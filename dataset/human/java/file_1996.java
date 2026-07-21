import java.util.*;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		HashMap<Long,Integer> map = new HashMap<>();
		while(n%2==0){
			map.put((long)2,map.getOrDefault((long)2,0)+1);
			//System.out.println(map.get((long)2));
			n=n/2;
		}
		for(long i=3;i<=Math.sqrt(n);i=i+2){
			while(n%i==0){
				n=n/i;
				map.put(i,map.getOrDefault(i,0)+1);
			}
		}
		if(n>2){
			map.put(n,map.getOrDefault(n,0)+1);
		}
		int ans =0;
		for(Map.Entry<Long,Integer> entry : map.entrySet() ){
			int y = entry.getValue();
			int u = (int)Math.sqrt(1+8*y);
			//System.out.println(u);
			u=(u-1)/2;
			//System.out.println(u);
			ans = ans+u;
		}
		System.out.println(ans);
	}
}
