import streamlit as st
from src.holiday import Holiday
from src.openai import Openai
import json

class Streamlit:
    
    def __init__(self):
        '''
        initializes the streamlit api
        args:   (None) 
        return: (None) 
        '''
        pass
    
    def streamloop(self):
        '''
        handles the gui of the program and outsources responsibilities to other classes
        args:   (None) 
        return: (None) 
        '''
        
        st.title(":blue[HolidAI]")
        st.divider()
        
        if 'holiday' not in st.session_state:
            st.session_state['holiday'] = ''
        if 'messages' not in st.session_state:
            st.session_state['messages'] = []
        
        with st.sidebar:
            openai_api_key = st.text_input('Openai Api Key', key= 'openai_api_key', type= 'password')
            holiday_api_key = st.text_input("Calendarific API Key", key="holiday_api_key", type="password")
            st.divider()
            month = st.text_input('Enter a month 1-12')
            day = st.text_input('Enter a day 1-31')
        
        if len(holiday_api_key) > 0:
            holidai = Holiday(api_key= holiday_api_key)
            if day:
                if month:
                    results = holidai.get_holidays(day, month)
                    results_data = results.json()
                    results_data_parsed = results_data['response']['holidays']
                    st.session_state.messages.append({"role" : "user", "content" : f'Parse these results of holidays that fall on a specific day. For each holiday give me the name and description. Here are the results: {results_data_parsed}'})
        
        if len(openai_api_key):
            if day:
                if month:
                    chatbot = Openai(api_key= openai_api_key)
                    st.session_state.messages = chatbot.chat(st.session_state.messages)
        
        for message in st.session_state.messages:
            if not message["role"] == "system":
                if not message["role"] == "user":
                    with st.chat_message(message["role"]):
                        st.markdown(message["content"])