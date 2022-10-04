
###################
# IMPORTED MODULES
###################

import turtle as tr
import tkinter as tk
import csv
import time
import random as r



######################
# IMPORTANT VARIABLES
######################

speed_lst = [0.35, -0.35]
ballx = r.choice(speed_lst)
bally = r.choice(speed_lst)
pause = 0
start_var = 0



#######################
# MAIN GAME FUNCTION
#######################

def game(p1="Player1", p2="Player2"):

    global ballx
    global bally
    global pause   


    ##########################
    # INFO SCREEN  
    ##########################

    # Destroy Screen
    ##########################

    def info_destroy():
        info_screen.destroy()

    info_screen = tk.Tk()

    info_screen.title("INFORMATION")
    info_screen.configure(bg="grey")

    info_screen.geometry("800x500")
    info_screen.minsize(800, 500)
    info_screen.maxsize(800, 500)

    
    rules_head = tk.Label(info_screen, text="RULES:", bg="grey", font=("Courier", 30, "bold"))
    rules_head.pack(pady=10)

    rule1 = tk.Label(info_screen, text=">>> The player who scores 3 points first will WIN the game", bg="grey", font=("arial", 15, "italic"))
    rule1.pack()


    controls_head = tk.Label(info_screen, text="CONTROLS:", bg="grey", font=("Courier", 30, "bold"))
    controls_head.pack(pady=20)

    control1 = tk.Label(info_screen, text='1. Press UP(↑) and DOWN(↓) keys to move Right paddle', bg="grey", font=("arial", 15, "italic"))
    control1.pack()

    control2 = tk.Label(info_screen, text='2. Press "w" key and "s" key to move Left paddle', bg="grey", font=("arial", 15, "italic"))
    control2.pack(pady=5)

    control3 = tk.Label(info_screen, text='3. Press "p" to pause', bg="grey", font=("arial", 15, "italic"))
    control3.pack()    

    button_rules = tk.Button(info_screen, text='Play', width=10, bg='white', fg='#000000', activebackground='#66ff66', font=("arial", 12, "bold italic"), command=info_destroy, relief="flat")
    button_rules.pack(pady=25)

    foot_rules = tk.Label(info_screen, text="Made By ~ Muteen, Aarush & Arjun", font=("Courier", 12 , "italic underline"), bg="grey")
    foot_rules.pack(side="bottom", anchor="e")


    info_screen.mainloop()

    ########################
    #   OBJECTS ON SCREEN
    ########################

    # The main game screen
    win = tr.Screen()
    win.bgcolor("black")
    win.setup(height=1000, width=1200)
    win.title("PONG")
    win.tracer(0)

    # For Full Screen
    box = tr.Turtle("classic")
    box.hideturtle()
    box.color("white")
    box.penup()
    box.goto(-500, -400)
    box.pendown()
    box.goto(500, -400)
    box.goto(500, 400)
    box.goto(-500, 400)
    box.goto(-500, -400)



    #################
    # Designs
    #################

    #center line
    cLine = tr.Turtle("square")
    cLine.hideturtle()
    cLine.color("white")
    cLine.penup()
    cLine.goto(0, -400)
    cLine.pendown()
    cLine.goto(0, 400)


    #center circle
    cCircle = tr.Turtle()
    cCircle.hideturtle()
    cCircle.color("white")
    cCircle.penup()
    cCircle.goto(0, -100)
    cCircle.pendown()
    cCircle.circle(100)



    ####################
    # PLAYERS INFO
    ####################

    # player1 info
    player1 = tr.Turtle()
    player1.hideturtle()
    player1.color("white")
    player1.penup()
    player1.goto(-450, 410)
    player1.write("{}: 0".format(p1), font=("Arial", 20, "italic"))
    player1_score = 0
    
    
    # player2 info
    player2 = tr.Turtle()
    player2.hideturtle()
    player2.color("white")
    player2.penup()
    player2.goto(50, 410)
    player2.write("{}: 0".format(p2), font=("Arial", 20, "italic"))
    player2_score = 0



    #####################
    # CREDITS
    #####################

    credit = tr.Turtle()
    credit.hideturtle()
    credit.color("white")
    credit.penup()
    credit.goto(0, -450)
    credit.write("MADE BY~ MUTEEN, AARUSH & ARJUN", font=("Arial", 20, "italic"))


    #####################
    # PAUSE SCREEN
    #####################

    pause_txt = tr.Turtle()
    pause_txt.hideturtle()
    pause_txt.color("white")
    pause_txt.penup()
    pause_txt.goto(-168, -50)

    ####################
    #   Components
    ####################

    # ball
    ball = tr.Turtle("circle")
    ball.shapesize(1.2, 1.2)
    ball_colour = ["#803790", "cyan", "#66ff66", "#ffff66", "#ff9933", "#ff355e", "#7cfc00", "#ff3399" , "#50bfe6", "#c8c8cd"]
    prevColor = r.choice(ball_colour)
    ball.color(prevColor)
    ball.speed(1)
    ball.penup()
    
    
    # ball.goto(474, 0)

    # left paddle
    lPaddle = tr.Turtle("square")
    lPaddle.color("#50bfe6")
    lPaddle.shapesize(6, 0.3)
    lPaddle.speed(0)
    lPaddle.penup()
    lPaddle.goto(-450, 0)

    # right paddle
    rPaddle = tr.Turtle("square")
    rPaddle.color("#50bfe6")
    rPaddle.shapesize(6, 0.3)
    rPaddle.speed(0)
    rPaddle.penup()
    rPaddle.goto(450, 0)


    #######################
    #   EVENT FUNCTIONS
    #######################

    # Right paddle movement up
    def rightUp():
        rightY = rPaddle.ycor()
        if(rightY <= 328):
            rPaddle.sety(rightY+30)


    # Right paddle movement down
    def rightDown():
        rightY = rPaddle.ycor()
        if(rightY >= -328):
            rPaddle.sety(rightY-30)


    # Left paddle movement up
    def leftUp():
        leftY = lPaddle.ycor()
        if(leftY <= 328):
            lPaddle.sety(leftY+30)


    # Left paddle movement down
    def leftDown():
        leftY = lPaddle.ycor()
        if(leftY >= -328):
            lPaddle.sety(leftY-30)


    # Ball colour change on bouncing
    def colorChange():
        # global ball_colour
        # global prevColor
        clr = r.choice(ball_colour)
        while clr == prevColor:
            clr = r.choice(ball_colour)
        ball.color(clr)
        return clr

    # Bounce ball on X-axis
    def bounceX():
        global ballx
        ball.shapesize(0.8, 1.2)
        cColor = colorChange()
        credit.undo()
        credit.color(cColor)
        credit.write("MADE BY~ MUTEEN, AARUSH & ARJUN", font=("Arial", 20, "italic"))
        ballx *= -1
        ball.shapesize(1.2, 1.2)

        return cColor


    # Bounce ball on Y-axis
    def bounceY():
        global bally
        ball.shapesize(1.2, 0.8)
        cColor = colorChange()
        credit.undo()
        credit.color(cColor)
        credit.write("MADE BY~ MUTEEN, AARUSH & ARJUN", font=("Arial", 20, "italic"))
        bally *= -1
        ball.shapesize(1.2, 1.2)
        return cColor


    # Game Pause
    def pauseGame():
        global pause
        if pause == 1:
            pause -= 1
            pause_txt.undo()
        elif pause == 0:
            pause += 1
            pause_txt.write("PAUSED", font=("Arial", 60, "bold"))

    

    #######################
    # KEYBOARD INPUT
    #######################

    win.listen()
    win.onkeypress(rightUp, "Up")
    win.onkeypress(rightDown, "Down")
    win.onkeypress(leftUp, "w")
    win.onkeypress(leftDown, "s")
    win.onkeypress(pauseGame, "p")
    win.onkeypress(leftUp, "W")
    win.onkeypress(leftDown, "S")
    win.onkeypress(pauseGame, "P")



    #####################
    # The main game loop
    #####################
    
    while player1_score < 3 and player2_score < 3:

        # to update the screen
        win.update()

        # To Pause the main game loop
        if pause == 1:
            continue

        # Border Collisions
        ###################

        # Border Collision for top
        if ball.ycor() > 388:
            ball.sety(388)
            nColor = bounceY()
            prevColor = nColor

        # Border Collision for bottom
        if ball.ycor() < -388:
            ball.sety(-388)
            nColor = bounceY()
            prevColor = nColor

        # Border Collision for right
        if ball.xcor() > 485:
            ball.goto(0, 0)
            player1_score += 1
            player1.undo()
            player1.write("{1}: {0}".format(player1_score, p1), font=("Arial", 20, "italic"))
            time.sleep(1)
            ballx = r.choice(speed_lst)
            bally = r.choice(speed_lst)

            

        # Border Collision for left
        if ball.xcor() < -485:
            ball.goto(0, 0)
            player2_score += 1
            player2.undo()
            player2.write("{1}: {0}".format(player2_score, p2), font=("Arial", 20, "italic"))
            time.sleep(1)
            ballx = r.choice(speed_lst)
            bally = r.choice(speed_lst)
            


        # Paddle Collisions
        ###################

        # Paddle Collision for right paddle
        if ((ball.xcor() >= 438 and ball.xcor()<=439) and (ball.ycor() <= rPaddle.ycor()+75 and ball.ycor() >= rPaddle.ycor()-75)):
            nColor = bounceX()
            rPaddle.color(prevColor)
            player2.undo()
            player2.color(prevColor)
            player2.write("{1}: {0}".format(player2_score, p2), font=("Arial", 20, "italic"))
            prevColor = nColor
            
            

        # Paddle Collision for left paddle
        if (ball.xcor() <= -438 and ball.xcor()>=-439) and (ball.ycor() <= lPaddle.ycor()+75 and ball.ycor() >= lPaddle.ycor()-75):
            nColor = bounceX()
            lPaddle.color(prevColor)
            player1.undo()
            player1.color(prevColor)
            player1.write("{1}: {0}".format(player1_score, p1), font=("Arial", 20, "italic"))
            prevColor = nColor                      



        # Ball Movement
        ################

        if ball.xcor() == 0 and ball.ycor() == 0:
            time.sleep(0.6)

        # Ball movement X-axis
        ball.setx(ball.xcor() + ballx)

        # Ball movement Y-axis
        ball.sety(ball.ycor() + bally)



    #########################
    # SCORE IN FILE
    #########################
    with open("scores.csv", "a+") as scores_write:

        write = csv.writer(scores_write)

        if player1_score > player2_score:
            score_lst = [p1, p2]
        else:
            score_lst = [p2, p1]        

        write.writerow(score_lst)


    # sreen termination
    #######################
    win.bye()
    tr.done()   



