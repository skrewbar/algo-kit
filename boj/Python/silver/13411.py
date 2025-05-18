from dataclasses import dataclass


@dataclass
class Point:
    i: int
    x: int
    y: int
    v: int


n = int(input())

points = [Point(i + 1, *map(int, input().split())) for i in range(n)]
points.sort(key=lambda p: (p.x**2 + p.y**2) / p.v**2)

for p in points:
    print(p.i)
