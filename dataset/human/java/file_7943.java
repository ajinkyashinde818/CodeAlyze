import java.util.*;

class Main{
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int cnt=0;
        for(int i=0;i<10;i++){
            int a=sc.nextInt();
            cnt+=a;
        }
        System.out.println(cnt);
    }
}
