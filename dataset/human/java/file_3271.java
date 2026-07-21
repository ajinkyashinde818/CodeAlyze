import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        for(int i = 0; i < String.valueOf(s).length();i++){
            if(String.valueOf(s).charAt(i) == '9'){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
