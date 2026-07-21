import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int A = input.nextInt();
        int B = input.nextInt();
      	int K = input.nextInt();
      
      	if (A > B) {
        	int tmp = A;
          	A = B;
          	B = tmp;
        }
      	int[] ab = new int[A];
      	int index = 0;
      
      	for (int i = 1; i <= A; i++) {
        	if (A % i == 0 && B % i == 0) {
              	ab[index] = i;
              	index++;
            }
        }
      
      System.out.print(ab[index - K]);

    }
}
