import java.util.Scanner;

public class Main {
    static Scanner stdIn = new Scanner(System.in);
    public static void main(String[] args){
        int n = stdIn.nextInt();
        int[] d1 = new int[n];
        int[] d2 = new int[n];
        for(int i=0; i<n; i++){
            d1[i] = stdIn.nextInt();
            d2[i] = stdIn.nextInt();
        }

        for(int i=0; i<n-2; i++){
            if((d1[i] == d2[i]) && (d1[i+1] == d2[i+1]) && (d1[i+2] == d2[i+2])){
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");
    }
}
