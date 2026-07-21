import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] args){
      	
		Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < A.length; i++) {
            A[i] = sc.nextInt();
        }
        
        int kyori_a = A[N-1]-A[0];
        int Aminus[] = new int[N];
        for (int i = 0; i < A.length; i++) {
            Aminus[i] = K-A[i];
        }
        int kyori_b = K;
        for (int i = 0; i < Aminus.length-1; i++) {
            kyori_b = Aminus[i+1] +A[i];
            if (kyori_a > kyori_b) {
                kyori_a = kyori_b;
            }
        }
        System.out.println(kyori_a);
      	sc.close();
    }
		

}
