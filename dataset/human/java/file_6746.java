import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int b = sc.nextInt(); 
        int a = sc.nextInt();
		int [] in = new int [a];
        int [] in2 = new int [a];
        int c = 0;
        for(int i=0;i<a;i++){
                             in[i] = sc.nextInt();
                            }
		for(int i=0;i<a-1;i++){
                               in2[i] = in[i+1]-in[i];
                              }
		in2[a-1] = b+in[0]-in[a-1];
        Arrays.sort(in2);
		System.out.println(b-in2[a-1]);
	}
}
