/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//https://atcoder.jp/contests/abc169/tasks/abc169_d
//package pkg21.days.of.code;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.*;
/**
 *
 * @author Pravash Ranjan
 */
 class Main {
    static class FastReader{BufferedReader br;StringTokenizer st;public FastReader(){br = new BufferedReader(new InputStreamReader(System.in));}String next(){ while (st == null || !st.hasMoreElements()){try{st = new StringTokenizer(br.readLine());}
        catch (IOException  e){e.printStackTrace();}}return st.nextToken();}int nextInt(){return Integer.parseInt(next());}long nextLong(){return Long.parseLong(next());} 
        double nextDouble(){return Double.parseDouble(next());}String nextLine(){String str = ""; try{str = br.readLine();}catch (IOException e){e.printStackTrace();}return str;}}
    public static void main(String args[])
    {
        FastReader ob=new FastReader();
        ArrayList<Integer> prm=new ArrayList<>();
        int size=(int)1e6+2;
        boolean prime[]=new boolean[(int)1e6+2];
        for(int i=2;i*i<size;i++)
        {
            for(int j=i*i;j<size;j+=i)
                prime[j]=true;
        }
        for(int i=2;i<size;i++)
            if(!prime[i])
                prm.add(i);
        long n=ob.nextLong();
        long m=n;
        HashMap<Long,Integer> map=new HashMap<>();
        int c=0;long x;int cnt=0;int sz=prm.size();
        //System.out.println((long)prm.get(sz-1)*999983L);
        while(n!=1)
        {
            if(c>=sz)
                break;
           x=prm.get(c);
           if(x*x>n)
               break;
           c++;cnt=0;
           while(n%x==0)
           {
               n/=x;cnt++;
           }
           if(cnt!=0)
               map.put((long)x,cnt);
           
        }
        if(n!=1)
            map.put(n,1);
        long ans=0;int sum=0;long j;
        for(long i:map.keySet())
        {
            for(j=1;(j*(j+1))/2<=map.get(i);j++);
            ans+=(j-1);            
        }
        if(m==1)
            System.out.println(0);
        else
            System.out.println(ans);
    }
}
