def solution(numbers, hand):
    answer = ''
    keypad = {'1':(0,0), '2':(0,1), '3':(0,2),
           '4':(1,0), '5':(1,1), '6':(1,2),
           '7':(2,0), '8':(2,1), '9':(2,2),
           '*':(3,0), '0':(3,1), '#':(3,2)}

    left = keypad['*']
    right = keypad['#']
    
    for number in numbers:
        if number == 1 or number == 4 or number == 7:
            answer += 'L'
            left = keypad[str(number)] 
        elif number == 3 or number == 6 or number == 9:
            answer += 'R'
            right = keypad[str(number)] 
        else:   
            leftDistance = abs(left[0]-keypad[str(number)][0])+abs(left[1]-keypad[str(number)][1])
            rightDistance = abs(right[0]-keypad[str(number)][0])+abs(right[1]-keypad[str(number)][1])
            
            if leftDistance < rightDistance:
                answer += 'L'
                left = keypad[str(number)]
            elif leftDistance > rightDistance:
                answer += 'R'
                right = keypad[str(number)]
            else:
                if hand == "right":
                    answer += 'R'
                    right = keypad[str(number)]
                else:
                    answer += 'L'
                    left = keypad[str(number)]
                    
    return answer