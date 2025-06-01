n, m = map(int, input().split())

daily_expense = [int(input()) for _ in range(n)]


def get_withdraw_count(k: int) -> int:
    money = 0
    withdraw_count = 0

    for e in daily_expense:
        if money - e < 0:
            money = k
            withdraw_count += 1
        money -= e

    return withdraw_count


lo = max(daily_expense)
hi = sum(daily_expense)

while lo < hi:
    mid = (lo + hi) // 2
    cnt = get_withdraw_count(mid)

    if m < cnt:
        lo = mid + 1
    else:
        hi = mid

print(lo)