##############
# EXIT GAME
##############
def quitGame():
    exit()



#######################
# VIEW SCORES
#######################

def viewScores():
    scoreScreen = tk.Tk(className=" WINNER LIST")
    scoreScreen.configure(bg="grey")
    scoreScreen.geometry("800x500")
    scoreScreen.minsize(800, 500)
    scoreScreen.maxsize(800, 500)    

    with open("scores.csv", "r") as Scores_file:
        score_reader = csv.reader(Scores_file)

        score_lst=[]
        for elem in score_reader:
            score_lst.append(elem)

        if len(score_lst) != 0 :
            head_frame = tk.Frame(scoreScreen,bg="grey")
            head_frame.pack(side="top", anchor="w", pady=3)
            win_label_text = tk.Label(head_frame, text="WINNER", bg="grey", font=("courier", 15, "bold"))
            win_label_text.pack(side="left", padx=5)
            vs_label_text = tk.Label(head_frame, text="V/S", bg="grey", font=("courier", 15, "bold"))
            vs_label_text.pack(side="left",padx=100)
            lose_label_text = tk.Label(head_frame, text="LOSER", bg="grey", font=("courier", 15, "bold"))
            lose_label_text.pack(side="left")

            lim = 0
            for p_names in score_lst[::-1]:

                if len(p_names) != 0:                   
                    lim += 1
                    win = p_names[0]
                    lose = p_names[1]

                    if lim < 14: 
                        player_frame = tk.Frame(scoreScreen, bg="grey")
                        player_frame.pack(side="top", anchor="w", pady=1)
                        win_name = tk.Label(player_frame, text=win, bg="grey", font=("courier", 15))
                        win_name.pack(side="left", padx=5)
                        vs_name = tk.Label(player_frame, text="V/S", bg="grey", font=("courier", 15))
                        vs_name.pack(side="left",padx=100)
                        lose_name = tk.Label(player_frame, text=lose, bg="grey", font=("courier", 15))
                        lose_name.pack(side="left") 

                    else:
                        break
        else:
            no_score_text = tk.Label(scoreScreen, text="NOTHING TO SHOW!!!", font=("courier", 40, "bold italic"), fg="red", bg="grey")
            no_score_text.pack(pady=150)

    foot_scores = tk.Label(scoreScreen, text="Made By ~ Muteen, Aarush & Arjun", font=("Courier", 12 , "italic underline"), bg="grey")
    foot_scores.pack(side="bottom", anchor="e")

    scoreScreen.mainloop()




