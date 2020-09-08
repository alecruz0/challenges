# Name: Manuel Cruz
# Description: Given a range of values, determine which values are twins in the range.
# A twin pair has two have two conditions. Both must be prime and their absolute
# difference must be 2.

# Given a number determine whether it is prime or not.
# Params:
# +n+:: Number to check
#
# Return:
# True if it is prime false otherwise
def is_prime(n)
	if n < 2 then return false end
	for v in 2..n-1
		if n % v == 0
			return false
		end
	end
	return true
end

# Determines whether the two given numbers are twins or not.
# Params:
# +a+:: First number to compare
# +b+:: Second number to compare
#
# Return:
# True if both are prime. False Otherwise.
def twins(a, b)
	primes = is_prime(a) && is_prime(b)
	difference = (a-b).abs() == 2
	return primes && difference
end

# Displays usage of program to screen
# Params:
# +message+:: Message to display to user
def usage(message)
	puts message
	puts "ruby twins.rb <left interval> <right interval>"
end

# Starting main method
def main(args)
	
	# check args
	if args.length() != 2
		usage("Invalid args")
		exit(-1)
	end
	
	left_interval = args[0].to_i()
	right_interval = args[1].to_i()
	
	# check all possible pairs
	for first_value in left_interval..right_interval - 1
		for second_value in left_interval + 1..right_interval
			if twins(first_value, second_value)
				print "(", first_value, ", ", second_value, ")"
				puts
			end
		end
	end
end

if __FILE__ == $0
	main(ARGV)
end
