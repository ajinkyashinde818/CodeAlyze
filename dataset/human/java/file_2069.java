import java.io.*;
import java.util.*;
import java.math.*;
import java.util.stream.Collectors;
import java.util.stream.*;


public class Main { 
    
    public static void main(String[] args) throws java.lang.Exception { 
        Reader pm =new Reader(); 
        //Scanner pm = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = 1;
        while(t-- > 0){
            long n = pm.nextLong();
            HashMap<Long, Integer> hm = new HashMap<>();
            
            while (n%2==0) { 
                hm.merge(2L,1,Integer::sum);
                n /= 2; 
            } 
      
            // n must be odd at this point.  So we can 
            // skip one element (Note i = i +2) 
            for (long i = 3; i <= Math.sqrt(n); i+= 2){ 
                // While i divides n, print i and divide n 
                while (n%i == 0) { 
                    hm.merge(i,1,Integer::sum);
                    n /= i; 
                } 
            } 
      
            // This condition is to handle the case whien 
            // n is a prime number greater than 2 
            if (n > 2) 
                hm.merge(n,1,Integer::sum);
                
            int ans = 0;
            Set<Long> st = hm.keySet();
            for(Long i:st){
                int pow = hm.get(i);
                int cnt = 0;
                //System.out.println(i+" "+pow);
                while(true){
                    cnt++;
                    pow-=cnt;
                    if(pow < 0){
                        cnt--;
                        break;
                    }
                    if(pow == 0)
                        break;
                }
                ans += cnt;
            }
            
            System.out.println(ans);

        }
    }
        
    
    public static int findClosest(int arr[], int target) { 
        int n = arr.length; 
  
        // Corner cases 
        if (target <= arr[0]) 
            return arr[0]; 
        if (target >= arr[n - 1]) 
            return arr[n - 1]; 
  
        // Doing binary search  
        int i = 0, j = n, mid = 0; 
        while (i < j) { 
            mid = (i + j) / 2; 
  
            if (arr[mid] == target) 
                return arr[mid]; 
  
            /* If target is less than array element, 
               then search in left */
            if (target < arr[mid]) { 
         
                // If target is greater than previous 
                // to mid, return closest of two 
                if (mid > 0 && target > arr[mid - 1])  
                    return getClosest(arr[mid - 1],  
                                  arr[mid], target); 
                  
                /* Repeat for left half */
                j = mid;               
            } 
  
            // If target is greater than mid 
            else { 
                if (mid < n-1 && target < arr[mid + 1])  
                    return getClosest(arr[mid],  
                          arr[mid + 1], target);                 
                i = mid + 1; // update i 
            } 
        } 
  
        // Only single element left after search 
        return arr[mid]; 
    } 
  
    // Method to compare which one is the more close 
    // We find the closest by taking the difference 
    //  between the target and both values. It assumes 
    // that val2 is greater than val1 and target lies 
    // between these two. 
    public static int getClosest(int val1, int val2, int target) { 
        if (target - val1 >= val2 - target)  
            return val2;         
        else 
            return val1;         
    } 
    static int count(Integer arr[], int x, int n,int l,int r,int cur) { 
      // index of first occurrence of x in arr[0..n-1]     
      int i;  
        
      // index of last occurrence of x in arr[0..n-1] 
      int j;  
           
      /* get the index of first occurrence of x */
      i = first(arr, 0, n-1, x, n,cur); 
       
      /* If x doesn't exist in arr[] then return -1 */
      if(i == -1) 
        return i; 
          
      /* Else get the index of last occurrence of x.  
         Note that we are only looking in the  
         subarray after first occurrence */  
      j = last(arr, i, n-1, x, n,cur);      
      
      System.out.println(x+" "+i+" "+j);
      /* return count */
      return j-i+1; 
    } 
       
