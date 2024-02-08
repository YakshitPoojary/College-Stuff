import random
import string

def generate_captcha(length=6):
    characters = string.ascii_letters + string.digits
    return ''.join(random.choice(characters) for _ in range(length))

def validate_input(prompt):
    return input(prompt)

def validate_captcha(input_str, captcha):
    if input_str == captcha:
        print("Captcha validated.")
    else:
        print("Incorrect captcha.")

captcha = generate_captcha()
print("Generated Captcha:", captcha)
user_input = validate_input("Enter Captcha: ")
validate_captcha(user_input, captcha)