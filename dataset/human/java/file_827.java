import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner  yomi = new Scanner(System.in);
        int n = yomi.nextInt();
        int a = yomi.nextInt();
        if (n<10){
            System.out.println(a+(100*(10-n)));
        }else System.out.println(a);
    }
}
