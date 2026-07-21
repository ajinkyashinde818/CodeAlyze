import java.util.Scanner;
  
public class Main {
	public static void main(String[] args) {
    	Scanner s = new Scanner(System.in);
      	int n = s.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n - 1];
      
      	int score = 0;
      
      	for (int i = 0; i < n; i++) {
        	a[i] = s.nextInt();
        }
      
      	for (int i = 0; i < n; i++) {
        	b[i] = s.nextInt();
        }
      
      	for (int i = 0; i < n - 1; i++) {
        	c[i] = s.nextInt();
        }
      
      	int index = 0;
      	for (int i = 0; i < n; i++) {
			if (i > 0 && index == a[i] - 1) score += c[a[i] - 2];
        	score += b[a[i] - 1];
			index = a[i];
        }
      	System.out.println(score);
    }
}
