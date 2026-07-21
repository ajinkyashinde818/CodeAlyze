import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        long k = sc.nextLong();       
		int [] in = new int [n];
        long [] count = new long [n];       
        for(int i=0;i<n;i++){
                             in[i] = sc.nextInt();
                            }
        count[0]=1;
        long mod = 0;
        int a = 0;
        int point = 1;
        long ans = 0;
        while(a<1){point=in[point-1];
                  count[point-1]++;
                   mod++;
                  if(count[point-1]==2){a=1;}}
        if(k<=mod){point=1;for(long i=0;i<k;i++){point=in[point-1];
                                                        }
                   ans=point;}
 else{long count1=0;
     int point2=1;while(point!=point2){point2=in[point2-1];k--;count1++;}
     for(long i=0;i<k%(mod-count1);i++){point2=in[point2-1];}
     ans=point2;}         
		System.out.println(ans);
}
}
