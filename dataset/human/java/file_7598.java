import java.util.Map;
import java.util.Scanner;
public class Main {


    public static void main(String[] args) {


        Scanner scan=new Scanner(System.in);
        int N=scan.nextInt();

        int A[]=new int[N];
        int B[]=new int[N];
        int C[]=new int[N];

        long K=scan.nextLong();

        int i=0;
        while (i<N){A[i]=scan.nextInt()-1;
        i=i+1;

        }
        int p=0;
        int R=0;
        if(K>N*2) {
            while (C[p] <= 2) {
                C[p] = C[p] + 1;
                if (C[p] == 2) {
                    R = R + 1;
                }
                ;
                p = A[p];
                K = K - 1;

            }
            K = K % R;
        }
        int i2=0;

       while(K>0){
               p=A[p];
       K=K-1;



       }
        System.out.println(p+1);
    }

       }
