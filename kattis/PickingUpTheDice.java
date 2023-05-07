import java.util.*;
//import java.util.Queue; 
import java.lang.*;
import java.io.*;

class PickingUpTheDice {
    public static void main(String[] args) {
        /*Tests tests = new Tests();
        tests.testCombos();*/
        Probability soln = new Probability();
        //print(soln.probability(3, 9));//target 9, die 3.
        //print(soln.probability(4, 13));
        print(soln.probability(18, 90-63));
        //print(soln.probability(6, 21));
        
        //print(soln.solve(3, 9));//target 9, prob 3.
        //print(soln.solve(4, 13));
        //print(soln.solve(18, 90));
        //print(soln.solve(6, 21));
    }
    public static void print(int n) {
        System.out.println(n);
    }
    public static void print(double n) {
        System.out.println(n);
    }
}

class Probability {
    private Combos combo;
    private int target;
    private int dice;
    Probability() {
        combo = new Combos();
    }
    //get # dice that maximizes chance
    public int solve(int dice, int target) {
        double maxProbability = 0, probability;
        int maxProbDie = 0;
        double combos, totalCombos;
        double targetD = target;
        int minDie = (int)Math.ceil(targetD/6.0);//minimum possible die we can use
        //double combosD, totalCombosD;
        for (int die = minDie; dice <= dice; die++) {
            combos = Double.valueOf(combo.comboSum(target, die));
            totalCombos = Math.pow(6, die);
            probability = combos/totalCombos;
            if (probability > maxProbability) {
                maxProbability = probability;
                maxProbDie = die;
            }
        }
        return maxProbDie;
    }
    public double probability(int die, int target) {
        double combos = (double) combo.comboSum(target, die);
        double totalCombos = Math.pow(6, die);
        return combos/totalCombos;
    }

}

class Combos {
    //recursive function to calculate number of combinations summing to target
    private Table table;
    private boolean wasInTable = false;
    public Combos() {
        table = new Table();//contains 1-6 already.
    }
    //dynamic version
    public int comboSum(int target, int dice) {
        int value = table.get(target, dice);
        if (value >= 1) {
            return value;
        }
        else {//-1, doesn't exist
            if (dice == 1) {
                table.add(target, dice, 0);
                return 0;
            }
            else {
                int combos;
                int comboCount = 0;
                for (int diceInt = 1; diceInt <= 6; diceInt++) {
                    combos = comboSum(target-diceInt, dice-1);
                    comboCount += combos;
                }
                table.add(target, dice, comboCount);
                return comboCount;
            }
        }
    }
    public int recursiveComboSum(int target, int dice) {
        if (dice == 1) {
            if (target >= 1 && target <= 6) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            int combos;
            int count = 0;
            for (int diceInt = 1; diceInt <= 6; diceInt++) {
                combos = recursiveComboSum(target-diceInt, dice-1);
                count += combos;
            }
            return count;
        }
    }
}


//class to test all our others individually
//use jetbrains for this.s
class Tests {
    public static void testTable () {
        Table tb = new Table();
        checkEquals(tb.get("6 1"), 1);
        checkEquals(tb.get("7 1"), -1);
        checkEquals(tb.get(7, 1), -1);
        tb.add(7, 2, 2);
        //we do not want these to be equivalent
        checkEquals(tb.get(7, 2), 2);
        checkEquals(tb.get(2, 7), -1);
    }
    public static void testCombos() {
        Combos cm = new Combos();
        int combo = cm.comboSum(6, 2);
        int combo2 = cm.comboSum(24, 2);
        checkEquals(combo, 5);
        checkEquals(combo2, 0);
        System.out.println(combo);
        System.out.println(combo2);
    }
    public static void checkEquals(int one, int two) {
        if (one != two) {
            System.out.println(Integer.toString(one) + " and " + Integer.toString(two) + " are not equal.");
        }
    }
    public static void checkEquals(String one, String two) {
        if (one != two) {
            System.out.println(one + " and " + two + " are not equal.");
        }
    }
}

//wrapper means I can change implementation without changing rest of code.
class Table {
    //firt index is target, 2nd is dieNum. mapped value is # combos.
    private HashMap<String, Integer> map;
    public Table() {
        /*map = new HashMap.of("6 1", 1, "5 1", 1, "4 1", 1, "3 1", 1, "2 1", 1, "1 1", 1);*/
        map = new HashMap<String, Integer>();
        for (int i=1; i<=6; i++) {
            add(Integer.toString(i)+" 1", 1);
        }
        //map.add("6 1", 1);
    }
    public String pairToKey(int target, int dice) {
        return Integer.toString(target) + " " + Integer.toString(dice);
        //could also have this in other sections.
    }
    //take advantage of lack
    public int get(int target, int dice) {
        return get(pairToKey(target, dice));
        //take advantage of null to store get as value, then check if null so x have to call contains
    }
    public int get(String key) {
        try {
            return map.get(key);
        } catch(NullPointerException e) {
            return -1;
        }
        //take advantage of null to store get as value, then check if null so x have to call contains
    }    
    public void add(int target, int dice, int value) {
        map.put(pairToKey(target, dice), value);
    }
    public void add(String key, int value) {
        map.put(key, value);
    }
}