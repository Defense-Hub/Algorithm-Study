# 각 이모티콘의 할인율에 대한 모든 경우의 수를 구하는 dfs
def dfs(temp, depth):
    global array
    percentage = [10,20,30,40]
    
    # 이모티콘의 개수 만큼 dfs가 돌았을 때
    if depth == len(temp):
        # 얕은 복사를 통해 새로운 temp 생성
        array.append(temp[:])
        return
    for p in percentage:
        temp[depth] += p
        dfs(temp, depth + 1)
        temp[depth] -= p

def solution(users, emoticons):
    answer = [0,0]  
    global array
    array = []
    
    dfs([0] * len(emoticons),0)
    
    for i in range(len(array)):
        serviceUser = 0
        profit = 0
        
        for user in users:
            useMoney = 0
            per, handMoney = user
            
            for j in range(len(emoticons)):
                # per 이상 할인하는 이모티콘은 구매
                if array[i][j] >= per:
                    useMoney += emoticons[j] * ((100-array[i][j])/100)

            if useMoney >= handMoney:
                # 이모티콘 구매 비용의 합이 handMoney 이상이 되면, 이모티콘 플러스 서비스 가입
                serviceUser += 1
            else:
                profit += useMoney
            
        if answer[0] < serviceUser:
            answer = [serviceUser, int(profit)]
        elif answer[0] == serviceUser:
            if answer[1] < profit:
                answer = [serviceUser, int(profit)]
    return answer