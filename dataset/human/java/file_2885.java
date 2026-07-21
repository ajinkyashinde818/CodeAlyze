import java.util.Scanner;

public class Main {
	
	public static int[][] array = {
		{1 , 2 , 1 , 2 , 1 , 4 , 1 , 4 },
		{1 , 2 , 1 , 4 , 1 , 4 , 1 , 2 },
		{1 , 4 , 1 , 2 , 1 , 2 , 1 , 4 },
		{1 , 4 , 1 , 4 , 1 , 2 , 1 , 2 },
		{2 , 1 , 2 , 1 , 4 , 1 , 4 , 1 },
		{2 , 1 , 4 , 1 , 4 , 1 , 2 , 1 },
		{4 , 1 , 2 , 1 , 2 , 1 , 4 , 1 },
		{4 , 1 , 4 , 1 , 2 , 1 , 2 , 1 }
	};
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int[] input = new int[8];
			String[] str = sc.nextLine().split(" ");
			
			for(int i = 0; i < 8; i++){
				input[i] = Integer.parseInt(str[i]);
			}
			
			int[] edit = new int[8];
			int min = Integer.MAX_VALUE;
			int min_num = -1;
			for(int i = 0; i < 8; i++){
				for(int j = 0; j < 8; j++){
					edit[j] = input[j] - array[i][j];
					if(edit[j] < 0){
						edit[j] = 0;
					}
				}
				
				int sum = 0;
				for(int j = 0; j < 8; j++){
					sum += edit[j]; 
				}
				
				if(min > sum){
					min = sum;
					min_num = i;
				}
			}
			
			boolean first = true;
			for(int i = 0; i < 8; i++){
				System.out.print(first ? array[min_num][i] : " "+array[min_num][i]);
				if(first == true){
					first = false;
				}
			}
			System.out.println();
			
		}
		
	}
	
}
