import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> num = new ArrayList<Integer>();
		ArrayList<String> param = new ArrayList<String>();
		int system = 0; // 文字の空白区切り 0:ON 1:OFF

		while (sc.hasNext()) {
			if (sc.hasNextInt()) {
				num.add(sc.nextInt());
			} else {
				if (system == 0)
					param.add(sc.next());
				if (system == 1)
					param.add(sc.nextLine());
			}
		}
		Method(num, param);
	}

	static void Method(ArrayList<Integer> num, ArrayList<String> param) {
		int[] n = new int[100];
		for(int i = 0; i <num.size(); i++){
			n[i] = num.get(i);
		}
		String[] p = new String[100];
		for(int i = 0; i <param.size(); i++){
			p[i] = param.get(i);
		}
		////////////////////////////////////////////////////////////////////
		int point = -1;
		boolean flag = false;
		
		for(int i = 0; i <= n[0] - n[1]; i++){
			//System.out.println(p[n[0]] + " " + p[i]);
			point = p[i].indexOf(p[n[0]],point+1);
			//System.out.println(point);
			if(point == -1) continue;
			if(n[1] == 1){
				flag = true;
				break;
			}
			for(int k = 1; k < n[1]; k++){
				//System.out.println((p[i + k]) + " " + p[n[0] + k]);
				if(point != (p[i + k]).indexOf(p[n[0] + k],point)) break;
				//System.out.println(point);
				if(k == n[1]-1) flag = true;
			}
		}
		if(flag){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		
	}
}
