import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int max = (int)Math.pow(10,9);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        //int ans = new int[n];
        for(int i = 0; i < k; i++){
            System.out.print(s + " ");
        }
        for(int i = k; i < n; i++){
            if(s == max){
                System.out.print(1 + " ");
            }else{
                System.out.print(s+1 + " ");
            }
        }
    }
}
