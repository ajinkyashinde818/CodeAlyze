import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        List<Integer> A = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        List<Integer> B = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        List<Integer> C = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

//        System.out.println(A.toString());
//        System.out.println(B.toString());
//        System.out.println(C.toString());
        int sum = 0;
        int pre = A.get(0);
        for (Integer a : A) {
            sum += B.get(a - 1);
//            System.out.println(sum);
            if (pre == a - 1) {
//                System.out.println("continue");
                sum += C.get(a - 2);
            }
            pre = a;
        }
        System.out.println(sum);
    }
}
