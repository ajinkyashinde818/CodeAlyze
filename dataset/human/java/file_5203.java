import static java.lang.Integer.*;
import static java.lang.Long.parseLong;
import static java.lang.Short.parseShort;
import static java.lang.Byte.parseByte;
import java.io.*;
import java.util.*;

public class Main {

    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static short nextShort() throws IOException {
        return parseShort(next());
    }

    static byte nextByte() throws IOException {
        return parseByte(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens())
            tok = new StringTokenizer(in.readLine());
        return tok.nextToken();
    }

    static String nextLine() throws IOException {
        return in.readLine();
    }

    private static BufferedReader in;
    private static StringTokenizer tok;
    private static PrintWriter out = new PrintWriter(System.out);
    private static Utilities doThis = new Utilities(out);
    private static MyMath doMath = new MyMath();
    private static NextPermutation permute = new NextPermutation();
    private static MergeSort mergeSort = new MergeSort();

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new InputStreamReader(System.in));

        /*--------------------SolutionStarted-------------------*/
        solve();
        /*--------------------SolutionEnded--------------------*/

        in.close();
        out.close();
    }

    static int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    static long longMax = Long.MAX_VALUE, longMin = Long.MIN_VALUE, longSum = 0, longCount;

    static void solve() throws IOException {
        LinkedList<Character> string = new LinkedList<>();
        char[] str = next().toCharArray();

        for (int i = 0; i <str.length ; i++) {
            string.add(str[i]);
        }

        int q = nextInt();
        boolean state = true;
        for (int i = 0; i <q ; i++) {
            int t = nextInt();
            if (t==1){
                state=!state;
            }else{
                int f = nextInt();
                char c = next().toCharArray()[0];
                if (f==1){
                    if (state){
                        string.addFirst(c);
                    }else{
                        string.addLast(c);
                    }
                }else {
                    if (state) {
                        string.addLast(c);
                    } else {
                        string.addFirst(c);
                    }
                }
            }
        }
        if (state){
            while(!string.isEmpty()){
                out.print(string.remove());
            }
        }else{
            while(!string.isEmpty()){
                out.print(string.removeLast());
            }
        }
    }
}
class Kruskal{
    private int[] link;
    private int[] size;
    Kruskal(int[] link, int[] size) {
        this.link = link;
        this.size = size;
        init(this.link);
        init(this.size);
    }
    private void init(int[] arr){
        for (int i = 0; i <arr.length ; i++) {
            arr[i] = i;
        }
    }
    public int find(int x){
        while(x!=link[x])
            x = link[x];
        return x;
    }

    public boolean same(int a, int b){
        return find(a) == find(b);
    }
    public void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (size[a] < size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        size[a] += size[b];
        link[b] = a;
    }
}
class IntegerPair implements Comparable<IntegerPair>{
    //This class must be immutable
    int first;
    int second;
    int value;
    private final int HASH;
    private final String STRING;

    private IntegerPair(int first, int second){
        this.first = first;
        this.second = second;
        STRING = first+" "+second;
        HASH = STRING.hashCode();
    }

    static IntegerPair of(int first, int second){
        return new IntegerPair(first, second);
    }

    @Override
    public boolean equals(Object o){
        if(o == null)
            return false;
        if (! (o instanceof IntegerPair))
            return false;
        if (this == o)
            return true;

        IntegerPair other =(IntegerPair) o;
        if(first == other.first && second == other.second)
            return true;
        return false;
    }

    @Override
    public int compareTo(IntegerPair other) {
        if (second == other.second)
            return first - other.first;
        return second - other.second;
    }

    @Override
    public int hashCode(){
        return HASH;
    }

    @Override
    public String toString(){
        return STRING;
    }
}
class Utilities {
    PrintWriter out;
    Utilities(PrintWriter out){
        this.out = out;
    }
    //int arrays start
    int lowerBound(int[] arr, int low, int high, int element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (low < arr.length && arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(int[] arr, int low, int high, int element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (low<arr.length && arr[low] <= element)
            return -1;
        return low;
    }
    //int arrays end
    //long arrays start
    int lowerBound(long[] arr, int low, int high, long element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (low < arr.length && arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(long[] arr, int low, int high, long element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (low<arr.length &&arr[low] <= element)
            return -1;
        return low;
    }
    //long arrays end
    //double arrays start
    int lowerBound(double[] arr, int low, int high, double element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (element > arr[middle])
                low = middle + 1;
            else
                high = middle;
        }
        if (arr[low] < element)
            return -1;
        return low;
    }

    int upperBound(double[] arr, int low, int high, double element) {
        int middle;
        while (low < high) {
            middle = low + (high - low) / 2;
            if (arr[middle] > element)
                high = middle;
            else
                low = middle + 1;
        }
        if (arr[low] <= element)
            return -1;
        return low;
    }
    //double arrays end
    int arrUp(int [][]arr,int i, int j){
        if(i<=0)
            return Integer.MIN_VALUE;
        return arr[i-1][j];
    }
    int arrDown(int [][]arr,int i, int j){
        if(i>=arr.length-1)
            return Integer.MIN_VALUE;
        return arr[i+1][j];
    }
    int arrLeft(int [][]arr,int i, int j){
        if(j<=0)
            return Integer.MIN_VALUE;
        return arr[i][j-1];
    }
    int arrRight(int [][]arr,int i, int j){
        if(j>=arr[i].length-1)
            return Integer.MIN_VALUE;
        return arr[i][j+1];
    }
    //////////////////

    char arrUp(char [][]arr,int i, int j){
        if(i<=0)
            return '\0';
        return arr[i-1][j];
    }
    char arrDown(char [][]arr,int i, int j){
        if(i>=arr.length-1)
            return '\0';
        return arr[i+1][j];
    }
    char arrLeft(char [][]arr,int i, int j){
        if(j<=0)
            return '\0';
        return arr[i][j-1];
    }
    char arrRight(char [][]arr,int i, int j){
        if(j>=arr[i].length-1)
            return '\0';
        return arr[i][j+1];
    }
    int count(char[] s, char c){
        int count = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i]==c)
                count++;
        }
        return count;
    }
    void swap(char[] s, int a,int b){
        char temp =s[b];
        s[b]= s[a];
        s[a] = temp;
    }
    void yes(){
        out.println("YES");
    }
    void no() {
        out.println("NO");
    }
    void bad(){
        out.println(-1);
    }
}
class MyMath {
    boolean isCoPrime(int a, int b) {
        return gcd(a, b) == 1;
    }

