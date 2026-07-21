import java.util.*;
public class Main {
    public static int max(int a, int b){return (a > b ? a : b);}
    public static int min(int a, int b){return (a < b ? a : b);}
    public static int gcd(int a, int b){return (b > 0 ? gcd(b, a % b) : a);}
    public static int lcm(int a, int b){return a / gcd(a, b) * b;}
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int cnt = 0;
        List<Long>A = new ArrayList<Long>();
        for(int i = 0; i < N; i++){
            Long a = sc.nextLong();
            if(a < 0){
                cnt ^= 1;
                a = -a;
            }
            A.add(a);            
        }        
        Collections.sort(A);
        if(cnt > 0)A.set(0, -A.get(0));
        Long ans = 0L;
        for(int i = 0; i < A.size(); i++)ans += A.get(i);
        System.out.print(ans);
    }
}
