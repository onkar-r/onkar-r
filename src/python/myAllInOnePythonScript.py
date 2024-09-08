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

print("\n\nWelcome to Onkar's implementation of a Calculator -- a four function calculator in Python!")

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

print("\n\nString slicing")
mystr = "HelloWorld"
print(f"Full string = {mystr}, Just Hello part = {mystr[:5]}, Reverse = {mystr[::-1]}") # Syntax: str[start pos: end pos : step]


print("\n\nLambda functions:")
square = lambda x: x*x
print(f"Square of 5 using lambda function: {square(5)}") # 25


print("\n\nMaking static variable thread-safe using mutex lock")
import threading

class Counter:
    count = 0  # Class variable (shared by all instances)
    lock = threading.Lock()  # Lock for thread safety

    @classmethod
    def increment(cls):
        with cls.lock:  # Acquire the lock before modifying the class variable
            temp = cls.count
            temp += 1
            cls.count = temp

# Function to increment the counter in a loop
def increment_counter():
    for _ in range(1000):
        Counter.increment()

# Create two threads
thread1 = threading.Thread(target=increment_counter)
thread2 = threading.Thread(target=increment_counter)

# Start both threads
thread1.start()
thread2.start()

# Wait for both threads to finish
thread1.join()
thread2.join()

# Check the final value of the class variable
print(Counter.count)

