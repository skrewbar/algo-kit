n = int(input())
res = 1
for i in range(2, n + 1):
    res *= i
    while res % 10 == 0:
        res //= 10
    res %= 10_000_000_000_000

print(f"{res % 100_000:0>5}")
