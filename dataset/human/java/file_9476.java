import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a, b;
        int me[][] = new int [3][2];
        int flg = 0;
        for(int i = 0; i < n; i++){
            a = sc.nextInt();
            b = sc.nextInt();
            me[i % 3][0] = a;
            me[i % 3][1] = b;
            if(i > 1){
                if(me[0][0] == me[0][1] && me[1][0] == me[1][1] && me[2][0] == me[2][1]){
                    System.out.println("Yes");
                    flg += 1;
                    break;
                }
            }
        }
        if(flg == 0){
            System.out.println("No");
        }
    }
}
