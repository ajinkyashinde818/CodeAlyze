import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int ans = 0;
        for(int i = 1 ; i <= x ; i *= 2)
            ans = i;
        System.out.println(ans);
    }
}
