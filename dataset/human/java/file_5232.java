import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		StringBuffer sb = new StringBuffer(sc.next());
		StringBuffer pos = new StringBuffer();

		int q = sc.nextInt();
		boolean reverse = false;
		for(int i = 0; i < q; i++){
			int op = sc.nextInt();

			if(op == 1){
				reverse = !reverse;
			}

			else {
				int f = sc.nextInt();
				char c = sc.next().charAt(0);
				if((f == 1 &&!reverse) || (f == 2 && reverse)){
					pos.append(c);
				}
				else {
					sb.append(c);
				}
			}
		}

		if(!reverse){
			System.out.println(pos.reverse().toString() + sb);
		}
		else {
			System.out.println(sb.reverse() + pos.toString());
		}
	}
}
