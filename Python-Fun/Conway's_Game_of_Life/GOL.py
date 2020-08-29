import pygame
import random
import math
from enum import Enum

class GAME_TYPE(Enum):
    INPUT = 1
    RANDOM = 2

#DEAD OR ALIVE class. This is for the cells of the game
class DOA:
    def __init__(self, x, y, size):
        self.x = x
        self.y = y
        self.size = size
        self.alive = False
        self.neighbors = 0
        self.rect = pygame.Rect(self.x, self.y, self.size,self.size)
 #   @property
    def get_alive(self):
        return self.alive

#    @alive.setter
    def set_alive(self, status):
        self.alive = status

    def draw(self, screen):
        if(self.alive == True):
            pygame.draw.rect(screen, (255,0,0), self.rect, 0)
        else:
            pygame.draw.rect(screen, (255,0,0), self.rect, -1)
            
#manages the grid of cells
class DOAManager:
    def __init__(self, interval, w,h, life_chance = .05, gtype=GAME_TYPE.RANDOM):
        self.w = w
        self.h = h
        self.life_chance = life_chance
        self.interval = interval
        self.num_doa_w = self.w//self.interval
        self.num_doa_h = self.h//self.interval
        self.rows = []
        self.inplay = False
        self.gtype = gtype

    def row(self, y):
        row = []
        for x in range(0,self.num_doa_w):
            r = DOA(x*self.interval, y, self.interval)
            row.append(r)
        self.rows.append(row)

    # sets random life
    def random_life(self):
        for y in rows:
            for x in y:
                ran = random.random()
                if(ran < self.life_chance):
                    x.set_alive(True)

    def get_gtype(self):
        return self.gtype

    @property
    def playing(self):
        return self.isplay

    @playing.setter
    def playing(self, val):
        self.isplay = val

    def block_clicked(self):
        mpress = pygame.mouse.get_pressed()
        for r in self.rows:
            for b in r:
                m_loc = pygame.mouse.get_pos()
                print(str(m_loc[0]) + " " + str(m_loc[1]))
                if(m_loc[0] >= b.x and m_loc[0] <= b.x + b.size and m_loc[1] >= b.y and m_loc[1] <= b.y + b.size):
                    if(mpress[0]):
                        b.set_alive(True)
                    if(mpress[2]):
                        b.set_alive(False)

    #manually input living blocks
    def manual_life(self):
        if self.inplay != True:
            pressed = pygame.key.get_pressed()
            if(pressed[pygame.K_RETURN]):
                self.inplay = True
            self.block_clicked()
            print("press enter") 

    #morning programming is obviously not my jam
    def define_grid(self):
        for y in range(0, self.num_doa_h):
            self.row(y*self.interval)
            if(self.gtype == GAME_TYPE.RANDOM):
                self.random_life()
                self.play = True


    # play the game
    def play(self):
        if(self.inplay == True):
            print("playing")
            #get all neighbors
            for y in range(0, self.num_doa_h):
                for x in range(0, self.num_doa_w):
                    self.rows[y][x].neighbors = self.get_neighbors(x,y)
            #preform changes
            for y in range(0, self.num_doa_h):
                for x in range(0, self.num_doa_w):
                    if(self.rows[y][x].get_alive() == True):
                        if(self.rows[y][x].neighbors < 2 or self.rows[y][x].neighbors > 3):
                            self.rows[y][x].set_alive(False)
                    else:
                        if(self.rows[y][x].neighbors == 3):
                            self.rows[y][x].set_alive(True)
           # pygame.time.wait(4000)


    def get_neighbors(self, x, y):
        ret = 0
        for x1 in range(x-1, x+2):
            if(x1 >= 0 and x1 < len(self.rows[0]) and y-1 >=0 and y+1 < len(self.rows)):
                    if(self.rows[y-1][x1].get_alive() == True):
                        ret+=1
                    if(self.rows[y+1][x1].get_alive() == True):
                        ret+=1

        if(x-1 >= 0 and x+1 < len(self.rows[0])):
            if(self.rows[y][x-1].get_alive() == True):
                ret+=1
            if(self.rows[y][x+1].get_alive() == True):
                ret+=1
        return ret
    
    def draw(self, screen):
        for y in self.rows:
            for x in y:
                x.draw(screen)
