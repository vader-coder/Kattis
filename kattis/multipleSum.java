/* Function to find the sum of multiples of k from 
k to n.
Uses fact that 1+2+3+...+(n-1)+n = n(n+1)/2 
Can prob prove with induction.
*/
class multipleSum {
    //1+2+3+...+(n-1)+n = n(n+1)/2 
    public static sumOneToN(int n) {
        return ((n+1)*n)/2;
    }
    //let k be an integer and n % k = 0
    //k(1+2+...+(n/k-2)+(n/k-1)+n/k) = k+2k+...(n-2k)+(n-k)+n
    //This is the sum of mutliples of k from k to n.
    //k(1+2+...+(n/k-2)+(n/k-1)+n/k) 
    public static sumKToN(int k, int n) {
        return k*sumOneToN(n/k);//assumes k % n. you must check this yourself. 
    }
}