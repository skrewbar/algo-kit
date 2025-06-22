def solve(t: int):
    n = int(input())
    heights: list[int | float] = list(map(int, input().split()))

    for i in range(1, n - 1):
        heights[i] = min(heights[i], (heights[i - 1] + heights[i + 1]) / 2)

    print(f"Case #{t}: {heights[-2]:.10f}")


for t in range(1, int(input()) + 1):
    solve(t)
