import java.util.*;
public class Main{
    public static void main(String[] args){
	new Main().run();
    }
    Scanner sc = new Scanner(System.in);

    int n, max;
    boolean[][] map;
    int[][] size;

    void run(){
	while(sc.hasNext()){
	    n = sc.nextInt();
	    if(n==0) break;

	    map = new boolean[n][n];
	    size = new int[n][n];
	    max = 0;

	    for(int i=0; i<n; i++){
		String s = sc.next();
		for(int k=0; k<n; k++){
		    map[i][k] = s.substring(k, k+1).equals(".") ? true : false;
		    if(i==0 || k==0)
			size[i][k] = map[i][k] ? 1 : 0;
		}
	    }
	    

	    for(int i=1; i<n; i++)
		for(int k=1; k<n; k++){
		    if(!map[i][k]) size[i][k] = 0;
		    else
			size[i][k] = Math.min(Math.min(size[i-1][k-1], size[i-1][k]), size[i][k-1]) + 1;
		    max = Math.max(size[i][k], max);
		}
	    // show();
	    System.out.println(max);
	}
    }

    void show(){
	for(int i=0; i<n; i++){
	    for(int k=0; k<n; k++)
		System.out.print(size[i][k]+" ");
	    System.out.println();
	}
    }
}