############################
# GUI MENUS FOR THE GAME
############################



#####################
# FULL NAME SCREEN
#####################

def names():

    # player name taker
    ###################

    def playerNames():
        player1_name = player1_Name.get()
        player2_name = player2_Name.get()
        name_screen.destroy()

        # calling main game
        #####################
        if len(player1_name) != 0 and len(player2_name) != 0:    
            game(player1_name, player2_name)
        elif len(player1_name) == 0 and len(player2_name) != 0:
            game(p2=player2_name)
        elif len(player2_name) == 0 and len(player1_name) != 0:
            game(p1=player1_name)
        elif len(player1_name) == 0 and len(player2_name) == 0:
            game()


    # screen destruction
    #######################
    global start_var

    if start_var == 0:
        start_var += 1
        start_screen.destroy()
    else:
        end_screen.destroy()



    ##################
    # Name Screen 
    ##################

    name_screen = tk.Tk()
    name_screen.title("Enter Names:")
    name_screen.configure(bg="grey")

    name_screen.geometry("800x500")
    name_screen.minsize(800, 500)
    name_screen.maxsize(800, 500)


    entry_text = tk.Label(text="Enter Names:", font=("Courier", 25), bg="grey")
    entry_text.pack(pady=50, padx=150)

    player1_var = tk.StringVar()
    player2_var = tk.StringVar()

    player_text1 = tk.Label(text="Enter player 1 name:", bg="grey", font=("Arial", 15, "italic"))
    player_text1.pack()

    player1_Name = tk.Entry(width=40, bd=6, relief="flat", textvariable=player1_var)
    player1_Name.pack(pady=10)


    player_text2 = tk.Label(text="Enter player 2 name:", bg="grey", font=("Arial", 15, "italic"))
    player_text2.pack()

    player2_Name = tk.Entry(width=40, bd=6, relief="flat", textvariable=player2_var)
    player2_Name.pack(pady=10)

    button_name = tk.Button(name_screen, text='Enter', width=10, height=1, bg='white', fg='#000000', activebackground='#66ff66', font=("arial", 12, "bold italic"), relief="flat", command=playerNames)
    button_name.pack(pady=7)

    foot_name = tk.Label(name_screen, text="Made By ~ Muteen, Aarush & Arjun", font=("Courier", 12 , "italic underline"), bg="grey")
    foot_name.pack(side="bottom", anchor="e")

    name_screen.mainloop()




