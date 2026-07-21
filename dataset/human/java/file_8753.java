import java.util.*;
import java.util.stream.*;
import java.util.function.*;

public class Main {
    public static void main(String[] args) throws Exception {
        System.out.println(new Main().solve());
    }
    
    int solve() {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        
        List<Integer> divA = IntStream.rangeClosed(1, a).filter(i -> a % i == 0).boxed()
                        .sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        List<Integer> divB = IntStream.rangeClosed(1, b).filter(i -> b % i == 0).boxed()
                        .sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        divA.retainAll(divB);
        
        return divA.get(k - 1);
    }
}
