import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			long N = scan.nextLong();
			int count = 0;
			Set<Long>set = new TreeSet<Long>();
			outside:while(true) {
				
				
				for(Long a:enum_div(N)) {
					//System.out.print(a);
					//System.out.print(" ");
					}
				
				//System.out.println();
				//Collections.sort(as,Collections.reverseOrder());
				int ok = 0;
				for(Long i:enum_div(N)) {
					if(primefact(i).size()==1&&!set.contains(i)) {
					
					//System.out.println(i);
					//System.out.println(i);
					set.add(i);
					ok=1;
					N = N/i;
					//System.out.println(N);
					count++;
					break;
					//System.out.println(N);
				}
				
					
					
			}
				if(N==1||N==0) {
					break outside;
				}
				
				
			 //System.out.println();
			 
			 if(ok==0)break;
			}
			
			System.out.println(count);
			
			
			
			
			
			
			
			
			
			
			
			
			
		}
		
		
	}
	
	
	
	private static ArrayList<Long> enum_div(long n){//数字１〜ｎまでの約数を全部Allaylistに詰め込むメソッド
		ArrayList<Long> ret = new ArrayList<Long>();
		for(long i = 1;i*i<=n;i++) {
			if(n%i==0) {
				ret.add(i);
				if(i*i!=n){
					ret.add(n/i);
				}
			}
		}
		
		//ただここまでだと格納した約数はソートされてない
		
		Collections.sort(ret);//int型、Sting型くらいの格納した奴ならコレクションクラスのソートが使える。
		//ソートしてからcollections.reverseつかえば降順にもできる
		return ret;
		
		
		
	}
	
	
	/*for(Integer key:A.keySet()) {
	System.out.println(key);//素数
	System.out.println(A.get(key));//素数の指数
	}みたいな感じで表示できる*/	
	private static Map<Long,Long> primefact(long n){//入力ｎの素数とその指数をmapに格納
		Map<Long,Long> map = new TreeMap<Long,Long>();
		for(long i = 2;i*i<=n;i++) {
			if(n%i!=0) {
				continue;
			}
			long ex = 0;//素因数分解した素数たちの指数
			
			while (n % i == 0) {//iでわれる限りやる
				++ex;
				n /= i;
				}		
			map.put(i, ex);//(素数、その素数の指数)
		}
		if(n!=1) {//もし最後に素数が残ったら入れておく
			map.put(n, (long)1);
		}
		return map;
	}
		

}
