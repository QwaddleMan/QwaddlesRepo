# John Conway's game of life
# Author: Jason Bowerman
# Python version: 3.7


import sys, pygame
import math
import random
from GOL import DOAManager, GAME_TYPE


pygame.init()

size = width, height = 1000, 1000
speed = [2, 2]
black = 0, 0, 0

screen = pygame.display.set_mode(size)
interval = 10
manager = DOAManager(interval,width, height, .04, GAME_TYPE.INPUT)
manager.define_grid()
count = 0
iterations = 3
while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit() 
    
    if(manager.get_gtype() == GAME_TYPE.INPUT):
        manager.manual_life()
    manager.play()
    screen.fill(black)
    manager.draw(screen)
    pygame.display.update()
    count+=1
