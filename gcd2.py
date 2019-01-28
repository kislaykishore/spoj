def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

n = int(input())
while n:
    n = n - 1
    str = input()
    strs = str.split(' ')
    a = int(strs[0])
    b = int(strs[1])
    print(gcd(a, b))