    /* if x is present in arr[] then returns the  
       index of FIRST occurrence of x in arr[0..n-1],  
       otherwise returns -1 */
    static int first(Integer arr[], int low, int high, int x, int n,int cur) 
    { 
      if(high >= low) 
      { 
        /*low + (high - low)/2;*/  
        int mid = (low + high)/2;   
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x && mid != cur) 
          return mid; 
        else if(x > arr[mid]) 
          return first(arr, (mid + 1), high, x, n,cur); 
        else
          return first(arr, low, (mid -1), x, n,cur); 
      } 
      return -1; 
    } 
       
    /* if x is present in arr[] then returns the  
       index of LAST occurrence of x in arr[0..n-1],  
       otherwise returns -1 */
    static int last(Integer arr[], int low, int high, int x, int n,int cur) 
    { 
      if(high >= low) 
      { 
        /*low + (high - low)/2;*/      
        int mid = (low + high)/2;  
        if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x && mid != cur) 
          return mid; 
        else if(x < arr[mid]) 
          return last(arr, low, (mid -1), x, n,cur); 
        else
          return last(arr, (mid + 1), high, x, n,cur);       
      } 
      return -1; 
    } 
       
    // function to count elements within given range 
    static int countInRange(int arr[], int n, int x, int y) { 
        // initialize result 
        int count = 0; 
        count = upperIndex(arr, n, y) -  
                lowerIndex(arr, n, x) + 1; 
        return count; 
    } 
    
    
    static int lowerIndex(int arr[], int n, int x) { 
        int l = 0, h = n - 1; 
        while (l <= h)  
        { 
            int mid = (l + h) / 2; 
            if (arr[mid] >= x) 
                h = mid - 1; 
            else
                l = mid + 1; 
        } 
        return l; 
    } 
      
    // function to find last index <= y 
    static int upperIndex(int arr[], int n, int y) { 
        int l = 0, h = n - 1; 
        while (l <= h)  
        { 
            int mid = (l + h) / 2; 
            if (arr[mid] <= y) 
                l = mid + 1; 
            else
                h = mid - 1; 
        } 
        return h; 
    }
    
    public static StringBuilder dec_to_bin(long n) {
        // decimal to binary upto 30 binaries
        if(n==0) {
            StringBuilder str=new StringBuilder("");
            for(int i=0;i<30;i++) {
                str.append("0");
            }
            return str;
        }
        StringBuilder str=new StringBuilder("");
        while(n!=0) {
            str.append(n%2L);
            n/=2L;
        }
        str=str.reverse();
        StringBuilder tmp_str=new StringBuilder("");
        int len=str.length();
        while(len!=30) {
            tmp_str.append("0");
            len++;
        }
        tmp_str.append(str);
        return tmp_str;
    }
    
    private static int binarySearchPM(int[] arr, int key){
        int n = arr.length;
        int mid = -1;
        int begin = 0,end=n;
        while(begin <= end){
            mid = (begin+end) / 2;
            if(mid == n){
                return n;
            }
            if(key < arr[mid]){
                end = mid-1;
            } else if(key > arr[mid]){
                begin = mid+1;
            } else {
                return mid;
            }
        }
        //System.out.println(begin+" "+end);
        return -begin; //expected Index
    }
    
    private static List<Integer> setToList(Set<Integer> s){
        List<Integer> al = s.stream().collect(Collectors.toList());
        return al;
    }
    
    private static List<Integer> mapValToList(HashMap<Integer,Integer> map){
        return map.values().stream().collect(Collectors.toList());
    }
    
    private static List<Integer> mapKeyToList(HashMap<Integer,Integer> map){
        return map.keySet().stream().collect(Collectors.toList());
    }
    
    private static HashMap<Integer, Integer> sortByKey(HashMap<Integer,Integer> map){
        return map
                .entrySet()
                .stream()
                .sorted(Map.Entry.comparingByValue())
                .collect(Collectors.toMap(
                    Map.Entry::getKey, 
                    Map.Entry::getValue, 
                    (oldValue, newValue) -> oldValue, LinkedHashMap::new));
    }
    
    static class Reader { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    }
}
