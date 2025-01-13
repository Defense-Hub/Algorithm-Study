import sys
input = sys.stdin.readline

n, k = map(int, input().split())
array = list(map(int, input().split())) 

def solution():
    # 누적 합 딕셔너리
    dictionary = {0 : 1}

    cnt = 0
    answer = 0

    for i in array:
        cnt += i

        # 현재까지 누적합 중에서 누적합 - (이전 누적합) = k 가 있으면
        # 즉 누적합 - k값이 이전에 나왔으면 정답개수 추가
        if cnt - k in dictionary.keys():
            answer += dictionary[cnt - k]

        # 누적 합 딕셔너리 갱신
        dictionary[cnt] = dictionary.get(cnt, 0) + 1

    print(answer)

solution()