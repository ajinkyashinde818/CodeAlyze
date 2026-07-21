import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt();
        int R=sc.nextInt();
        if(N<10){
            pl(100*(10-N)+R);

        }
        else{
            pl(R);
        }
    }
    public static void pl(Object o){
        System.out.println(o);
    }
    public static void p(Object o){
        System.out.println(o);
    }
}
