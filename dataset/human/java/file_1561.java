import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		char[][] matrix1 = new char[100][];
		char[][] matrix2 = new char[100][];
		
		int i , j , n , m;
		n = scan.nextInt();
		m = scan.nextInt();
		
		for (i = 0;i < n;i ++) {
			String input = scan.next();
			matrix1[i] = input.toCharArray();
		}
		
		for (i = 0;i < m;i ++) {
			String input = scan.next();
			matrix2[i] = input.toCharArray();
		}
		
		boolean result = false;
		for (i = 0;i + m - 1 < n;i ++)
			for (j = 0;j + m - 1 < n;j ++) {
				if (equals(matrix1 , matrix2 , i , j)) {
					result = true;
				}
			}
		if (result)
			System.out.println("Yes");
		else
			System.out.println("No");
		
	}
	
	private static boolean equals(char[][] matrix1 , char[][] matrix2 , int x1 , int y1) {
		
		int i , j , n = matrix1[0].length , m = matrix2[0].length;
		for (i = 0;i < m;i ++)
			for (j = 0;j < m;j ++) {
				char ch1 = matrix1[x1 + i][y1 + j];
				char ch2 = matrix2[i][j];
				if (ch1 != ch2)
					return false;
			}
		return true;
		
	}
	
}
