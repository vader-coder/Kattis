import java.util.*;
//import java.util.Queue; 
import java.lang.*;
import java.io.*;

//Long, String, Int
class MainClass<T> {
    public static void print(T output) {
        System.out.println(output);
    } 
	public static void main (String[] args) {
	    //type[] array = new type[length]
        //System.out.println()
		Scanner scan = new Scanner(System.in);
        //long input = Long.parseLong(scan.nextLine());
		//Queue<Long> output = new LinkedList<Long>();
		int size;
		//System.out.println(factorial(7, 2));
		
		while (scan.hasNextLine()) {
		    //scan.nextLine();
            String input = scan.nextLine();
            int words[] = input.split(' ');
            //input = Long.parseLong(scan.nextLine());
        }
    }
}