    int gcd(int a, int b) {
        int temp;
        while(b!=0){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    long gcd(long a, long b) {
        long temp;
        while(b!=0){
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    int log2(int x) {
        return (int) (Math.log(x) / Math.log(2));
    }
    boolean[] sieveOfEratosthenes(int n) {
        // Create a boolean array "primes[0..n]" and initialize
        // all entries it as true. A value in primes[i] will
        // finally be false if i is Not a primes, else true.
        boolean primes[] = new boolean[n+1];
        for(int i=0;i<n;i++)
            primes[i] = true;

        for(int p = 2; p*p <=n; p++)
        {
            // If primes[p] is not changed, then it is a primes
            if(primes[p])
            {
                // Update all multiples of p
                for(int i = p*p; i <= n; i += p)
                    primes[i] = false;
            }
        }
        return primes;
    }
}
class NextPermutation {

    // Function to swap the data
    // present in the left and right indices
    private int[] swap(int data[], int left, int right) {

        // Swap the data
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        // Return the updated array
        return data;
    }

    // Function to reverse the sub-array
    // starting from left to the right
    // both inclusive
    private int[] reverse(int data[], int left, int right) {

        // Reverse the sub-array
        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        // Return the updated array
        return data;
    }

    // Function to find the next permutation
    // of the given integer array
    boolean findNextPermutation(int data[]) {

        // If the given data-set is empty
        // or contains only one element
        // next_permutation is not possible
        if (data.length <= 1)
            return false;

        int last = data.length - 2;

        // find the longest non-increasing suffix
        // and find the pivot
        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        // If there is no increasing pair
        // there is no higher order permutation
        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        // Find the rightmost successor to the pivot
        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        // Swap the successor and the pivot
        data = swap(data, nextGreater, last);

        // Reverse the suffix
        data = reverse(data, last + 1, data.length - 1);

        // Return true as the next_permutation is done
        return true;
    }
}
class MergeSort {
    // Merges two subarrays of arr[].
    // First subarray is arr[l..m]
    // Second subarray is arr[m+1..r]
    void merge(int arr[], int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        int L[] = new int[n1];
        int R[] = new int[n2];

        /*Copy data to temp arrays*/
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Main function that sorts arr[l..r] using
    // merge()
    void sort(int[] arr){
        sort(arr, 0, arr.length-1);
    }
    void sort(int arr[], int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = (l + r) / 2;

            // Sort first and second halves
            sort(arr, l, m);
            sort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
}



class BinarySearchTree<T extends Comparable<T>> {
    private class Node<T extends Comparable<T>> {
        private Node left, right;
        T data;

        Node(T data) {
            this.data = data;
        }

        void insert(T data) {
            if (this.data.compareTo(data) >= 0) {
                if (right == null) {
                    right = new Node(data);
                } else {
                    right.insert(data);
                }
            } else {
                if (left == null) {
                    left = new Node(data);
                } else {
                    left.insert(data);
                }
            }
        }

        boolean contains(T data) {
            if (this.data.equals(data)) {
                return true;
            } else if (this.data.compareTo(data) > 0) {
                if (right == null)
                    return false;
                return right.contains(data);
            } else {
                if (left == null)
                    return false;
                return left.contains(data);
            }
        }
        void printInOrder(){
            if(right !=null){
                right.printInOrder();
            }
            System.out.println(data);
            if (left != null){
                left.printInOrder();
            }
        }
    }

    private Node root;
    private int nodes;
    BinarySearchTree(T data) {
        setRoot(data);
    }

    BinarySearchTree(){

    }
    public void setRoot(T data){
        if(root != null)
            throw new IllegalStateException();
        root = new Node(data);
        nodes++;
    }
    public void insert(T data) {
        root.insert(data);
        nodes++;
    }

    public boolean contains(T data) {
        return root.contains(data);
    }
    public void printInOrder(){
        root.printInOrder();
    }
}
