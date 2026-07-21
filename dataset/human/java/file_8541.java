import java.util.*;
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int cnt = 0;
        int ans = 0;

        if(a >= b){
            for(int i = a;i > 0;i--){
                if(a%i == 0 && b%i == 0){
                    ans = i;
                    cnt++;
                    if(cnt == k)
                    break;
                }
            }
        }else{
            for(int i = b;i > 0;i--){
                if(a%i == 0 && b%i == 0){
                    ans = i;
                    cnt++;
                    if(cnt == k)
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
