import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

/**
 * Given two sets in files. Perform the following operations on them:<br>
 * 
 * <ul>
 * <li> Union </li>
 * <li> Intersection </li>
 * <li> Difference </li>
 * <li> Symmetric Difference </li>
 * </ul>
 * 
 * @author Manuel Cruz
 * @version 1.0
 * @date June 3, 2020
 *
 */
public class SetOperations {
	
	/**
	 * Open the file and read values contained in them. Return them in a set object.
	 * @param filename - name of the file
	 * @return a set containing the values found in the file
	 */
	public static Set<Integer> generateSet(String filename)
	{
		File file = new File(filename);
		if (!file.exists()) // check that there is a file
		{
			System.err.println(filename + " does not exist.");
			System.exit(-1);
		}
		
		Set<Integer> set = new HashSet<Integer>();
		
		// read the file's content
		try {
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line = br.readLine();
			while (line != null)
			{
				String[] stringValues = line.split("\\s+");
				for(String v : stringValues) {
					set.add(Integer.parseInt(v.trim()));
				}
				line = br.readLine();
			}
			br.close();
		} catch (IOException e) {
			System.err.println(filename + " does not exist.");
			System.exit(-1);
		}
		
		return set;
	}

	/**
	 * Perform the Union of two sets.
	 * @param firstSet - First set
	 * @param secondSet - Second Set
	 * @return the union of the first and second set
	 */
	public static Set<Integer> union(Set<Integer> firstSet, Set<Integer> secondSet)
	{
		Set<Integer> result = new HashSet<Integer>();
		
		for(int i : firstSet)
			result.add(i);
		
		for(int i : secondSet)
			result.add(i);
		
		return result;
	}
	
	/**
	 * Perform the intersection of two sets.
	 * @param firstSet - First set
	 * @param secondSet - Second Set
	 * @return the intersection of the first and second set
	 */
	public static Set<Integer> intersection(Set<Integer> firstSet, Set<Integer> secondSet)
	{
		Set<Integer> result = new HashSet<Integer>();
		
		for(int i : firstSet)
		{
			if (secondSet.contains(i))
				result.add(i);
		}
		
		return result;
	}
	
	/**
	 * Perform the difference of two sets.
	 * @param firstSet - First set
	 * @param secondSet - Second Set
	 * @return the difference of the first and second set
	 */
	public static Set<Integer> difference(Set<Integer> firstSet, Set<Integer> secondSet) 
	{
		Set<Integer> result = new HashSet<Integer>();
		
		for(int i : firstSet)
		{
			if (!secondSet.contains(i))
				result.add(i);
		}
		
		return result;
	}
	
	/**
	 * Perform the symmetric difference of two sets.
	 * @param firstSet - First set
	 * @param secondSet - Second Set
	 * @return the symmetric difference of the first and second set
	 */
	public static Set<Integer> symmetricDifference(Set<Integer> firstSet, Set<Integer> secondSet)
	{
		Set<Integer> result = new HashSet<Integer>();
		
		Set<Integer> firstResult = difference(firstSet, secondSet);
		Set<Integer> secondResult = difference(secondSet, firstSet);
		
		result.addAll(firstResult);
		result.addAll(secondResult);
		
		return result;
	}
	
	/**
	 * Program usage message
	 */
	public static void usage()
	{
		System.out.println("Usage:");
		System.out.println("\tjava SetOperations firstFile secondFile");
	}
	
	/**
	 * Program start
	 * @param args - command line arguments
	 */
	public static void main(String[] args) {
		if (args.length != 2) {
			usage();
			System.exit(-1);
		}
		
		// create sets with the given files
		Set<Integer> firstSet = generateSet(args[0]);
		Set<Integer> secondSet = generateSet(args[1]);
		Set<Integer> result;
		
		// show files to the screen
		System.out.println("First Set: " + firstSet);
		System.out.println("Second Set: " + secondSet);
		
		System.out.println();
		
		// union performed
		System.out.println("First Set - Union - Second Set");
		result = union(firstSet, secondSet);
		System.out.println("Result: " + result);
		
		System.out.println();
		
		// intersection performed
		System.out.println("First Set - Intersection - Second Set");
		result = intersection(firstSet, secondSet);
		System.out.println("Result: " + result);
		
		System.out.println();
		
		// difference performed
		System.out.println("First Set - Difference - Second Set");
		result = difference(firstSet, secondSet);
		System.out.println("Result: " + result);
		System.out.println("Second Set - Difference - First Set");
		result = difference(secondSet, firstSet);
		System.out.println("Result: " + result);
		
		System.out.println();
		
		// symmetric difference performed
		System.out.println("First Set - Symmetric Difference - Second Set");
		result = symmetricDifference(firstSet, secondSet);
		System.out.println("Result: " + result);
	}

}

