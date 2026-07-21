import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long n_ = n;
        List<Integer> prime = new ArrayList<>();
        int[] fact = new int[10000000];
        for(int i=2;i<9999999;i++){
            if(n_ % i == 0){
                prime.add(i);   //素因数
            }
            while(n_ % i == 0){
                n_ /= i;
                fact[i]++;      //実際に何乗しているか
            }
            if(n_ == 1){
                break;
            }
        }
        if(n == 1){
            System.out.println(0);
        }else if(prime.isEmpty()){    //素数だった時
            System.out.println(1);
        }else {
            int count = n_ == 1 ? 0 : 1;    //割り切れてない場合素数が残っている
            for (int p : prime) {
                int i = 1;
                while (i <= fact[p]) {
                    fact[p] -= i;
                    i++;
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
