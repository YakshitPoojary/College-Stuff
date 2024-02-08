import tkinter as tk
from tkinter import PhotoImage
from PIL import Image, ImageTk

correct_sequence = [True, False, False, True, False, False, False, True, False]

user_selection = [False] * len(correct_sequence)

def toggle_selection(index):
    user_selection[index] = not user_selection[index]
    if user_selection[index]:
        buttons[index].config(bg="#FF0000")  
    else:
        buttons[index].config(bg="#333333")  

def verify_selection():
    if user_selection == correct_sequence:
        msg_label.config(text="Correct!")
    else:
        msg_label.config(text="Incorrect!")

window = tk.Tk()
window.title("Captcha Image Selector")
window.geometry('450x600')
window.configure(bg='#FFFFFF')

frame = tk.Frame(window, bg='#FFFFFF')
frame.pack(expand=True, fill='both')

image_paths = [
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/cat2.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat4.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat1.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/cat3.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat2.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat3.png",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat5.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/cat1.jpg",
    "C:/Users/Yakshit/Desktop/VSCODE/Repository/College-Stuff/captchaImages/notcat6.jpg",
]

photo_images = [ImageTk.PhotoImage(Image.open(path).resize((150, 150), Image.BICUBIC)) for path in image_paths]

buttons = []
for i, image in enumerate(photo_images):
    button = tk.Button(frame, image=image, bg="#333333", command=lambda idx=i: toggle_selection(idx))
    button.grid(row=i // 3, column=i % 3, padx=5, pady=5)
    buttons.append(button)

heading_label = tk.Label(frame, text="Select All Photos with Cats", bg="#0E86D4", fg="#FFFFFF", font=("Georgia", 16))
heading_label.grid(row=len(photo_images) // 3, column=0, columnspan=3, pady=10)

verify_button = tk.Button(frame, text="Verify", bg="#0E86D4", fg="#FFFFFF", font=("Georgia", 16), command=verify_selection)
verify_button.grid(row=len(photo_images) // 3 + 1, column=1, pady=10)

msg_label = tk.Label(frame, text="", bg="#FFFFFF", fg="#333333", font=("Georgia", 16))
msg_label.grid(row=len(photo_images) // 3 + 2, column=0, columnspan=3, pady=10)

window.mainloop()