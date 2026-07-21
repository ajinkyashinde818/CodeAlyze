import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		String s = sc.next();
		int count = sc.nextInt();
		StringBuffer result = new StringBuffer(s);
		boolean outputflg = true;
		Map<Integer, String> map = new HashMap<Integer,String>();
		int start,end;
		start=0;
		end =0;
		map.put(0, s);
		for(int i=0;i<count;i++) {
			int type = sc.nextInt();
			if (type == 1) {
				outputflg = !outputflg;
			} else {
				int f = sc.nextInt();
				String c = sc.next();
				if ((f==1&&outputflg)||((f==2&&!outputflg))) {
					map.put(start-1 , c);
					start--;
				} else {
					map.put(end+1, c);
					end++;
				}
			}
		}
		if (outputflg) {
			for (int i=start;i<=end;i++) {
				System.out.print(map.get(i));
			}
		} else {
			for (int i=end;i>=start;i--) {
				if (i==0) {
					System.out.print(new StringBuffer(map.get(i)).reverse());
				} else {
					System.out.print(map.get(i));
				}
			}
		}

	}
}
