import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int k = s.nextInt();
        int n = s.nextInt();

        int arr[] = new int[n];
        Arrays.sort(arr);

        for(int i = 0 ; i < n ; i++)
        arr[i] = s.nextInt();

        int max = 0;

        for(int i = 1 ; i < n ; i++){
            max = Math.max(arr[i]-arr[i-1],max);
        }
        int last = k - arr[n-1] + arr[0] - 0;
        max = Math.max(last, max);

        System.out.println(k-max);
    }
}
