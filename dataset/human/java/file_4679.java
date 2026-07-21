import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] c = sc.next().toCharArray();
        int[] currency = new int[c.length+1];
        int ans = 0;
        int borrow = 0;
        int tmp = 0;
        for(int i=c.length-1;i>=0;i--){
            tmp = c[i]-'0'+borrow;
            if(tmp < 5){
                currency[i+1] = tmp;
                ans+=tmp;
                borrow = 0;
            }else if(tmp == 5){
                if(i>=1 && c[i-1] >='5'){
                    borrow = 1;
                }else{
                    currency[i+1] = tmp;
                    borrow = 0;
                    ans+=tmp;
                }
            }else if(tmp<=9){
                borrow = 1;
            }else if(tmp==10){
                borrow = 1;
            }
        }
        if(borrow==1){
            ans++;
            currency[0] = 1;
        }
        borrow = 0;
        for(int i=c.length-1;i>=0;i--){
            tmp = currency[i+1] - (c[i] - '0') - borrow;
            if(tmp < 0){
                tmp  = tmp + 10;
                borrow = 1;
            }else{
                borrow = 0;
            }
            ans+=tmp;
        }
        System.out.println(ans);
    }
}
