import java.util.*;
//import java.util.Queue; 
import java.lang.*;
import java.io.*;
//does dyanmic programming version.
//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1#
class fibonnaci {
	public static void main (String[] args) {
        Solution soln = new Solution();
        Queue<Long> ans = new LinkedList<Long>();
        for (int i =0; i<args.length; i++) {
            int n = Integer.parseInt(args[i]);
            ans.add(soln.nthFibonacci(n));
        }
        for (int i =0; i<args.length; i++) {
            System.out.println(ans.remove());
        }
    }
}

class Solution {
    //item i represents (i+1)th number in fibbonnaci sequence 
    public ArrayList<Long> sequence;
    //private long nMinus1Term = 1;
    //private long nMinus2Term = 1;
    public Solution () {
        sequence = new ArrayList<Long>();
    }///was satatic
    public static long nthFibonacci(int n){
        if (n == 1) {
            return 0;
        }
        else if (n ==2 || n == 3) {
            return 1;
        }
        else {
            Solution soln = new Solution();
            return soln.dynamicFibonnaci(n, soln.sequence);
        }
    }
    //nth fib number is at nth spot in fib
    //build up array sequence.
    public long dynamicFibonnaci(int n, ArrayList<Long> sequence) {
        if (sequence.size() >= n) {
            return sequence.get(n-1);//return nth item
        }
        else {//nth position at n-1
            buildSequence(n, sequence);
            return dynamicFibonnaci(n, sequence);
        }
    }
    public static void buildSequence(long n, ArrayList<Long> sequence) {
        long nMinus1Term = 1L;
        long nMinus2Term = 0L;//0, 1, 1. from 3rd term to nth term
        if (sequence.isEmpty()) {
            sequence.add(nMinus2Term);
            sequence.add(nMinus1Term);
        }//containing 2 at least
        for (int i=sequence.size(); i<n+1; i++) {//term 0 has 1st term, term n-1 has nth term
            nMinus1Term = sequence.get(i-1);
            nMinus2Term = sequence.get(i-2);
            sequence.add(nMinus1Term+nMinus2Term);
        }
    }
    public static long recursiveFibonacci(long n){
        if (n == 1L) {
            return 0L;
        }
        else if (n ==2L || n == 3L) {
            return 1L;
        }
        else {
            return recursiveFibonacci(n-1L) + recursiveFibonacci(n-2L);
        }
    }
}