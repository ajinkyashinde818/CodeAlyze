import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		List<Long> list = insu(n);
		Map<Long, Integer> map = new HashMap<>();
		for (Long key : list) {
    		Integer i = map.get(key);
    		map.put(key, i == null ? 1 : i + 1);
		}
		int ans = 0;
		for (Integer v: map.values()) {
			int hituyou = 1;
			int nokori = v;
			while(nokori >= hituyou){
				ans++;
				nokori -= hituyou;
				hituyou++;
			}
		}
		System.out.println(ans);
	}
	public static List<Long> insu(long n){
		List<Long> list = new ArrayList<>();
		if(n==1) return list;
		for(int i=2; i<=Math.sqrt(n); i++){
			if(n%i == 0){
				list.add((long)i);
				n = n/i;
				i = 1;
			}
		}
		list.add(n);
		return list;
	}
}
