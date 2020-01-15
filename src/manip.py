# for TC_Sv1.0: uppercase command
# ordinary remote control toy car
import serial, time, sys
import serial.tools.list_ports
import pygame
from pygame.locals import *

'''
**Aurix Keymap**

*preset:
'W': motor forward
'S': motor backward
'A': steer left
'D': steer right
'E': all clear

*adjusted set
'Z': steer origin
'X': motor origin
'''

# basic parameters --begin
#1 about serial
_port_name = 'COM7'
_bps = 9600
_time_out = 0.5
_write_time_out = 0.5
_parity = serial.PARITY_NONE
_stopbits = 1
_bytesize = 8
#2 about manip
_frame_spd = 100
_move_fwrd = K_w
_move_back = K_s
_steer_left = K_a
_steer_right = K_d
#3 moving and turning constants
_motor_thresh = 100
_steer_thresh = 50
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
    if key == _move_fwrd:
        print("forwarding")
        Put('S' * _motor_thresh)
    elif key == _move_back:
        print("backing")
        Put('W' * _motor_thresh)
    elif key == _steer_right:
        print("right steering")
        Put('D' * _steer_thresh)
    elif key == _steer_left:
        print("left steering")
        Put('A' * _steer_thresh)

# reverse car to original state
def Restore(key, a_key, d_key):
    if key in (_move_fwrd, _move_back):
        print("stop motor")
        Put('X')
    elif key == _steer_left:
        if not d_key:
            print("originate from left")
            Put('Z')
        else: print("ignored originate from left")
    elif key == _steer_right:
        if not a_key:
            print("originate from right")
            Put('Z')
        else: print("ignored originate from right")

    
def main():
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("car manual manip")
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((50, 50, 50))
    screen.blit(background, (0, 0))
    clock = pygame.time.Clock()
    while 1:
        clock.tick(_frame_spd)
        
        # cover released keys' call to 'Restore()' func,
        # if the opposite key has been pushed
        keylist = pygame.key.get_pressed()
        a_key = keylist[K_a]
        d_key = keylist[K_d]
        
        for event in pygame.event.get():
            if event.type == QUIT:
                return
            elif event.type == KEYDOWN:
                if event.key == K_ESCAPE: return
                Motion(event.key)
            elif event.type == KEYUP:
                Restore(event.key, a_key, d_key)

        
        
if __name__ == '__main__':
    # open serial
    try:
        ser = serial.Serial(_port_name, _bps,
                            timeout = _time_out)
        if ser.is_open:
            print("info:", ser)
            ser.bytesize = _bytesize
            ser.parity = _parity
            ser.stopbits = _stopbits
            
            
    except Exception as msg:
        print("cannot connect to serial:", _port_name)
        #raise SystemExit(msg)
    
    main()
    
    try:
        ser.close()
    except:
        pass
