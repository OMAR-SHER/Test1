# Python program to validate an Email # only checks format of email
# import re module
# re module provides support
# for regular expressions
import re

# Make a regular expression
# for validating an Email
regex = '\b[A-Z0-9._%+-]+@[A-Z0-9.-]+.[A-Z]{2,}\b'


# Define a function for
# for validating an Email
def check(email):
    # pass the regular expression
    # and the string in search() method
    if (re.search(regex, email)):
        print("Valid Email")

    else:
         print("Invalid Email")
# Driver Code
if __name__== '__main__':
    # Enter the email
    email = str(input("Enter Email::"))
    # calling run function
    check(email)
    email = "my.ownsite@our-earth.org"
    check(email)
    email = "ankitrai326.com"
    check(email)