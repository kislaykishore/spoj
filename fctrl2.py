tests = int(input())
for x in range(tests):
    num = int(input())
    val = 1
    for i in range(1, num + 1):
        val = val * i

    print val
