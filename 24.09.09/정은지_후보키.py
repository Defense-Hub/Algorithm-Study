from itertools import combinations

def solution(relation):
    row = len(relation)
    col = len(relation[0])
    
    # 인덱스 리스트
    indexs = [i for i in range(col)]
    candidate = []
    
    for i in range(1,col+1):
        # 속성들의 인덱스 조합을 뽑는다
        combi = combinations(indexs,i)
        
        for comb in combi:
            check = set()
            
            for r in relation:
                key = ""
                for c in comb:
                    key += r[c]
                check.add(key)
                
            # 유일성 체크
            if len(check) == row:
                candidate.append(comb)
                
    # 최소성 체크 (더 작은 조합으로 대체 X) => 0이 이미 후보키이면 0을 가지는 집합들은 후보키가 될 수 없다
    candidateKeys = []

    for cand in candidate:
        canBeKey = True
        
        for key in candidateKeys:
            if set(key).issubset(set(cand)):
                canBeKey = False
                break
                
        if canBeKey:
            candidateKeys.append(cand)

    return len(candidateKeys)
