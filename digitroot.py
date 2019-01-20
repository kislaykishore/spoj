def exponentiation(base, exponent, mod):
    if exponent == 1:
        return base % mod
    elif exponent == 0:
        return 1
    else:
        exp1 = exponent // 2
        exp2 = exponent - exp1
        val = exponentiation(base, exp1, mod) * exponentiation(base, exp2, mod)
        return val % mod

num = int(input())
exponent = int(input())
if num == 0:
    print("0\n")
else:
    val = exponentiation(num, exponent, 9)
    print((9 + val)%9)
