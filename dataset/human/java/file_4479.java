import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        long count;
        long A = Integer.parseInt(scanner.next());
        long B = Integer.parseInt(scanner.next());
        long C = Integer.parseInt(scanner.next());

        if ( A + B + 1 >= C ){
            count = B + C;
        }else{
            count = B * 2 + A + 1;
        }

        System.out.println(count);
    }
}
