import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String nr = sc.nextLine();

        int N = Integer.parseInt(nr.split(" ")[0]);
        int R = Integer.parseInt(nr.split(" ")[1]);

        if(10 <= N){
            System.out.println(R);
        } else {
            System.out.println(R + (100 * (10 - N)));
        }

    }
}
