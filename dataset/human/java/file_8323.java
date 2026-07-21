import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        long a = sc.nextInt();
        long b = sc.nextInt();

        long tmp;

        long c = a;
        c *= b;

        while ((tmp=a%b)!=0){
            a = b;
            b = tmp;
        }

        System.out.println(c/b);

    }

}
