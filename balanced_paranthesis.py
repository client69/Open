t = int(input())

while t:
    s = input()
    stack = []
    res = "YES"
    for i in range(len(s)):
        if s[i] == '(' or s[i] == '{' or s[i] == '[':
            stack.append(s[i])
        else:
            if s[i] == ')':
                if len(stack) != 0 and stack[-1] == '(':
                    stack.pop()
                else:
                    res = "NO"
                    break

            if s[i] == '}':
                if len(stack) != 0 and stack[-1] == '{':
                    stack.pop()
                else:
                    res = "NO"
                    break

            if s[i] == ']':
                if len(stack) != 0 and stack[-1] == '[':
                    stack.pop()
                else:
                    res = "NO"
                    break

    if stack or res == "NO":
        print("NO")
    else:
        print("YES")

    t -= 1
