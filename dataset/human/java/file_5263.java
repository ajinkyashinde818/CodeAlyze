import java.util.Scanner;

public class Main {
	private Scanner sc;
	
	private int n;
	private int[][] map;
	public static void main(String[] args) {
		new Main();
	}
	
	public Main() {
		sc = new Scanner(System.in);

		while (sc.hasNextLine() == true) {
			n = Integer.parseInt(sc.nextLine());
			if (n == 0) break;
	
			map = new int[n][n];
			for (int i = 0; i < n; i++) {
				String line = sc.nextLine();
				
				int width = 0;
				for (int j = 0; j < n; j++) {
					int index = n - j - 1;
					
					if (line.charAt(index) == '*') width = 0;
					else width++;
					
					map[i][index] = width;
				}
			}
			
			int max = 0;
			for (int j = 0; j < n; j++) {
				boolean flag = true;
				while (flag == true) {
					flag = false;

					int height = 0;
					for (int i = 0; i < n; i++) {
						if (map[i][j] > max) {
							height++;
							
							if (height == (max + 1)) {
								max++;
								flag = true;
								break;
							}
						} else {
							height = 0;
						}
					}
				}
			}
			System.out.println(max);
		}
	}
}
