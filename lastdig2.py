def pow(a, b):
    if b == 0:
        return 1
    else:
        val = pow(a, b//2)
        if b & 1 == 0:
            return (val*val)% 10
        else:
            return ((val * val) * a)% 10

tests = int(input())
for p in range(tests):
    val = input().split(' ')
    a = int(val[0])
    b = int(val[1])
    a = a % 10
    print(pow(a, b))
