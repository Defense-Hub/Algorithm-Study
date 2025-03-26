# 13:37 ~ 13:56

import sys
from itertools import combinations
input = sys.stdin.readline

l,c = map(int,input().split())
alphabets = list(input().split())
vowels = ['a','e','i','o','u']

def check_valid_string(string):
    vowel_cnt = 0
    consonant_cnt = 0
    for i in string:
        if i in vowels:
            vowel_cnt += 1
        else:
            consonant_cnt += 1

    if vowel_cnt >= 1 and consonant_cnt >= 2:
        return True
    else:
        return False

def solution():
    answer = set()
    alphabets.sort()
    combs = list(combinations(alphabets,l))

    for comb in combs:
        new_string = "".join(comb)
        if check_valid_string(new_string):
            print(new_string)

solution()