import java.util.Scanner;
class Main{
    public static void main(String[] args) {
        //入力
        Scanner scn=new Scanner(System.in);
        int a=scn.nextInt();
        int b=scn.nextInt();
        int k=scn.nextInt();
        //処理
        int cnt=0;
        int answer=0;
        for(int i=1;i<=Math.max(a,b);i++){
            if(a%i==0&&b%i==0)cnt++;
        }
        int length=cnt;
        cnt=0;
        for(int i=1;;i++){
            if(a%i==0&&b%i==0)cnt++;
            if(cnt==length-k+1){
                answer=i;
                break;
            }
        }
        //出力
        System.out.println(answer);
    }
}
