#
# Author: Manuel Cruz
# Date: June 3, 2020
# Description: Check whether the given string is a palindrome or not.
#

import sys

def palindrome(string):
    '''Checks whether the given string is a palindrome or not'''
    if len(string) == 0 or len(string) == 1:
        return True

    if string[0] != string[-1]:
        return False

    return palindrome(string[1:-1])

def usage():
    '''Prints usage of script'''
    print("Usage:")
    print("\tpython3 palindrome.py string")

def main(args):
    '''Main method'''
    if len(args) != 2:
        usage()
        sys.exit(-1)

    is_palindrome = palindrome(args[1])

    message = "The string " + "\"" + args[1] + "\""

    if (is_palindrome):
        message += " is "
    else:
        message += " is not "

    message += "a palindrome."

    print(message)

if __name__ == '__main__':
    main(sys.argv)
