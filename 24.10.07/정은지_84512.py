def dfs(word, array):
    alphabet = ['A', 'E', 'I', 'O', 'U']
    if word:
        array.append(word)
    
    if len(word)<5:
        for i in alphabet:
            dfs(word+i,array)
    
def solution(word):
    answer = 0
    array = []
    
    dfs("",array)
    array.sort()

    return array.index(word)+1