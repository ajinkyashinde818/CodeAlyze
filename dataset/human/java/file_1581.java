import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];
		String x = "";
		String y = "";
		for (int i = 0; i < n; i++) {
			a[i] = scan.next();
			x = x + a[i];
		}
		for (int i = 0; i < m; i++) {
			b[i] = scan.next();
			y = y + b[i];
		}
		//System.out.println(x);
		List<Integer> index = new ArrayList<Integer>();

		for (int i = 0,l=0; i < m; i++) {

				if(a[i].contains(b[l])) {
					index.add(i);
					l++;
			}

			}




		//System.out.println(index);
//indexの中身が連番になっていればOK
		boolean hyozi =false;
		for(int i=0, l=index.size()-1;i<index.size()-1;i++,l--) {
			if(index.get(i)+1==index.get(i+1)) {
				hyozi =true;

				//降順になってるとき
			}else if(index.get(l)+1==index.get(l-1)){
				hyozi = true;
			}else {
				hyozi = false;
			}
		}

		if(m==n) {
		int count=0;
		for (int i = 0; i < n; i++) {
			if(a[i].equals(b[i])) {
				count++;
			}
			}

		if(count == a.length) {
			hyozi = true;
		}else {
			hyozi=false;
		}
		}

		if (hyozi == true) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
