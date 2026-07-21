import java.util.*;

public class Main{
	static public void  main(String[] args){
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		int b = scan.nextInt();
		int k = scan.nextInt();

		int cnt = 0;
		List<Integer> l = new ArrayList<>();
		for(int i = 1; i <= b; i++){
			if(a % i == 0 && b % i == 0){
				cnt++;
				//				System.err.println(i);
				l.add(i);
			}
		}
		System.out.println(l.get(l.size() - k));
	}
}
