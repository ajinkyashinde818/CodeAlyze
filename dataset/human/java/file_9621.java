import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
        int attempt = in.nextInt();
        int[][] diceArr = new int[attempt][2];
        for (int i = 0; i < attempt; i++) {
            diceArr[i][0] = in.nextInt();
            diceArr[i][1] = in.nextInt();
        }
        int counter = 0;
        for (int i = 0; i < attempt; i++) {
            if (counter == 3) {
                break;
            } else if (diceArr[i][0] == diceArr[i][1]) {
                counter++;
            } else {
                counter = 0;
            }
        }
        if (counter >= 3) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        in.close();
    }
}
