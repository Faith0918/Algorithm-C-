inp = str(input())

characters = ""
numbers = ""

for idx in range(len(inp)):
    if int(ord(inp[idx]))>=int(ord('0')) and int(ord(inp[idx]))<=int(ord('9')):
        numbers=numbers+inp[idx]
    else:
        characters = characters + inp[idx]


print(characters+numbers)