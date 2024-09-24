from itertools import combinations

def solution(orders, course):
    answer = []
    frequency = {}
    
    # 주문 별 조합 뽑기
    for order in orders:
        for i in course:        
            for j in list(combinations(list(order),i)):
                j = list(j)
                j.sort()
                frequency_key = "".join(j)

                if frequency_key not in frequency:
                    frequency[frequency_key] = 0
                frequency[frequency_key] += 1
    
    new_frequency = {}
    
    # key = 코스 수, value = (주문된 횟수, 요리 알파벳)
    for i in frequency: 
        if frequency[i] >= 2:
            if len(i) not in new_frequency:
                new_frequency[len(i)] = []
            new_frequency[len(i)].append((frequency[i],i))

    # 각 코스 별로 가장 많이 주문된 요리 뽑아 정답 배열에 넣기
    for i in new_frequency:
        array = sorted(new_frequency[i],reverse = True)
        max_order_count = array[0][0]

        for j in array:
            if j[0] == max_order_count:
                answer.append(j[1])
    
    answer.sort()
           
    return answer