from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
from bs4 import BeautifulSoup as bs
from selenium.webdriver.chrome.options import Options
import re



chrome_options = Options()
chrome_options.add_argument("--headless")
chrome_options.add_argument("--window-size=1920x1080")

usr = 'kenjishimizu1717@gmail.com'
pwd = 'shimizu1902to2000'

#links
window1="https://www.facebook.com/"

#
bot_say = "[BOT] Hi there, This is an Automated message, " \
          "A Bot created by kenji to talk to useless humans. " \
          "Want to talk to him?\n" \
          "Contact Information: \n" \
          "Cell Num: 09175028874" \
#driver
#driver = webdriver.Chrome()
driver = webdriver.Chrome(options = chrome_options)
#window 1
driver.get(window1)
username_box = driver.find_element_by_id('email')
username_box.send_keys(usr)
print("email")
password_box = driver.find_element_by_id('pass')
password_box.send_keys(pwd)
print("password")
login_box = driver.find_element_by_id('loginbutton')
login_box.click()
print("login")
time.sleep(2)

"""
spans = soup.findAll('span')
for span in spans:
    print(span.text)
"""

while(1):
    # get the url
    url = driver.page_source
    time.sleep(1)
    # parse html to get data
    soup = bs(url, features='html.parser')
    # loop to find the class
    spans=[spans for active_chat in soup.findAll("div", {"class":"oajrlxb2 gs1a9yip g5ia77u1 mtkw9kbi tlpljxtp "
                                                    "qensuy8j ppp5ayq2 goun2846 ccm00jje s44p3ltw "
                                                    "mk2mc5f4 rt8b4zig n8ej3o3l agehan2d sk4xxmp2 "
                                                    "rq0escxv nhd2j8a9 q9uorilb mg4g778l btwxx1t3 "
                                                    "pfnyh3mw p7hjln8o kvgmc6g5 cxmmr5t8 oygrvhab "
                                                    "hcukyx3x tgvbjcpo hpfvmrgz jb3vyjys rz4wbd8a "
                                                    "qt6c0cv9 a8nywdso l9j0dhe7 i1ao9s8h esuyzwwr "
                                                    "f1sip0of du4w35lb lzcic4wl abiwlrkh p8dawk7l "
                                                    "s45kfl79 emlxlaya bkmhp75w spb7xbtv m7zwrmfr tmrshh9y",
                                            "role":"button"})
        for spans in active_chat("span",{"class":"bp9cbjyn ljqsnud1 pq6dq46d datstx6m taijpn5t "
                                                         "jb3vyjys jxrgncrl qt6c0cv9 qnrpqo6b k4urcfbm"})]
    active_element = 0
    for span in spans:
        digit = [float(s) for s in re.findall(r'-?\d+\.?\d*', span.text)]

        for i in digit:
            active_element = i;
        time.sleep(0.50)
        if active_element > 0:
            text_box = driver.find_element_by_xpath('//*[@id="mount_0_0"]/div/div/div[4]/div[1]/div[1]/div[1]/div/div/div[1]/div/div/div/div[2]/div/div[2]/form/div/div[4]/div[2]/div[1]/div/div/div/div/div[2]/div/div/div/div')
            text_box.click()
            text_box.send_keys(bot_say,Keys.ENTER)
            close_box = driver.find_element_by_xpath('//*[@id="mount_0_0"]/div/div/div[4]/div[1]/div[1]/div[1]/div/div/div[1]/div/div/div/div[1]/div/div[3]/span[4]/div')
            close_box.click()
            print("Messages Left:", active_element)


    if soup.findAll("div", {"class":"oajrlxb2 tdjehn4e qu0x051f esr5mh6w e9989ue4 r7d6kgcz rq0escxv nhd2j8a9 j83agx80 p7hjln8o kvgmc6g5 cxmmr5t8 oygrvhab hcukyx3x jb3vyjys rz4wbd8a qt6c0cv9 a8nywdso i1ao9s8h esuyzwwr f1sip0of lzcic4wl l9j0dhe7 abiwlrkh p8dawk7l bp9cbjyn s45kfl79 emlxlaya bkmhp75w spb7xbtv rt8b4zig n8ej3o3l agehan2d sk4xxmp2 taijpn5t tv7at329 thwo4zme",
                                            "role":"button"}):
        close_call = driver.find_element_by_xpath('//*[@id="facebook"]/body/div[10]/div[1]/div/div[2]/div/div/div/div[1]/div')
        close_call.click()
    else:
        pass











