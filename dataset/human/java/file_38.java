import java.util.*;
import java.io.*;

public class Main {
    public static void printSet(Set<Integer> s){
    	for(int e:s){
    		System.out.print(" "+e);
    	}
    	System.out.println();
    }
    
    public static void make(int N,int K){
    	Set<Integer>[] S = new Set[K];
    	for(int k=0;k<K;k++) S[k] = new HashSet<>();
    	int edgeNum = 1;
    	for(int i=0;i<K;i++) for(int j=i+1;j<K;j++){
    		S[i].add(edgeNum);
    		S[j].add(edgeNum);
    		edgeNum++;
    	}
    	System.out.println(K);
    	for(int k=0;k<K;k++){
    		System.out.print(K-1);
    		printSet(S[k]);
    	}
    }
    
    
    
    public static void solve(int N){
    	for(int k=1; k<100000; k++){
    		if(N == k *(k-1)/2){
    			System.out.println("Yes");
    			make(N,k);
    			return;
    		}
    		else if (N < k*(k-1)/2){
    			System.out.println("No");
    			return;
    		}
    	}
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        solve(N);
    }
}
