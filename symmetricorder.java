import java.util.*;
//import java.util.Queue; 
import java.lang.*;
import java.io.*;

//accomplishes task in O(n) time.

//class to keep track of each set using stacks and queues
class Set {
    private boolean addToFrontNext = true;
    private Stack<String> back = new Stack<String>();
    private Queue<String> front = new LinkedList<String>();
    private int set;
    public Set(int setNum) {
        set = setNum;
    }
    public void add(String input) {
        if (addToFrontNext) {//add to end of queue for front
            front.add(input);
        }
        else {//add to to of Stack for back
            back.push(input);
        }
        addToFrontNext = !addToFrontNext;
    }
    //print out values for front, followed by values in back.
    public void print() {
        System.out.println("SET "+ Integer.toString(set));
        while (!front.isEmpty()) {
            System.out.println(front.remove());
        }
        while (!back.isEmpty()) {
            System.out.println(back.pop());
        }
    }
}

//Long, String, Int
class symmetricorder {
    public static boolean isInteger( String input ) {
        try {
            Integer.parseInt( input );
            return true;
        }
        catch( NumberFormatException e ) {
            return false;
        }
    }
    public static void printSets(Queue<Set> sets) {
        Set currentSet;
        while (!sets.isEmpty()) {
            currentSet = sets.remove();
            currentSet.print();
        }
    } 
	public static void main (String[] args) {
	    //type[] array = new type[length]
        //System.out.println()
		Scanner scan = new Scanner(System.in);
        Queue<Set> sets = new LinkedList<>();//create queue of sets
        Set currentSet = null;//keep track of current set	
		int setCounter = 0;
        while (scan.hasNextLine()) {
            String input = scan.nextLine();
            if (isInteger(input)) {
                int setNum = Integer.parseInt(input);
                if (setNum != 0) {
                    setCounter++;
                    currentSet = new Set(setCounter);
                    sets.add(currentSet);
                }
                else {
                    break;
                }
            }
            else if (currentSet != null) {//not integer, then add line to current Set
                currentSet.add(input);
            }
            //input = Long.parseLong(scan.nextLine());
        }
        //print every set
        printSets(sets);
    }
}