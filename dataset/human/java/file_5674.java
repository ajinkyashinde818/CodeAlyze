import java.util.*;

public class Main{

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();

        int[] arr = new int[n];

        if (s!=(int)1e9){
            for (int i=0; i<k; i++){
                arr[i] = s;
            }
            for (int i=k; i<n; i++){
                arr[i] = (int)1e9;
            }
        }else {
            for (int i=0; i<k; i++){
                arr[i] = s;
            }
            for (int i=k; i<n; i++){
                arr[i] = 1;
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i=0; i<n; i++){
            sb.append(arr[i]+" ");
        }

        String ans = sb.toString();

        System.out.println(ans);
    }
}
