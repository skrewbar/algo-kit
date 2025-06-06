for _ in range(int(input())):
    n, m, l = map(int, input().split())
    x = l
    for s in list(map(int, input().split())):
        if s == -1:
            continue
        x = max(x, m - s)
    
    print(f"The scoreboard has been frozen with {x} minute", end="")
    if x != 1:
        print("s", end="")
    print(" remaining.")