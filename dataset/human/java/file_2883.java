import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()) {
			int[] p = new int[8];
			for(int i = 0; i < 8; i++) {
				p[i] = sc.nextInt();
			}

			String t = "555555555";
			int max = 0;
			int[] c = {4, 1, 4, 1, 2, 1, 2, 1};
			for(int i = 0; i < 8; i++) {
				int v = 0;
				for(int j = 0; j < 8; j++) {
					v += Math.min(p[j], c[(i + j) % 8]);
				}
				if(max < v) {
					String g = "";
					for(int j = 0; j < 8; j++) {
						g += Integer.toString(c[(i + j) % 8]);
					}
					max = v;
					t = g;
				}else if(max == v) {
					String g = "";
					for(int j = 0; j < 8; j++) {
						g += Integer.toString(c[(i + j) % 8]);
					}
					if(t.compareTo(g) > 0) {
						t = g;
					}
				}
			}
			for(int i = 0; i < 8; i++) {
				if(i == 7) {
					System.out.println(t.charAt(i));
				}else {
					System.out.print(t.charAt(i) + " ");
				}
			}
		}
		sc.close();
	}
}
