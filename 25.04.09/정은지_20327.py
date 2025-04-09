# 15:26 ~ 17:06

import sys
import pprint
input = sys.stdin.readline

n,r = map(int,input().split())
matrix = [list(map(int,input().split())) for _ in range(2**n)]
calculations = [list(map(int,input().split())) for _ in range(r)]

def flip1(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[i+size-r-1][j+c]
    return new_matrix

def flip2(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[i+r][j+size-c-1]
    return new_matrix

def rotate3(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[i+size-c-1][j+r]
    return new_matrix

def rotate4(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[i+c][j+size-1-r]
    return new_matrix

def flip5(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[len(matrix)-size+r-i][j+c]
    return new_matrix

def flip6(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[i+r][len(matrix)-size+c-j]
    return new_matrix

def rotate7(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[len(matrix)-size-j+r][i+c]
    return new_matrix

def rotate8(l):
    new_matrix = [row[:] for row in matrix]
    size = 2**l

    for i in range(0,len(matrix),size):
        for j in range(0,len(matrix),size):
            for r in range(size):
                for c in range(size):
                    new_matrix[i+r][j+c] = matrix[j+r][len(matrix)-size-i+c]
    return new_matrix

# k는 연산 번호, l은 부분 배열 크기
def calculate(k,l):
    global matrix

    if k==1:
        matrix = flip1(l)
    elif k==2:
        matrix = flip2(l)
    elif k==3:
        matrix = rotate3(l)
    elif k==4:
        matrix = rotate4(l)
    elif k==5:
        matrix = flip5(l)
    elif k==6:
        matrix = flip6(l)
    elif k==7:
        matrix = rotate7(l)
    elif k==8:
        matrix = rotate8(l)

def solution():
    for calculation in calculations:
        k,l = calculation
        calculate(k,l)

    for i in matrix:
        print(*i)
solution()