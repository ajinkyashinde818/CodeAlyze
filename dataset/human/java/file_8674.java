import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sn = new Scanner(System.in);
        int a = sn.nextInt();
        int b = sn.nextInt();
        int k = sn.nextInt();
        
        List<Integer> commonDiviserList = new ArrayList<>();
        int c = a > b ? b : a;
        for (int i = c; i >= 1; i--){
            if(a % i == 0 && b % i == 0){
                commonDiviserList.add(i);
            }
        }
        
        System.out.println(commonDiviserList.get(k - 1));        
    }
}
