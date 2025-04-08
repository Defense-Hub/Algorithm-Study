# 14:25 ~ 14:59

import sys
input = sys.stdin.readline
from collections import deque

s = int(input())
visited = [[False] * (1001) for _ in range(1001)]

def bfs(emoji_cnt, clipboard_cnt):
    visited[emoji_cnt][clipboard_cnt] = True
    queue = deque([[emoji_cnt, clipboard_cnt,0]])

    while(queue):
        emoji,clipboard,time = queue.popleft()
        new_emoji, new_clipboard = 0,0

        if emoji == s:
            print(time)
            break

        for i in range(3):
            # 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
            if i == 0:
                new_emoji, new_clipboard = emoji, emoji
            # 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
            elif i == 1:
                new_emoji, new_clipboard = emoji + clipboard, clipboard
            # 화면에 있는 이모티콘 중 하나를 삭제
            elif i == 2:
                new_emoji, new_clipboard = emoji-1, clipboard

            if 0 <= new_emoji < 1001 and 0 <= new_clipboard < 1001 and not visited[new_emoji][new_clipboard]:
                visited[new_emoji][new_clipboard] = True
                queue.append([new_emoji, new_clipboard, time+1])

bfs(1,0)