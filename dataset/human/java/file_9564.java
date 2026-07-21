import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int N = scn.nextInt();
        int count = 0;
        for(int i=0; i<N; i++) {
            int a = scn.nextInt();
            int b = scn.nextInt();
            if(a == b) {
                count++;
            } else {
                count = 0;
            }
            if(count == 3) {
                break;
            }
        }
        if(count == 3) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
