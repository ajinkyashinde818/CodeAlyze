import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a  = sc.nextInt();
        int b  = sc.nextInt();
        int k  = sc.nextInt();
        int big = 0;
        if(a<b){
            big = a;
        }else{
            big = b;
        }
        List<Integer> list = new ArrayList<>();
        for(int i=big;i>=1;i--) {
            if (a % i == 0 && b % i == 0) {
                list.add(i);

            }
        }
        if(list.size() != 0){
            System.out.println(list.get(k-1));
        }else{
            System.out.println(0);
        }
    }
}
