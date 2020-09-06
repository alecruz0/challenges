# Name: Manuel Cruz
# Purpose: Experiment with time dilation equations from theory of relativity.
#          Given the percentage of speed of light, and the time traveling at that speed.
#          Calculate the dilated time.

import sys
import math

# Constants
SPEED_OF_LIGHT = 300000000
SECONDS_PER_YEAR = 60*60*24*365

def seconds_to_years(seconds):
    '''Converts the given seconds to years'''
    return seconds / SECONDS_PER_YEAR

def years_to_seconds(years):
    '''Converts the given years to seconds'''
    seconds_per_year = 31536000
    return years * SECONDS_PER_YEAR

def time_dilation(seconds, speed):
    '''Change in time based on speed of dilated speed'''
    earth_time = seconds / (math.sqrt(1 - (speed/SPEED_OF_LIGHT)**2))
    return earth_time

def usage():
    '''Usage of the program'''
    print("python3 time_dilation.py <percentage of speed of light> <number of years traveling>")

def main(args):
    '''Main method to claculate time dilation based on the args given by the user.'''
    if len(args) != 3:
        usage()
        sys.exit(-1)
    
    percentage_speed = args[1]
    
    if percentage_speed > 1:
        percentage_speed /= 100

    # Check the speed of light percentage
    if percentage_speed > 1 or percentage_speed < 0:
        print("Percentage of speed must be between 0 and 100")
        print("Please try again\n")
        usage()
        sys.exit(-1)
    
    time_traveling = args[2]

    # Compute dilated time
    dilated_time = seconds_to_years(time_dilation(years_to_seconds(time_traveling), SPEED_OF_LIGHT * percentage_speed))

    print("You will travel at", percentage_speed * 100, "% of the speed of light")
    print("You will travel at", SPEED_OF_LIGHT * percentage_speed, "m/s")

    print("If you go in a spaceship for", time_traveling, "years.")
    print("For you,", time_traveling, "years would pass.")
    print("But on Earth", dilated_time, "years would have passed\n")

if __name__ == '__main__':
    main(sys.argv)
    
