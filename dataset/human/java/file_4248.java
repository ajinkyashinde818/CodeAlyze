import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n-1];
        int sum = 0;
        for(int i=0;i<n;i++){
            a[i] = Integer.parseInt(sc.next())-1;
        }
        for(int i=0;i<n;i++){
            b[i] = Integer.parseInt(sc.next());
        }
        for(int i=0;i<n-1;i++){
            c[i] = Integer.parseInt(sc.next());
        }
        sc.close();
        int prev = -2;
        for(int i=0;i<n;i++){
            sum+=b[a[i]];
            if(a[i] - prev == 1){
                sum+=c[prev];
            }
            prev = a[i];
        }
        System.out.println(sum);
    }
}
