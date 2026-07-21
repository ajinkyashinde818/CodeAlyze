import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int count = 0;
        int i = sc.nextInt();
        for (int i1 = 0; i1 < i; i1++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if(l == r){
                count++;
                if(count >= 3){
                    System.out.println("Yes");
                    return;
                }
            }else{
                count = 0;
            }
        }
        System.out.println("No");
    }
}
