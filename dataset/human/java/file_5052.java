import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean reverseEven = true;
		StringBuilder top = new StringBuilder("");
		StringBuilder bottom = new StringBuilder("");
		String s = sc.next();
		int q = sc.nextInt();
		for(int i = 0; i < q; i++){
			int q1 = sc.nextInt();
			if(q1 == 1){
				reverseEven = !reverseEven;
			}else{
				int f = sc.nextInt();
				if(f == 1){
					if(reverseEven){
						top.insert(0, sc.next());
					}else{
						bottom.append(sc.next());
					}
				}else{
					if(reverseEven){
						bottom.append(sc.next());
					}else{
						top.insert(0, sc.next());
					}
				}
			}
		}
		StringBuilder ans = top.append(s).append(bottom);
		if(! reverseEven){
			ans = ans.reverse();
		}
		System.out.println(ans);
	}
}
