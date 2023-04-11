from turtle import *

lenght = 5
angle = 25.7
stc = []


path = "F"

speed(0)

def draw_path(path):
    left(90)
    for symbol in path:
        if symbol =='F':
            forward(lenght)
        elif symbol == '-':
            right(angle)
        elif symbol == '[':
            stc.append(xcor())
            stc.append(ycor())
            stc.append(heading())

        elif symbol == ']':
            penup()
            setheading(stc.pop())
            sety(stc.pop())
            setx(stc.pop())
            pendown()
    update()
    mainloop()

def apply_rule(path):
    rule="F[+F]F[-F]F"

    return path.replace("F", rule)


path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)
path = apply_rule(path)


draw_path(path)

exitonclick()