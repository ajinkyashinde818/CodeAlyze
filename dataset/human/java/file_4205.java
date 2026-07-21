import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner n = new Scanner(System.in);
        int N = n.nextInt();
        int a[] = new int[N];
        int b[] = new int[N];
        int c[] = new int[N-1];
        String A[] = new String[N];
        String B[] = new String[N];
        String C[] = new String[N-1];
        int sum = 0;
        for(int i=0;i<N;i++){
            A[i] = n.next();
            a[i] = Integer.parseInt(A[i]);
        }
        for(int i=0;i<N;i++){
            B[i] = n.next();
            b[i] = Integer.parseInt(B[i]);
        }
        for(int i=0;i<N-1;i++){
            C[i] = n.next();
            c[i] = Integer.parseInt(C[i]);
        }
        for(int i=0;i<N;i++){
            sum += b[a[i]-1];
            if(i<N-1){
                if(a[i]==a[i+1]-1){
                    sum += c[a[i]-1];
                } 
            }
        }
        n.close();
        System.out.println(sum);
    }
}
