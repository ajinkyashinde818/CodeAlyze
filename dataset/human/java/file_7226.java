import java.util.*;
class Main{
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args){
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A =new int[N];
        int[] differ=new int[N];
        for(int i=0;i<N;i++)
            A[i] = sc.nextInt();
        Arrays.sort(A);
        for(int i=0;i<N;i++){
            if(i==(N-1))
            differ[i]=K-(A[i]-A[0]);
            else
            differ[i]=A[i+1]-A[i];
        }
        Arrays.sort(differ);
        System.out.println(K-differ[N-1]);
    }
}
