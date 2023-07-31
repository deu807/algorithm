# x1*y2 + x2*y3 + x3*y1 - (x2*y1 - x3*y2 - x1*y3)이 음수면 시계, 양수면 반시계, 0이면 평행
import sys
x1, y1, x2, y2 = map(int, sys.stdin.readline().rstrip().split()) 
x3, y3, x4, y4  = map(int, sys.stdin.readline().rstrip().split())

def ccw(x1, y1, x2, y2, x3, y3) :
    return x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3 

ccw1 = ccw(x1, y1, x2, y2, x3, y3)
ccw2 = ccw(x1, y1, x2, y2, x4, y4)
ccw3 = ccw(x3, y3, x4, y4, x1, y1)
ccw4 = ccw(x3, y3, x4, y4, x2, y2)

if ccw1 * ccw2 < 0 and ccw3 * ccw4 < 0:
    print(1)
else :
    print(0)