from io import BytesIO
from gtts import gTTS
import pygame
import time 

class Tts:
    
    def __init__(self):
        pygame.init()
        pygame.mixer.init()
    
    def wait(self):
        while pygame.mixer.get_busy():
            time.sleep(1)

    def texttospeech(self, messages, language = 'en'):
        phrase = messages[-1]["content"]
        mp3_fo = BytesIO()
        tts = gTTS(phrase, lang= language)
        tts.write_to_fp(mp3_fo)
        mp3_fo.seek(0)
        sound = pygame.mixer.Sound(mp3_fo)
        sound.play()
        while pygame.mixer.get_busy():
            time.sleep(1)