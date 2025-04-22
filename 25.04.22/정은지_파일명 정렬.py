# 16:30 ~ 17:10

from collections import defaultdict

def solution(files):
    answer = []
    dic = defaultdict(list)
    
    for file in files:
        Head = ''
        Number = ''
        Tail = ''
        
        length = len(file)
        i = 0

        # Head 추출
        while i < length and not file[i].isdigit():
            Head += file[i]
            i += 1

        # Number 추출
        while i < length and file[i].isdigit():
            Number += file[i]
            i += 1

        # Tail은 나머지
        Tail = file[i:]
        #print("헤드",Head,"숫자",Number,"꼬리",Tail)

        dic[Head.lower()].append((Number,Tail,Head))
        sorted_header = sorted(dic.keys())

        for key in sorted_header:
            dic[key].sort(key=lambda x:(int(x[0])))

    dic = dict(sorted(dic.items()))
    #print(dic)
    for key in dic.keys():
        for value in dic[key]:
            Number,Tail,Head = value
            answer.append(Head+Number+Tail)
   # print(answer)                         
    return answer

#solution(["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"])
solution(["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"])
#기댓값 〉	["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"]