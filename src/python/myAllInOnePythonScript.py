#!/usr/bin/env python
import sys


def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mult(a, b):
    return a * b

def div(a, b):
    return a / b


##############  M A I N ########################
a = None
b = None
op = None

print("Welcome to Onkar's implementation of a Calculator -- a four function calculator in Python!")

while (True):
    # get input values
    a = input("Enter the first argument: ")
    op = input("Enter the operation: ")
    b = input("Enter the second argument: ")
    try:
        a = int(a)
        b = int(b)
    except ValueError:
        print("Invalid number argument...")
        raise # End the execution here

    # decide function
    if (op != None):
        if (op == "+"):
            print ("Sum: ", add(a, b))
        elif (op == "-"):
            print ("Difference: ", sub(a, b))
        elif (op == "*"):
            print ("Product: ", mult(a, b))
        elif (op == "/"):
            print ("Quotient: ", div(a, b))
        else:
            print ("Invalid operation...")

    q = input("Quit? [y/n] ")
    if (q == "y" or q == "Y"):
        print("Exiting... Bye!")
        break

print("String slicing")
mystr = "HelloWorld"
print(f"Full string = {mystr}, Just Hello part = {mystr[:5]}, Reverse = {mystr[::-1]}") # Syntax: str[start pos: end pos : step]
