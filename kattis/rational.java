import java.util.*;
//import java.util.Queue; 
import java.lang.*;
import java.io.*;

class Rational {
    public int num;
    public int den;
    public int decimal;
    public Rational(int n, int d, int frac) {
        num = n;
        den = d;
        decimal = frac;
    }
    public multiply(int scalar) {
        if (num*scalar % den) {
            num = num*scalar;
            decimal = num/den;
        }
        else {
            num = num*scalar/den;
            den = 1;
        }
    }
}