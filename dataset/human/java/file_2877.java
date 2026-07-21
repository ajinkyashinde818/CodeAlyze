//Volume0-0082
import java.util.Scanner;

public class Main {

	private static final int S = 8;

	public static void main(String[] args) {

		//declare
		String[] s;
		int      i,j,m,msum,mmin,maxi;
		int[]    p = new int[S];
		int[][]  c = {{1,2,1,2,1,4,1,4}, //ascending order
				      {1,2,1,4,1,4,1,2},
                      {1,4,1,2,1,2,1,4},
                      {1,4,1,4,1,2,1,2},
                      {2,1,2,1,4,1,4,1},
                      {2,1,4,1,4,1,2,1},
                      {4,1,2,1,2,1,4,1},
			          {4,1,4,1,2,1,2,1}};

        //input
        Scanner sc = new Scanner(System.in);
        while((sc.hasNext())){
        	s = sc.nextLine().split("\\s");
        	for(i=0;i<S;i++){p[i] = Integer.parseInt(s[i]);}

        	//calculate
        	mmin = Integer.MAX_VALUE;
        	maxi = 0;
        	for(i=0;i<S;i++){
            	msum = 0;
        		for(j=0;j<S;j++){
        			m = p[j] - c[i][j];
        			if(m>0){msum += m;}
        		}
        		if(mmin > msum){
        			mmin = msum;
        			maxi = i;
        		}
        	}

        	//output
        	for(i=0;i<S;i++){
        		System.out.print(c[maxi][i]);
        		if(i<S-1){
        			System.out.print(" ");
        		} else {
        			System.out.println();
        		}
        	}
        }
	}
}
