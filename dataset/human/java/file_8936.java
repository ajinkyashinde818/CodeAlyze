import java.util.*;
import java.io.*;
class Program{

}
class Main{
    public static void main(String args[]) throws IOException{
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt(), B = sc.nextInt(), K = sc.nextInt();
    int small = Math.min(A,B), big = Math.max(A,B);
    ArrayList <Integer> fact = new ArrayList<Integer>();
    for(int i = 1;i<=(int)Math.sqrt(small);i++){
        if (small%i==0){
            if(big%i==0){
                fact.add(i);
            }
            if (big%(small/i)==0 && i!=small/i) fact.add(small/i);
            
        }
    }
    Collections.sort(fact);
    Collections.reverse(fact);
    //System.out.println(fact);
    System.out.println(fact.get(K-1));
    }
}
