def solution(skill, skill_trees):
    answer = 0
    prev_skill = list(skill)
    dic = {}

    # 딕셔너리에 각 스킬 별 선행 스킬 저장
    for i in range(len(prev_skill)):
        dic[prev_skill[i]] = prev_skill[:i]
    
    print(dic)
    
    for i in skill_trees:
        skill_tree = list(i)
        all_exist = True
        for j in range(len(skill_tree)-1,-1,-1):
            # 선행 스킬이 있는 경우만 검사    
            if skill_tree[j] in dic:
                # 현재 스킬트리 스킬의 선행 스킬들 now_skill
                now_skill = dic[skill_tree[j]]
                # 현재 스킬트리 스킬이 실행되기 전 배워진 스킬들
                prev_skill = skill_tree[:j+1]
                # now_skill에 있는 스킬들이 prev_skill에 전부 있으면 answer += 1
                for k in now_skill:
                    if k not in prev_skill:
                        all_exist = False
                        break               
        if all_exist:
            answer += 1
    return answer