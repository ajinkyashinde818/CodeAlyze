import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int[] num = new int[101];
        int cnt = 0;

        for(int i =1;i<101;i++){
            if(a%i==0 && b%i==0){
                cnt++;
                num[cnt] = i;
                //System.out.println(i);
            }
        }

        System.out.println(num[cnt-k+1]);
      
    }
}
