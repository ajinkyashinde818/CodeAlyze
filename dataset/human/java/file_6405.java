import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int K = Integer.parseInt(scan.next());
        int S = Integer.parseInt(scan.next());
        int cou = 0;

        for(int i = 0;i<=K;i++){
            for(int j = 0;j<=K;j++){
                if(0<=S-i-j&&S-i-j<=K){
                    if(i+j+(S-i-j) == S){
                        cou++;
                    }
                }
            }
        }
        System.out.println(cou);
    }
}
