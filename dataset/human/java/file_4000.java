import java.util.Scanner;

public class Main {
    public static boolean debug = true;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] no = new int[n];
        for(int i=0;i<n;i++){
            no[i] = sc.nextInt();
        }

        int[] manzoku = new int[n];
        for(int i=0;i<n;i++){
            manzoku[i] = sc.nextInt();
        }

        int[] plus = new int[n-1];
        for(int i=0;i<n-1;i++){
            plus[i] = sc.nextInt();
        }

        int sum = 0;

        int temp = -99;
        for(int i=0;i<n;i++){
            int now = no[i];
            sum += manzoku[now-1];

            if(temp == now-1){
                sum += plus[temp-1];
            }

            temp = now;

        }

        System.out.println(sum);


    }

    public static void d(String message){
        if(debug){
            System.out.println(message);
        }
    }
}
