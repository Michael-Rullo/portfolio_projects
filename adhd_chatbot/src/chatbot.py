from openai import OpenAI

class Api:
    
    def __init__(self, api_key):
        
        self.client = OpenAI(api_key= api_key)
        self.client.files.create(
        file=open("adhd_chatbot\src\ADHD_training_set", "rb"),
        purpose= "fine-tune"
        )
    
    def chat(self, gpt_model, messages):
        
        completion = self.client.chat.completions.create(
            model= gpt_model,
            messages= messages
        )
                
        messages.append(
                {"role" : "assistant", "content" : completion.choices[0].message.content}
            )
        
        return messages