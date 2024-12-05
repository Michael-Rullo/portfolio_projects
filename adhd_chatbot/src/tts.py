import pyttsx3

class Tts:
    
    def __init__(self):
        self.engine = pyttsx3.init()
        pass
    
    # def texttoaudio(self, messages, language):
    #     i = 1
    #     for phrase in messages[-2:]:
    #         audio = gTTS(phrase, lang= language, slow= False)
    #         audio.save(f'audio{i}')
    #         i += 1
    
    # def playaudio(self):
    #     for iterable in range(1, 3, 1):
    #         with open(f'audio{iterable}', 'rb') as f:
    #             data = f.read()
    #             b64 = base64.b64encode(data).decode()
    #             autoplay_audio("local_audio.mp3")
    
    def texttospeech(self, messages):
        phrase = messages[-1]["content"]
        self.engine.say(phrase)
        self.engine.runAndWait()