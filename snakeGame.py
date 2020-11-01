# import pygame module in this program  
import pygame 
import enum
import time

class Direction(enum.Enum):
    up = 1
    down = 2
    left = 3
    right = 4
  
# activate the pygame library .   
# initiate pygame and give permission   
# to use pygame's functionality.   
pygame.init() 
  
# create the display surface object   
# of specific dimension..e(500, 500).   
win = pygame.display.set_mode((500, 500)) 
  
# set the pygame window name  
pygame.display.set_caption("Moving rectangle") 
  
# object current co-ordinates  
x = 200
y = 200
  
# dimensions of the object  
width = 20
height = 20

nowDirect = Direction.left
nextTime = 0
  
# velocity / speed of movement 
vel = 20
  
# Indicates pygame is running 
run = True


  
# infinite loop  
while run: 
    # creates time delay of 10ms  
      
    # iterate over the list of Event objects   
    # that was returned by pygame.event.get() method.   
    for event in pygame.event.get(): 
          
        # if event object type is QUIT   
        # then quitting the pygame   
        # and program both.   
        if event.type == pygame.QUIT: 
              
            # it will make exit the while loop  
            run = False

 # stores keys pressed  
    keys = pygame.key.get_pressed() 
    if keys[pygame.K_LEFT]: 
        nowDirect = Direction.left
    if keys[pygame.K_RIGHT]: 
        nowDirect = Direction.right
    if keys[pygame.K_DOWN]: 
        nowDirect = Direction.down
    if keys[pygame.K_UP]: 
        nowDirect = Direction.up


    currentTime = time.time()
    if currentTime >= nextTime:
        
        try:
            timeout = next(move())
        except StopIteration:
            # The drawing is finished, exit the main loop?
            break
        nextTime = currentTime + timeout
    
    
    def move():
        # if left arrow key is pressed 
            if nowDirect == Direction.left and x>0: 
                
                # decrement in x co-ordinate 
                x -= vel 
                
            # if left arrow key is pressed 
            if nowDirect == Direction.right and x<500-width: 
                
                # increment in x co-ordinate 
                x += vel 
                
            # if left arrow key is pressed    
            if nowDirect == Direction.up and y>0: 
                
                # decrement in y co-ordinate 
                y -= vel 
                
            # if left arrow key is pressed    
            if nowDirect == Direction.down and y<500-height: 
                # increment in y co-ordinate 
                y += vel 
                
    # completely fill the surface object   
    # with black colour   
    win.fill((0, 0, 0)) 
      
    # drawing object on screen which is rectangle here  
    pygame.draw.rect(win, (255, 0, 0), (x, y, width, height)) 
      
    # it refreshes the window 
    pygame.display.update()  
  
# closes the pygame window  
pygame.quit() 

#create by poomipat01


