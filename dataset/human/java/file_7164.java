import java.util.*;
import java.util.stream.Stream;

public class Main {//ここが Main になっている
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line1, line2;
        int[] k_n_array = new int[2];
        line1 = sc.nextLine();
        line2 = sc.nextLine();
        String[] k_n_s = line1.split(" ");
        int K = Integer.parseInt(k_n_s[0]);
        int N = Integer.parseInt(k_n_s[1]);

        k_n_s = line2.split(" ");
        // System.out.println(Arrays.asList(k_n_s));
        int[] A_int = Stream.of(k_n_s).mapToInt(Integer::parseInt).toArray();
        // System.out.println(A_int.length);
        int[] diff_A = new int[A_int.length];
        for (int i=0;i<A_int.length-1;i++){
            diff_A[i] = A_int[i+1] - A_int[i];
        }
        diff_A[A_int.length-1] = K - A_int[A_int.length-1] + A_int[0];

        int max = diff_A[0];
        int min = diff_A[1];
        for (int i = 1; i < diff_A.length; i++) {
            int v = diff_A[i];
            if (v > max) {
                max = v;
            }
            if (v < min) {
                min = v;
            }
        }
        System.out.println(K - max);

    }
}




// Scanner sc = new Scanner(System.in);
// String line1, line2;
// int[] k_n_array = new int[2];
// line1 = sc.nextLine();
// line2 = sc.nextLine();
// String[] k_n_s = line1.split(" ");
// int K = Integer.parseInt(k_n_s[0]);
// int N = Integer.parseInt(k_n_s[1]);
//
// // System.out.println(K+" "+N);
//
// k_n_s = line2.split(" ");
// // System.out.println(Arrays.asList(k_n_s));
// int[] A_int = Stream.of(k_n_s).mapToInt(Integer::parseInt).toArray();
// int ist_most_large = 1;
// // System.out.println(A_int.length);
//
// while (true) {
//     int now_distance = A_int[A_int.length - ist_most_large] - A_int[0];
//     // System.out.println(now_distance);
//     ist_most_large++;
//     if (ist_most_large >= A_int.length){
//         System.out.println(now_distance);
//         break;
//     }
//     int next_distance = K - A_int[A_int.length - ist_most_large] + A_int[0];
//     if (next_distance >= now_distance){
//       System.out.println(now_distance);
//       break;
//     }
//     else{
//         now_distance = next_distance;
//         // break;
//     }
//
// }
