import streamlit as st
from src.chatbot import Api
from src.tts import Tts

class Controller:
    
    def __init__(self):
        
        self.api = None
        self.tts = Tts()
    
    def mainloop(self):
        
        st.title(":brain: :blue[FocusMD]")
        st.markdown(":rainbow[Yes, this name was ai generated]")
        st.divider()
        
        if "messages" not in st.session_state:
            st.session_state.messages = []
            
        if 'language' not in st.session_state:
            st.session_state.language = ''
        
        with st.sidebar:
            tts_switch = st.toggle('Text-to-Speech')
            openai_api_key = st.text_input("OpenAI API Key", key="chatbot_api_key", type="password")
            model = st.sidebar.selectbox(label='Model', options= ['gpt-4o-mini', 'gpt-4o', 'gpt-4-turbo', 'o1-preview'])
            language = st.sidebar.selectbox(label= 'Language', options= ['en', 'fr', 'es'])

        for message in st.session_state.messages:
            with st.chat_message(message["role"]): st.markdown(message["content"])

        user_input = st.chat_input("Ask Away (about adhd)")
        
        if len(openai_api_key) > 0:
            if model:
                api = Api(openai_api_key)
        
            if user_input:
            
                st.chat_message("user").markdown(user_input)
                st.session_state.messages.append(
                    {"role" : "user", "content" : user_input}
                )
                
                if tts_switch:
                    self.tts.texttospeech(st.session_state.messages)
                
                st.session_state.messages = api.chat(model, st.session_state.messages)
                
                if tts_switch:
                    self.tts.texttospeech(st.session_state.messages)
                
                st.chat_message("assistant").markdown(st.session_state.messages[-1]["content"])