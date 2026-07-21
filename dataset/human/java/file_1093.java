import java.util.*;
import java.io.*;
public class Main {

	public static void main(String[] args) throws Exception{
		int num = 998244353;

		// TODO Auto-generated method stub
 		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
 		PrintWriter out = new PrintWriter(System.out);
 		int n = Integer.parseInt(bf.readLine());
 		StringTokenizer st = new StringTokenizer(bf.readLine());
 		int[] array = new int[n];
 		for(int j =0;j<n;j++){
 			array[j] = Integer.parseInt(st.nextToken());
 		}
 		StringTokenizer st1 = new StringTokenizer(bf.readLine());
 		int[] newarray = new int[n];
 		for(int j = 0;j<n;j++){
 			newarray[n-1-j] = Integer.parseInt(st1.nextToken());
 		}
 		int start = Integer.MAX_VALUE;
 		int end = -1;
 		int val = 0;
 		for(int j =0;j<n;j++){
 			if (array[j] == newarray[j]){
 				start = Math.min(start,  j);
 				val = array[j];
 				end = Math.max(end,  j);
 			}
 		}
 		
 		int curr = 0;
 		ArrayList<Integer> indices = new ArrayList<Integer>();
 		for(int j = 0;j<n;j++){
 			if ((j < start || j > end) && array[j]!= val && newarray[j]!= val){
 				indices.add(j);
 			}
 		}
 		if (indices.size() >= end-start+1){
 			out.println("Yes");
 			for(int j = start;j<=end;j++){
 				//swap indices.get(j-start) and j
 				int temp = newarray[j];
 				newarray[j] = newarray[indices.get(j-start)];
 				newarray[indices.get(j-start)] = temp;
 			}
 			for(int j : newarray){
 				out.print(j + " ");
 			}
 			out.println();
 		}
 		else{
 			out.println("No");
 		}
 		
 		
 		
 		out.println();
	 		
 		out.close();
 		
 		
 		
 	}
}
 	
 
//StringJoiner sj = new StringJoiner(" "); 
//sj.add(strings)
//sj.toString() gives string of those stuff w spaces or whatever that sequence is
