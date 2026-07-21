import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;
public class Main {


    public static void main(String[] args) {


        Scanner scan = new Scanner(System.in);
       int K=scan.nextInt();
        int N=scan.nextInt();
        int A[]=new int [N];

for(int i=0;i<N;i++){A[i]=scan.nextInt();}

        Arrays.sort(A);
int M=0;
for(int i1=0;i1<N-1;i1++){if(A[i1+1]-A[i1]>M){M=A[i1+1]-A[i1];}}
if(A[0]+K-A[N-1]>M){M=A[0]+K-A[N-1];}
int L=K-M;
        System.out.println(L);


    }

}
