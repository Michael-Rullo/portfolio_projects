from openai import OpenAI

class Openai:
    
    def __init__(self, api_key):
        '''
        initializes the openai api
        args:       api_key     (str)   an openai api key
        return:     messages    (dict)  dictionary of conversation history
        '''
        self.client = OpenAI(api_key= api_key)
    
    def chat(self, messages):
        '''
        uses the chat history to have a gpt-4o-mini parse the data and format it
        args:       messages    (dict)      dictionary of conversation history
        return:     messages    (dict)      updated conversation dictionary
        '''
        completion = self.client.chat.completions.create(
            model= 'gpt-4o-mini',
            messages= messages
        )
                
        messages.append(
                {"role" : "assistant", "content" : completion.choices[0].message.content}
            )
        
        return messages