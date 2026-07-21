import java.util.*;
import java.lang.*;
import java.io.*;
class Main
{
    public static String function(int [][]arr){
        for(int i = 0; i < arr.length - 2; i++){
          if(arr[i][0] == arr[i][1] && arr[i + 1][0] == arr[i + 1][1] && arr[i + 2][0] == arr[i +  2][1])
            return "Yes";
        }
      return "No";
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
	    try{
		BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
		int T= Integer.parseInt(reader.readLine());
        int [][]arr = new int[T][2];
		for(int i = 0; i < T; i++){
		    String []str=reader.readLine().split(" ");
		    arr[i][0]=Integer.parseInt(str[0]);
		    arr[i][1]=Integer.parseInt(str[1]);
		}
        System.out.println(function(arr));
	    }
	    catch( Exception e){
	        return ;
	    }
	}
}
