// Java program For handling Input/Output 
import java.io.*; 
import java.util.*;
import java.math.*;
//import java.awt.*;

public class Main 
{ 
    Scanner sc;
    Map<Integer, List<Integer>> graph = new HashMap<>();
    //actual logic
    void solve(){
        long a = nl();
        long b = nl();
        long hcf = hcf(a, b);
        System.out.println((a*b)/hcf);
    }

    long hcf(long a, long b)
    {
        if(a == 0)
            return b;
        else
            return hcf(b%a, a);
    }

    //constructor
    Main(){
        try{  
            sc = new Scanner(System.in);
        }catch(Exception e){
            System.out.println(e);
        }
    }


    //main metohd
    public static void main(String[] args) 
    { 
     new Main().solve();
 }


    //Utility methods
 void graphInput(int n)
 {
    for(int i = 0;i < n;i++)
    {
        int a = ni();
        int b = ni();

        if(!graph.containsKey(a))
        {
            List<Integer> l = new ArrayList<>();
            l.add(b);
            graph.put(a, l);
        }
        else
            graph.get(a).add(b);
    }
    System.out.println(graph);
}

void bfs(int nodes)
{
    Queue<Integer> q = new LinkedList<>();
    int visited[] = new int[nodes+1];

    q.add(1);
    while(!q.isEmpty())
    {
        System.out.print(q.peek() + " ");
        visited[q.peek()] = 1;
        if(graph.get(q.peek()) != null)
        {
            for(int i: graph.get(q.peek()))
            {
                if(visited[i] != 1)
                    q.add(i);
            }
        }

        q.poll();
    }
}
        //input an integer from scanner
int ni()
{
    int a = sc.nextInt();
    return a;
}
        //input a long from scanner
long nl()
{
    return sc.nextLong();
}
        //input a float from scanner
float nf(){
    float a = sc.nextFloat();
    return a;
}
        //input a double from scanner
double nd(){
    double a = sc.nextDouble();
    return a;
}
        //input a sentence from scanner
String ns(){
    return sc.nextLine();
}
        //converts a string to stringtokenizer
StringTokenizer nst(String s){
    return new StringTokenizer(s);
}
        //input an intger array
void ia(int a[]){
    for(int i = 0;i < a.length;i++)
        a[i] = sc.nextInt();
}
        //
void la(long a[]){
    for(int i = 0;i < a.length;i++)
        a[i] = sc.nextLong();
}
        //input a float array
void fa(float a[]){
    for(int i = 0;i < a.length;i++)
        a[i] = sc.nextFloat();
}
        //input a double array
void da(double a[]){
    for(int i = 0;i < a.length;i++)
        a[i] = sc.nextDouble();
}
        //input a string array either with all empty input or from scanner
void sa(String a[], boolean empty){
    if(empty)
    {
        for(int i = 0;i < a.length;i++)
        {
            a[i] = "";
        }
    }
    else
    {
        for(int i = 0;i < a.length;i++)
        {
            a[i] = ns();
        }
    }
}
        //input two dimensional integer array
void ida(int a[][], int n, int m)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            a[i][j] = ni();
        }
    }
}
        //input two dimentional long array
void lda(long a[][], int n, int m)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            a[i][j] = nl();
        }
    }
}
        //input two dimensional double array
void dda(double a[][], int n, int m)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            a[i][j] = nd();
        }
    }
}
        //convert string to integer
int stoi(String s){
    return Integer.parseInt(s);
}
        //convert string to double
double stod(String s){
    return Double.parseDouble(s);
}
        //find minimum in a long array
long lmin(long a[])
{
    long min = Long.MAX_VALUE;
    for(int i = 0;i < a.length;i++)
    {
        if(min > a[i])
            min = a[i];
    }
    return min;
}
        //find minimum in a integer array
int imin(int a[])
{
    int min = Integer.MAX_VALUE;
    for(int i = 0;i < a.length;i++)
    {
        if(min > a[i])
            min = a[i];
    }
    return min;
}
        //find maximum in a long array
long lmax(long a[])
{
    long max = Long.MIN_VALUE;
    for(int i = 0;i < a.length;i++)
    {
        if(max < a[i])
            max = a[i];
    }
    return max;
}
        //find maximum in an integer array
int imax(int a[])
{
    int max = Integer.MIN_VALUE;
    for(int i = 0;i < a.length;i++)
    {
        if(max < a[i])
            max = a[i];
    }
    return max;
}
        //check whether an element is present in an integer array by binary search
boolean ibs(int a[], int toFind)
{
    Arrays.sort(a);
    int min = 0;
    int max = a.length-1;
    boolean found = false;

    while(min <= max && !found)
    {
        int mid = min + (max-min)/2;
        if(a[mid] == toFind)
        {
           found = true;
       }
       else if(toFind > a[mid])
       {
        min = mid+1;
    }
    else
    {
        max = mid-1;
    }

}
return found;
}
        //check whether an element is present in a long array
boolean lbs(long a[], long toFind)
{
    Arrays.sort(a);
    int min = 0;
    int max = a.length-1;
    boolean found = false;

    while(min <= max && !found)
    {
        int mid = min + (max-min)/2;
        if(a[mid] == toFind)
        {
           found = true;
       }
       else if(toFind > a[mid])
       {
        min = mid+1;
    }
    else
    {
        max = mid-1;
    }

}
return found;
}

int stb(String s)
{
    int sum = 0;
    int k = 0;
    for(int i = s.length()-1;i >= 0;i--)
    {
        sum += stoi(s.charAt(i)+"") * Math.pow(2, k++);
    }
    return sum;
}

}
