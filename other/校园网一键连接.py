import requests
from datetime import datetime
if __name__ == '__main__':
    url="http://172.16.200.11/"

    data={
        "DDDDD":"2024212430",
        "upass":"164935",
        "0MKKey":"123"
    }
    header={
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
        "Accept-Encoding": "gzip, deflate",
        "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
        "Cache-Control": "max-age=0",
        "Connection": "keep-alive",
        "Content-Length": "40",
        "Content-Type": "application/x-www-form-urlencoded",
        "Cookie":"myusername=2024212430",
        "Host": "172.16.200.11",
        "Origin": "http://172.16.200.11",
        "Referer": "http://172.16.200.11/",
       " Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
    }

    response = requests.post(url,data=data,headers=header).status_code