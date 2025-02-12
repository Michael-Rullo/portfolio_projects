import requests
from datetime import datetime

class Holiday:
    
    def __init__(self, api_key):
        '''
        initializes the class
        args:       api_key     (str)   the api key for calendarific
        return:     (None)
        '''
        self.api_key = api_key
        self.year = datetime.now().year
    
    def get_holidays(self, day, month):
        '''
        gets the data on holidays
        args:       day     (str) the day of the month to get holidays on
                    month   (str) the month of the year to get holidays on
        return:     search  (json)the returned holiday data from the api request
        '''
        search = requests.get(f'https://calendarific.com/api/v2/holidays?&api_key={self.api_key}&country=US&year={self.year}&month={month}&day={day}')
        return search