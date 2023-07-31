import sys

n = int(sys.stdin.readline())  

def erts(x):
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True

def isPrime_ndigit(num):
    if len(str(num)) == n:
        print(num)
    else:
        for i in range(10):
            if erts(num * 10 + i):
                isPrime_ndigit(num * 10 + i)

isPrime_ndigit(2)
isPrime_ndigit(3)
isPrime_ndigit(5)
isPrime_ndigit(7)
