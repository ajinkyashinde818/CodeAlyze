import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		ArrayDeque<String> que = new ArrayDeque<>();
		String[] first = sc.next().split("");
		for(String s :first) {
			que.offerLast(s);
		}
		
		int Q = sc.nextInt();
		boolean reversed = false;
		for(int i =0;i<Q;i++ ) {
			int query_type = sc.nextInt();
			if(query_type==1) {
				reversed = !reversed;
			}else {
				int query_type2 = sc.nextInt();
				String add_str = sc.next();
				if((reversed&&query_type2==1)||(!reversed&&query_type2==2)) {
					que.offerLast(add_str);
				}else {
					que.offerFirst(add_str);
				}
			}
		}
		List<String> ans_list= new ArrayList<>( que );
		if(reversed) {
			Collections.reverse(ans_list);	
		}
		String ans = ans_list.stream().collect(Collectors.joining(""));
		System.out.println(ans);

	}

}
