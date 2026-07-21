import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();

        List<Integer> commonDivisor = new ArrayList<Integer>();
        for(int i = 1; i <= Math.min(A,B); i++){
            if(A % i == 0 && B % i == 0){
                commonDivisor.add(i);
            }
        }

        int index = commonDivisor.size() - K;
        out.println(commonDivisor.get(index));
    }
}
