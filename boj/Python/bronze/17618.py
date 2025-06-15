def get_digit(x: int) -> int:
    ret = 0
    while x > 0:
        ret += x % 10
        x //= 10
    return ret


n = int(input())
answer = 0
for i in range(1, n + 1):
    if i % get_digit(i) == 0:
        answer += 1
print(answer)
