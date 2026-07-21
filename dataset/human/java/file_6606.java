import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static int def = 10000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int x = sc.nextInt();
		int y = sc.nextInt();
		List<Integer> listx = new ArrayList<>();
		List<Integer> listy = new ArrayList<>();
		boolean turn = false;
		int step = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == 'F') {
				step++;
			} else {
				if(turn) {
					listy.add(step);
				} else {
					listx.add(step);
				}
				step = 0;
				turn = !turn;
			}
		}
		if(turn) {
			listy.add(step);
		} else {
			listx.add(step);
		}
		boolean[] ansx = new boolean[2 * def];
		boolean[] ansy = new boolean[2 * def];
		for(int i = 0; i < 2 * def; i++) {
			ansx[i] = false;
			ansy[i] = false;
		}
		ansx[listx.get(0) + def] = true;
		listx.remove(0);
		ansy[def] = true;
		for(int i = 0; i < listx.size(); i++) {
			int value = listx.get(i);
			boolean[] tmp = new boolean[2 * def];
			for(int j = 0; j < 2 * def; j++) {
				tmp[j] = false;
			}
			for(int j = 0; j < 2 * def; j++) {
				if(ansx[j]) {
					tmp[j + value] = true;
					tmp[j - value] = true;
				}
			}
			for(int j = 0; j < 2 * def; j++) {
				ansx[j] = tmp[j];
			}
		}
		for(int i = 0; i < listy.size(); i++) {
			int value = listy.get(i);
			boolean[] tmp = new boolean[2 * def];
			for(int j = 0; j < 2 * def; j++) {
				tmp[j] = false;
			}
			for(int j = 0; j < 2 * def; j++) {
				if(ansy[j]) {
					tmp[j + value] = true;
					tmp[j - value] = true;
				}
			}
			for(int j = 0; j < 2 * def; j++) {
				ansy[j] = tmp[j];
			}
		}
		if(ansx[x + def] && ansy[y + def]) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
