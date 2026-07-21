import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int seq = 0;
        boolean yes = false;
        for(int i=0; i<n; i++) {
            int d1 = in.nextInt();
            int d2 = in.nextInt();
            if(d1==d2) {
                seq++;
                if(seq>=3) {
                    yes = true;
                }
            }
            else {
                seq = 0;
            }
        }
        System.out.println(yes ? "Yes" : "No");
    }
}
