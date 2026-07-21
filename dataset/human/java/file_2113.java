import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long n=Long.parseLong(br.readLine());
        ArrayList<Integer> a=new ArrayList<>();
        for(long i=2;i*i<=n;i++){
            int count=0;
            while(n%i==0){
                count++;
                n/=i;
//                System.out.println(i);
            }
            if(count!=0){
                a.add(count);
            }
        }
        if(n!=1){
            a.add(1);
        }
//        System.out.println(a.toString());
        int ans=0;
        for(int k:a){
            int count=0;
            int temp=0;
            for(int i=1;i<=k;i++){
                temp+=i;
                if(temp>k){
                    break;
                }
                count++;
            }
            ans+=count;
        }
        System.out.println(ans);
    }
}
