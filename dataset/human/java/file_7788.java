import java.util.*;
 
import java.io.*;
 
public class Main{
	public static void main(String[] $){
		Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        long K = s.nextLong();
        int[] A = new int[N];
        for(int i = 0; i < N; i++){
            A[i] = s.nextInt();
        }
        HashMap<Integer, Boolean> hash = new HashMap<Integer, Boolean>();
        List<Integer> amari = new ArrayList<Integer>();
        int[] noroop = new int[N];
        int i = 1;
        do{
            amari.add(i);
            hash.put(i, true);
            i = A[i-1];
        }while(hash.get(i) == null);
        int roopPrev = amari.indexOf(i);
        int[] rooping = new int[N];
        for(int j = 0; j < roopPrev; j++){
            noroop[j] = amari.get(j);
        }

        for(int j = roopPrev; j < amari.size(); j++){
            rooping[j-roopPrev] = amari.get(j);
        }

        int roopN = amari.size()-roopPrev;
        if(K >= roopPrev){
            System.out.println(rooping[(int)((K-roopPrev)%roopN)]);
        }else{
            System.out.println(noroop[(int)K]);
        }
        
	}
}
