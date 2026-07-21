import java.io.IOException;
import java.util.Scanner;

public class Main {
    static class Solution {
        public void find(int perimeter, int[] arr) {

            arr[arr.length-1] = perimeter;

            int res = Integer.MAX_VALUE;
            int antiClock = (arr[0] + perimeter)%perimeter;

            res = Math.min(res, perimeter-(perimeter - arr[arr.length-2])- antiClock);
            res = Math.min(res, perimeter - (arr[1]-arr[0]));

            for(int i=1; i<arr.length-1; i++) {
                res = Math.min(res, perimeter - (arr[i+1]-arr[i])); //clock
                res = Math.min(res, perimeter - (arr[i]-arr[i-1])); //anti
            }
            System.out.println(res);

        }

    }

    public static void main(String[] args) throws IOException {
        Solution sol = new Solution();
        Scanner sc = new Scanner(System.in);
        int perimeter = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n+1];
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }
        sol.find(perimeter, arr);
    }
}
