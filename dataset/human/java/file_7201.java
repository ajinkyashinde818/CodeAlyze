import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);

        int k = stdIn.nextInt();
        int n = stdIn.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = stdIn.nextInt();
        }

        int max = 0;
        int sub;
        for(int i=0; i<n-1; i++){
            sub = a[i+1] - a[i];
            if(sub > max){
                max = sub;
            }
        }
        sub = (a[0] + k) - a[n-1];
        if(sub > max){
            max = sub;
        }

        System.out.println(k-max);
    }
}
