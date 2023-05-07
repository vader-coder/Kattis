import requests
#url = 'http://api.openweathermap.org/data/2.5/weather?q=London,uk&APPID=5426747c91d4cb03a9aaa8874058a78e'
#url = 'http://api.openweathermap.org/data/2.5/weather?q=Rapid City&APPID=5426747c91d4cb03a9aaa8874058a78e'
url = 'https://api.polygon.io/v1/last/stocks/AAPL?apiKey=NfTRcV1jofMTSSkp9dOZL6x1O1lj4Uvi'
res = requests.get(url)
data = res.json()
print(res)
print(data)