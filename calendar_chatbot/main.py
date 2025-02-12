from src.streamlit import Streamlit

def main():
    '''
    starts the program and starts the controller
    args:   (None) 
    return: (None) 
    '''
    
    handler = Streamlit()
    handler.streamloop()

main()