import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        //int K = sc.nextInt();
        //long N = sc.nextLong();

        int[] A = new int[N];
        int[] B = new int[N];
        int count=0;
        for(int i=0; i<N; i++){
            A[i]=sc.nextInt();
            B[i]=sc.nextInt();
            if(A[i]==B[i]){
                count++;
            }else{
                count=0;
            }
            if(count==3){
                System.out.println("Yes");
                return;
            }
        }
        

        
        System.out.println("No");
        }
    }
