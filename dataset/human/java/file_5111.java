import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		LinkedList<Character> list = new LinkedList<Character>();
		for(char c : S.toCharArray()){
			list.add(c);
		}
		int Q = sc.nextInt();
		boolean r = false;
		for(int q = 0 ; q < Q ; ++q){
			int T = sc.nextInt();
			if(T == 1){
				r = !r;
			}else{
				int f = sc.nextInt();
				char c = sc.next().charAt(0);
				if(f == 1){
					if(r){
						list.addLast(c);
					}else{
						list.addFirst(c);
					}
				}else{
					if(r){
						list.addFirst(c);
					}else{
						list.addLast(c);
					}					
				}
			}
		}
		if(r){
			Collections.reverse(list);
		}
		StringBuilder ret = new StringBuilder();
		for(char c : list){
			ret.append(c);
		}
		System.out.println(ret);
	}
}