###################
# START SCREEN
###################

start_screen = tk.Tk(className=" PONG MENU")
start_screen.configure(bg="grey")
start_screen.geometry("800x500")
start_screen.minsize(800, 500)
start_screen.maxsize(800, 500)

head_start = tk.Label(start_screen, text = "PONG MENU", bg="grey", pady=50) 
head_start.config(font =("Courier", 35)) 
head_start.pack()

button1_start = tk.Button(start_screen, text='Start Game', width=40, height=2, bg='white', fg='#000000', activebackground='#66ff66', font=("arial", 12, "bold italic"), command = names, relief="flat")
button1_start.pack()

button2_start = tk.Button(start_screen, text='Winner List', width=40, height=2, bg='white', fg='#000000', activebackground='#ff9933', font=("arial", 12, "bold italic"), command = viewScores, relief="flat")
button2_start.pack(pady=10)

button3_start = tk.Button(start_screen, text='Exit', width=40, height=2, bg='white', fg='#000000', activebackground='#ff355e', font=("arial", 12, "bold italic"), command = quitGame, relief="flat")
button3_start.pack()

foot_start = tk.Label(start_screen, text="Made By ~ Muteen, Aarush & Arjun", font=("Courier", 12 , "italic underline"), bg="grey")
foot_start.pack(side="bottom", anchor="e")

start_screen.mainloop()




##################
# END SCREEN
##################

while True:
    end_screen = tk.Tk()
    end_screen.title("GAME OVER!!!")
    end_screen.configure(bg="grey")
    end_screen.geometry("800x500")
    end_screen.minsize(800, 500)
    end_screen.maxsize(800, 500)

    head_end = tk.Label(end_screen, text = "GAME OVER", bg="grey", pady=50) 
    head_end.config(font =("Courier", 35)) 
    head_end.pack()

    button1_end = tk.Button(end_screen, text='Restart', width=40, height=2, bg='white', fg='#000000', activebackground='#66ff66', font=("arial", 12, "bold italic"), command = names, relief="flat")
    button1_end.pack()

    button2_end = tk.Button(end_screen, text='Winner List', width=40, height=2, bg='white', fg='#000000', activebackground='#ff9933', font=("arial", 12, "bold italic"), command = viewScores, relief="flat")
    button2_end.pack(pady=10)

    button3_end = tk.Button(end_screen, text='Exit', width=40, height=2, bg='white', fg='#000000', activebackground='#ff355e', font=("arial", 12, "bold italic"), command = quitGame, relief="flat")
    button3_end.pack()

    foot_end = tk.Label(end_screen, text="Made By ~ Muteen, Aarush & Arjun", font=("Courier", 12 , "italic underline"), bg="grey")
    foot_end.pack(side="bottom", anchor="e")

    end_screen.mainloop()
