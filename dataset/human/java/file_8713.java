import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int count = 0;
        int[] comd = new int[Math.min(a,b)];
        for(int i = 1; i <= Math.min(a,b); i++){
            if(a%i == 0 && b%i == 0){
                comd[count] = i;
                count++;
            }
        }
        System.out.print(comd[count-k]);
    }
}
