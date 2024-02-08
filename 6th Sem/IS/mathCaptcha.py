import random

def mathCaptcha():
    num1 = random.randint(0, 20)
    num2 = random.randint(1, 20)

    operations = ['+', '-', '*', '/']
    op = random.choice(operations)

    if op == '+':
        eq = num1 + num2
    elif op == '-':
        eq = num1 - num2
    elif op == '*':
        eq = num1 * num2
    else:
        eq = round(num1 / num2, 2)

    user_ans = float(input(f"Solve the equation {num1} {op} {num2}: "))

    if user_ans != eq:
        print("Incorrect!")
        mathCaptcha()
    else:
        print("Correct Answer.")

mathCaptcha()
