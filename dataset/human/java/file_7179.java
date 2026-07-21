import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int k=sc.nextInt();
        int N=sc.nextInt();
        int[] arr=new int[N];
        int max=0;
        for (int i=0;i<N;i++){
            arr[i]=sc.nextInt();
            if (i>1){
                max = Math.max(arr[i] - arr[i - 1], max);
            }
        }
        max =  Math.max(k - arr[(N - 1)] + arr[0], max);
        System.out.println(k-max);
    }

}
