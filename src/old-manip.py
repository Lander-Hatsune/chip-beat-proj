# to TC_Demo v2.0
# lower-case command
import serial, time, sys
import serial.tools.list_ports
import pygame
from pygame.locals import *

'''
**Aurix Keymap**

*preset:
'w': motor forward
's': motor backward
'a': steer left
'd': steer right
'e': all clear

*adjusted set
'z': steer origin
'x': motor origin
'''

# basic parameters --begin
#1 about serial
port_name = 'COM7'
bps = 9600
waiting_time = 0.5
#2 about manip
frame_spd = 60
move_fwrd = K_w
move_back = K_s
steer_left = K_a
steer_right = K_d
#3 moving and turning constants
motor_thresh = 100
steer_thresh = 50
# basic parameters --end

# serial output
def Put(msg):
    try:
        ser.write(msg.encode('gbk'))
    except Exception as msg:
        print("output failed:", msg)
        #raise SystemExit(msg)

# steering and motoring of car
def Motion(key):
    if key == move_fwrd:
        print("forwarding")
        Put('w' * motor_thresh)
    elif key == move_back:
        print("backing")
        Put('s' * motor_thresh)
    elif key == steer_right:
        print("right steering")
        Put('d' * steer_thresh)
    elif key == steer_left:
        print("left steering")
        Put('a' * steer_thresh)

# reverse car to original state
def Restore(key):
    if key in (move_fwrd, move_back):
        print("stop motor")
        Put('x')
    elif key in (steer_left, steer_right):
        print("originate steer")
        Put('z')

    
def main():
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("car manip")
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((50, 50, 50))
    screen.blit(background, (0, 0))
    clock = pygame.time.Clock()
    while 1:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == QUIT:
                return
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE: return
                Motion(event.key)
            elif event.type == KEYUP:
                Restore(event.key)

        
        
if __name__ == '__main__':
    # open serial
    try:
        ser = serial.Serial(port_name, bps, timeout = waiting_time)
        if ser.is_open:
            print("info:", ser)
            
    except Exception as msg:
        print("cannot connect to serial:", port_name)
        #raise SystemExit(msg)
    
    main()
    
    try:
        ser.close()
    except:
        pass
