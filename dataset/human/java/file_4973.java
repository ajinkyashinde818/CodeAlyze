import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		boolean hantenFlg = true;
		StringBuilder sb = new StringBuilder();
		sb.append(S);
		int Q = Integer.parseInt(sc.next());
		for(int i=0;i < Q;i++) {
			if(Integer.parseInt(sc.next()) == 1) {
				hantenFlg = hantenFlg ? false: true;
			}  else {
				if(Integer.parseInt(sc.next())==1) {
					if(hantenFlg) {
						sb.insert(0, sc.next());
					} else {
						sb.append(sc.next());
					}
				} else {
					if(hantenFlg) {
						sb.append(sc.next());
					} else {
						sb.insert(0, sc.next());
					}
				}
			}
		}
		sb = hantenFlg ? sb: sb.reverse();
		System.out.println(sb.toString());
	}
}
