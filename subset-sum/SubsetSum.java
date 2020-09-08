import java.io.*;
import java.util.*;

/**
 * Subset sum class reads a file that contains an array, and the sum to 
 * check for as well as the size of subset to check for.
 * 
 * @author Manuel Cruz
 *
 */
public class SubsetSum
{
	/**
	 * Private class to keep track of location of specific value in an array.
	 * @author Manuel Cruz
	 *
	 */
	private static class Value
	{
		/** Integer value */
		public int value;
		
		/** Index in array of value */
		public int index;
		
		/**
		 * Explicit constructor.
		 * @param value - Integer of Value
		 * @param index - Location of value
		 */
		public Value(int value, int index)
		{
			this.value = value;
			this.index = index;
		}
		
		@Override
		public String toString()
		{
			return "" + value;
		}
	}
	
	/**
	 * Prints the usage of the program
	 */
	private static void usage(String message)
	{
		if (message != null)
			System.err.println(message);
		
		System.out.println("java SubsetSum <array file> <subset size> <sum to search>");
	}

	/**
	 * Main starting point of the program.
	 * @param args - args given at terminal
	 */
	public static void main(String[] args)
	{
		if (args.length != 3)
		{
			usage("Invalid args");
			System.exit(-1);
		}
		
		File file = new File(args[0]);
		if (!file.exists())
		{
			usage("File: " + args[0] + " Does not exits");
			System.exit(-2);
		}
		
		int[] values = null;
		try
		{
			BufferedReader bf = new BufferedReader(new FileReader(file));
			String[] stringValues = bf.readLine().trim().split(",|\\s+");
			values = new int[stringValues.length];
			for(int i = 0; i < stringValues.length; ++i)
				values[i] = Integer.parseInt(stringValues[i].trim());
			
			bf.close();
		}
		catch (IOException ioe)
		{
			usage("There was an error in reading file: " + args[0]);
			System.exit(-3);
		}
		
		int subsetSize = Integer.parseInt(args[1].trim());
		if (subsetSize < 2)
		{
			usage("Subset Size has to be in the range of 2 and the size of array");
			System.exit(-4);
		}
		
		int totalSum = Integer.parseInt(args[2].trim());
		
		findMatch(values, totalSum, subsetSize);
	}
	
	/**
	 * Finds the matches. Gets all the possible subsets of the given size with no repetition in the subsets.
	 * @param list - List to get subsets from
	 * @param total - sum to compare the subsets
	 * @param numToUse - size of the subsets
	 */
	public static void findMatch(int[] list, int total, int numToUse)
	{
		// create a list that contains the values with its index to keep track
		List<Value> values = new ArrayList<Value>();
		for (int i = 0 ; i < list.length; ++i)
			values.add(new Value(list[i], i));
		
		// get all the combinations of the given numToUse
		List<Set<Value>> sets = combinations(values, numToUse);
		
		// list to hold valid sets
		List<Set<Value>> validSets = new ArrayList<Set<Value>>();
		for (Set<Value> set : sets)
		{
			// checks every single subset that matches
			int sum = 0;
			for (Value value : set)
				sum += value.value;
			
			if (sum == total)
				validSets.add(set);
		}
		
		// prints them to the screen
		for (Set<Value> set : validSets)
		{
			Value[] setValues = set.toArray(new Value[0]);
			for (int i = setValues.length - 1; i >= 0; --i)
			{
				if (i == 0)
					System.out.print("Element[" + (setValues[i].index + 1) + "] = ");
				else
					System.out.print("Element[" + (setValues[i].index + 1) + "] + ");	
			}
			
			for (int i = setValues.length - 1; i >= 0; --i)
			{
				if (i == 0)
					System.out.print(setValues[i].value + " = ");
				else
					System.out.print(setValues[i].value + " + ");	
			}
			
			System.out.println(total);
		}
	}
	
	/**
	 * Gets all the possible subsets of the given size. It does not allow duplications. 
	 * Those subsets will not be allowed.
	 * @param values - List of values
	 * @param setSize - size of the subsets
	 * @return A list containing all of the possible subsets of size setSize
	 */
	public static List<Set<Value>> combinations(List<Value> values, int setSize)
	{
		List<Set<Value>> sets = new ArrayList<Set<Value>>();
		if (setSize == 2) // base case
		{
			for (int i = 0; i < values.size(); ++i)
			{
				for (int j = i + 1; j < values.size(); ++j)
				{
					if (values.get(i).value != values.get(j).value)
					{
						Set<Value> set = new HashSet<Value>();
						set.add(values.get(i));
						set.add(values.get(j));
						sets.add(set);
					}
				}
			}
		}
		else // recursive case
		{
			List<Set<Value>> previousSets = combinations(values, setSize - 1);
			for (Set<Value> set : previousSets)
			{
				for (int i = 0; i < values.size(); ++i)
				{
					Set<Value> newSet = new HashSet<Value>();
					for (Value value : set)
					{
						if (value.value != values.get(i).value)
							newSet.add(value);
					}
						
					newSet.add(values.get(i));
					
					if (!sets.contains(newSet) && newSet.size() == setSize)
						sets.add(newSet);
				}
			}
		}
		return sets;
	}
}
