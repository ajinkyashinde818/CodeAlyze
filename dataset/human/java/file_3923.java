import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);

		while (true) {
			final int n = Integer.parseInt(sc.nextLine());
			
			if(n == 0){
				break;
			}
			
			char[][] map = new char[n][];
			for(int i = 0; i < n; i++){
				map[i] = sc.nextLine().toCharArray();
			}
			
			LinkedList<Integer> stack = new LinkedList<Integer>();
			for(int i = n - 1; i >= 0; i--){
				int pos = 0;
				if(map[i][pos] != '.') { continue; }
				
				while(pos < map[i].length && map[i][pos] == '.'){
					pos++;
				}
				
				final int height = pos - 1;
				
				
				while(!stack.isEmpty()){
					if(stack.getLast() >= height){
						stack.removeLast();
					}else{
						break;
					}
				}
				
				for(int high : stack){
					map[i][high] = '|';
				}
				map[i][height] = '+';
				for(int j = 0; j < height; j++){
					if(map[i][j] == '.') { map[i][j] = ' '; }
				}
				
				stack.addLast(height);
			}
			
			for(int i = 0; i < n; i++){
				System.out.println(map[i]);
			}
		}
	}
}
