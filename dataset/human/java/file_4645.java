import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			final int m = sc.nextInt();
			final int n = sc.nextInt();
			
			if(m == 0 && n == 0){
				break;
			}
			
			int[] books = new int[n];
			for(int i = 0; i < n; i++){
				books[i] = sc.nextInt();
			}
			
			int upper = 1000000 * n;
			int lower = 1;
			
			while((upper - lower) != 1){
				int med = (upper + lower) / 2;
				
				//System.out.println(med);
				
				int col = 0;
				int wid = 0;
				boolean flag = true;
				for(int i = 0; i < n; i++){
					if(col >= m){
						flag = false;
						break;
					}
					
					if(wid + books[i] > med){
						col++;
						i--;
						wid = 0;
					}else{
						wid += books[i];
					}
				}
				
				if(!flag){
					lower = med;
				}else{
					upper = med;
				}
			}
			
			System.out.println(upper);
		}

	}

}
