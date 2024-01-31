import board
import audioio
import digitalio
import audiocore
from digitalio import DigitalInOut, Direction, Pull

import time

# Helpers

def load_file(path: str):
    data = open(path, "rb")
    wav = audiocore.WaveFile(data)

    return wav

# Global

led = digitalio.DigitalInOut(board.A2)
led.direction = digitalio.Direction.OUTPUT
led.value = True


a = audioio.AudioOut(board.A0)
wav1 = load_file("btn_weiss.wav")
wav2 = load_file("btn_gelb.wav")
wav3 = load_file("btn_rot.wav")
wav4 = load_file("btn_blau.wav")


button_white = DigitalInOut(board.D12)
button_white.direction = Direction.INPUT
button_white.pull = Pull.DOWN
button_white_state = button_white.value


button_yellow = DigitalInOut(board.D11)
button_yellow.direction = Direction.INPUT
button_yellow.pull = Pull.DOWN
button_yellow_state = button_yellow.value

button_red = DigitalInOut(board.D10)
button_red.direction = Direction.INPUT
button_red.pull = Pull.DOWN
button_red_state = button_red.value

button_blue = DigitalInOut(board.D9)
button_blue.direction = Direction.INPUT
button_blue.pull = Pull.DOWN
button_blue_state = button_blue.value


while True:
    # white button
    cur_state_btn_white = button_white.value
    if cur_state_btn_white != button_white_state:
        if cur_state_btn_white:
            a.play(wav1)

    # yellow button
    cur_state_btn_yellow = button_yellow.value
    if cur_state_btn_yellow != button_yellow_state:
        if cur_state_btn_yellow:
            a.play(wav2)

    # red button
    cur_state_btn_red = button_red.value
    if cur_state_btn_red != button_red_state:
        if cur_state_btn_red:
            a.play(wav3)

    # blue button
    cur_state_btn_blue = button_blue.value
    if cur_state_btn_blue != button_blue_state:
        if cur_state_btn_blue:
            a.play(wav4)