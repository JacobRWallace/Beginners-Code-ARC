import requests
import time

payload = {
    'content': ""
}

header = {
    'Authorization': "YOUR_TOKEN"  
}

payload['content'] = input("Message: ")
cnt = int(input("Count: "))
rte = float(input("Rate (s): "))

for i in range(cnt):
    r = requests.post('https://discord.com/api/v9/channels/1101345798282821654/messages', data=payload, headers=header)
    if r.status_code == 429:
        print("Rate limited, waiting...")
        time.sleep(1)
    else:
        print("Message sent successfully!")

    time.sleep(rte)