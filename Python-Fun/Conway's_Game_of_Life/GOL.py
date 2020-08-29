import pygame
import random
import math


#DEAD OR ALIVE class. This is for the cells of the game
class DOA:
    def __init__(self, x, y, size):
        self.x = x
        self.y = y
        self.size = size
        self.alive = False
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
    def __init__(self, interval, w,h, life_chance):
        self.w = w
        self.h = h
        self.life_chance = life_chance
        self.interval = interval
        self.num_doa_w = self.w//self.interval
        self.num_doa_h = self.h//self.interval
        self.rows = []

    def row(self, y):
        row = []
        for x in range(0,self.num_doa_w):
            var = random.random()
            r = DOA(x*self.interval, y, self.interval)
            if(var < self.life_chance):
                r.set_alive(True)
            row.append(r)
        self.rows.append(row)

    def define_grid(self):
        for y in range(0, self.num_doa_h):
            self.row(y*self.interval)

    # play the game
    def play(self):
        for y in range(0, self.num_doa_h):
            for x in range(0, self.num_doa_w):
                neighbors = self.get_neighbors(x,y)
                if(self.rows[y][x].get_alive() == True):
                    if(neighbors < 2):
                        self.rows[y][x].set_alive(False)
                    if(neighbors > 3):
                        self.rows[y][x].set_alive(False)
                else:
                    if(neighbors == 3):
                        self.rows[y][x].set_alive(True)


    def get_neighbors(self, x, y):
        ret = 0
        for x1 in range(x-2, x+2):
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
