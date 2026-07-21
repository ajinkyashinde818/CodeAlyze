import java.util.Scanner;




public class Main {

    public static void main(String[] args) {

    	Main main=new Main();

    	main.run();

    }

    void run() {
    	Scanner sc=new Scanner(System.in);

    	int N=sc.nextInt();
    	int M=sc.nextInt();

    	String[][] A=new String[N][N];

    	for(int i=0;i<N;i++) {
    		A[i]=sc.next().split("");
    	}

    	String[][] B=new String[M][M];

    	for(int i=0;i<M;i++) {
    		B[i]=sc.next().split("");
    	}

    	int set=N-M;

    	for(int x=0;x<=set;x++) {
    		
    		for(int y=0;y<=set;y++) {
    			boolean isMatch=true;
    			for(int i=0;i<M;i++) {
    				for(int j=0;j<M;j++) {
    					if(!A[x+i][y+j].equals(B[i][j])) {
    						isMatch=false;
    					}
    				}
    			}

    			if(isMatch) {
    				System.out.println("Yes");
    				return;
    			}

    		}
    	}

    	System.out.println("No");

    }

}
